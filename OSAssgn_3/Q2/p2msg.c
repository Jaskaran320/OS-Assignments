#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/msg.h>
struct message {
    char arr1[6];
    int arr2[6];
}msg;
int main() {
    key_t key;
    int msgid;
    key = ftok("Makefile", 65);
    for (int i = 0; i < 10; i++) {
        if ((msgid = msgget(key, 0666 | IPC_CREAT)) < 0) {
            perror("msgget");
            exit(1);
        }
        msgrcv(msgid, &msg, sizeof(msg), 0, 0);
        for(int j = 0; j < 5; j++){
            printf("%c ", msg.arr1[j]);
        }
        printf("\n");
        int x = msg.arr2[4];
        if(msgsnd(msgid, &x, sizeof(x), 0) < 0) {
            perror("msgsnd");
            exit(1);
        }
    }
    msgctl(msgid, IPC_RMID, NULL);
    return 0;
}