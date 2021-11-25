#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<sys/time.h>
#include<signal.h>
#include<errno.h>
#include<string.h>
#include <stdint.h>
int x;
int rdrand (){
    int a;
    __asm__ volatile ("rdrand %0" :"=r" (a)::);
    return a;
}
void handler1(int signum){
    union sigval k;
    k.sival_int = rdrand();
    printf("%d\n", k.sival_int);
    sigqueue (x, SIGTERM, k);
}
int main(int argc, char* argv[]) {
    int x = atoi(argv[1]);
    signal(SIGALRM, handler1);
    struct itimerval ti;
    ti.it_value.tv_sec = 1;
    ti.it_value.tv_usec = 0;
    ti.it_interval.tv_sec = 1;
    ti.it_interval.tv_usec = 0;
    int t = setitimer(ITIMER_REAL, &ti, NULL);
    if (t == -1) {
        perror("Setitimer error");
        exit(1);
    }
    while(1){
        pause();
    }
    return 0;
}