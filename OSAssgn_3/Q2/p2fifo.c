#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
struct message {
    char arr1[6];
    int arr2[6];
}msg;
int main() {
    int fd;
    char *fifo = "/tmp/fifo";
    for(int i = 0; i < 10; i++){
        fd = open(fifo, O_RDONLY);
        read(fd, &msg, sizeof(msg));
        int x = msg.arr2[4];
        for(int j = 0; j < 5; j++){
            printf("%c ", msg.arr1[j]);
        }
        printf("\n");
        close(fd);
        fd = open(fifo, O_WRONLY);
        write(fd, &x, sizeof(x));
        close(fd);
    }
    return 0;
}