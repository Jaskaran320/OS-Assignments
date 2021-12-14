#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include<sys/socket.h>
#include<sys/un.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#define socket_path "./socket"
void rand_str(char *a, size_t l) {
    char b[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    while (l-- > 0) {
        srand(time(0) + rand());
        size_t index = (double) rand() / RAND_MAX * (sizeof b - 1);
        *a++ = b[index];
    }
    *a = '\0';
}
struct message {
    char arr1[6];
    int arr2[6];
}msg;
int main() {
    int x, connfd, k = 0;
    char arr[50];
    for (int i = 0; i < 50; i++){
        rand_str(&arr[i], 1);
    }
    struct sockaddr_un servaddr;
    int len = sizeof(struct sockaddr_un);
    int sockfd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    memset(&servaddr, 0, sizeof(struct sockaddr_un));
    servaddr.sun_family = AF_UNIX;
    strncpy(servaddr.sun_path, socket_path, sizeof(servaddr.sun_path)-1); 
    unlink(socket_path);
    if(bind(sockfd,(struct sockaddr *)&servaddr, len) < 0) {
        perror("bind");
        exit(EXIT_FAILURE);
    }
    if(listen(sockfd, 5) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    while(1) {
        if(connfd = accept(sockfd, (struct sockaddr *)&servaddr, (socklen_t *)&len) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        for (int i = 0; i < 10; i++) {
            char arr1[6] = {arr[5*i], arr[5*i+1], arr[5*i+2], arr[5*i+3], arr[5*i+4], '\0'}; 
            recv(connfd, &msg, sizeof(msg), 0);
            for(int j = 0; j < 5; j++){
                printf("%c ", arr1[j]);
            }
            printf("\n");
            int x = msg.arr2[4];
            send(connfd, &x, sizeof(x), 0);
            k++;
        }
        if (k == 10){
            close(sockfd);
            exit(EXIT_SUCCESS);
        }
    }
    return 0;
}