#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
struct message {
    char arr1[6][2];
    int arr2[6];
}msg;
int main() {
    int fd;
    char *fifo = "/tmp/fifo";
    for(int i = 0; i < 10; i++){
        fd = open(fifo, O_RDONLY);
        if(read(fd, &msg, sizeof(msg)) < 0){
            perror("read");
            exit(1);
        }
        int x = msg.arr2[4];
        for(int j = 0; j < 5; j++){
            printf("%c%c ", msg.arr1[j][0], msg.arr1[j][1]);
        }
        printf("\n");
        close(fd);
        fd = open(fifo, O_WRONLY);
        if(write(fd, &x, sizeof(x)) < 0){
            perror("write");
            exit(1);
        }
        close(fd);
    }
    return 0;
}