#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
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
    int fd, x;
    char arr[50];
    for (int i = 0; i < 50; i++){
        rand_str(&arr[i], 1);
    }
    char *fifo = "/tmp/fifo";
    mkfifo(fifo, 0666);
    for(int i = 0; i < 10; i++){
        fd = open(fifo, O_WRONLY);
        char arr3[6] = {arr[5*i], arr[5*i+1], arr[5*i+2], arr[5*i+3], arr[5*i+4], '\0'}; 
        int arr4[6] = {5*i, 5*i+1, 5*i+2, 5*i+3, 5*i+4, '\0'};
        memcpy(msg.arr1, arr3, sizeof(arr3));
        memcpy(msg.arr2, arr4, sizeof(arr4));
        write(fd, &msg, sizeof(msg));
        close(fd);
        fd = open(fifo, O_RDONLY);
        read(fd, &x, sizeof(x));
        printf("%d\n", x);
        close(fd);
    }
    return 0;
}