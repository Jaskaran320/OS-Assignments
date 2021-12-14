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
struct message {
    char arr1[6];
    int arr2[6];
}msg;
void rand_str(char *a, size_t l) {
    char b[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    while (l-- > 0) {
        srand(time(0) + rand());
        size_t index = (double) rand() / RAND_MAX * (sizeof b - 1);
        *a++ = b[index];
    }
    *a = '\0';
}
int main() {
    struct sockaddr_un cliaddr;
    int x;
    char arr[50];
    for (int i = 0; i < 50; i++){
        rand_str(&arr[i], 1);
    }
    int len = sizeof(cliaddr);
    int sockfd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    memset(&cliaddr, 0, len);
    cliaddr.sun_family = AF_UNIX;
    strncpy(cliaddr.sun_path, socket_path, sizeof(cliaddr.sun_path)-1); 
    int c = connect(sockfd, (struct sockaddr *)&cliaddr, sizeof(cliaddr));
    if (c < 0) {
        perror("connect");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < 10; i++) {
        char arr3[6] = {arr[5*i], arr[5*i+1], arr[5*i+2], arr[5*i+3], arr[5*i+4], '\0'}; 
        int arr4[6] = {5*i, 5*i+1, 5*i+2, 5*i+3, 5*i+4, '\0'};
        memcpy(msg.arr1, arr3, sizeof(arr3));
        memcpy(msg.arr2, arr4, sizeof(arr4));
        send(sockfd, &msg, sizeof(msg), 0);
        recv(sockfd, &x, sizeof(x), 0);
        for (int j = 0; j < 10; j++) {
            printf("%d\n", 5*j+4);
        }
    }
    close(sockfd);
    return 0;
}