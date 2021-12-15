#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <time.h>
#include <sys/types.h>
#include <sys/msg.h>
struct message {
    char arr1[6][2];
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
    key_t key;
    int msgid, x;
    char arr[50][2];
    for (int i = 0; i < 50; i++){
        rand_str(&arr[i][0], 1);
        rand_str(&arr[i][1], 1);
    }
    key = ftok("Makefile", 65);
    for (int i = 0; i < 10; i++) {
        if ((msgid = msgget(key, 0666 | IPC_CREAT)) < 0) {
            perror("msgget");
            exit(1);
        }
        char arr3[6][2] = {{arr[5*i][0], arr[5*i][1]}, {arr[5*i+1][0], arr[5*i+1][1]}, {arr[5*i+2][0], arr[5*i+2][1]}, {arr[5*i+3][0], arr[5*i+3][1]}, {arr[5*i+4][0], arr[5*i+4][1]}, {'\0', '\0'}};
        int arr4[6] = {5*i, 5*i+1, 5*i+2, 5*i+3, 5*i+4, '\0'};
        memcpy(msg.arr1, arr3, sizeof(arr3));
        memcpy(msg.arr2, arr4, sizeof(arr4));
        if(msgsnd(msgid, &msg, sizeof(msg), 0) < 0){
            perror("msgsnd");
            exit(1);
        }
        if(msgrcv(msgid, &x, sizeof(x), 0, 0) < 0){
            perror("msgrcv");
            exit(1);
        }
        printf("%d\n", x);
    }
    msgctl(msgid, IPC_RMID, NULL);
    return 0;
}