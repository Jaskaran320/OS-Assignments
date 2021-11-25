#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<signal.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>
void handler(int signum, siginfo_t *info, void *context) {
    printf("Inside signal handler\n"); 
    int x = info->si_value.sival_int;
    printf("Value: %d\n", x);
}
int main() {
    pid_t pid, pid1;
    int status;
    pid = fork();
    char* str1 = malloc(sizeof(pid)), *str2 = malloc(sizeof(pid));
    sprintf(str1, "%d", pid);
    char* args1[] = {"./E1", str1, NULL};
    sprintf(str2, "%d", pid);
    char* args2[] = {"./E2", str2, NULL};
    if (pid < 0) {
        perror("Fork error");
    }
    else if (pid == 0) {
        struct sigaction action;
        action.sa_flags = SA_SIGINFO;
        action.sa_sigaction = &handler;
        sigaction(SIGTERM, &action, NULL);
        while(1);
    }
    else {
        pid1 = fork();
        if (pid1 < 0) {
            perror("Fork error");
        }
        else if (pid1 == 0) {
            execvp("./E1", args1);
        }
        else {
            execvp("./E2", args2);
        }
    }
    return 0;
}