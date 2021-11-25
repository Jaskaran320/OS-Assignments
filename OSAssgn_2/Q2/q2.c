#define _GNU_SOURCE
#include <unistd.h>
#include <sys/syscall.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#define kernel_2d_memcpy 448
int main(){
    float arr[3][3] = {{7.0,14.0,21.0},{28.0,35.0,42.0},{49.0,56.0,63.0}};
    float arr1[3][3];
    printf("Making system call\n");
    long res = syscall(kernel_2d_memcpy, arr, arr1);
    if (res < 0)
        perror("syscall");
    printf("System call returned %ld.\n", res);
    int i = 0, j = 0;
    while(i < 3){
        while(j < 3){
            printf("%f ", arr1[i][j]);
            j++;
        }
        printf("\n");
        j = 0;
        i++;
    }
    return 0;
}