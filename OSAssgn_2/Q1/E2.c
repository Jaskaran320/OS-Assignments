#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<sys/time.h>
#include<signal.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>
int x;
unsigned long long rdtsc()
{
    int a;
    int b;
    __asm__ __volatile__ ("RDTSC\n\t"
            "mov %%edx, %0\n\t"
            "mov %%eax, %1\n\t": "=r" (a), "=r" (b)::
            "%rax", "rbx", "rcx", "rdx");    
    unsigned long long c= (((unsigned long long) a << 32| b)) ;
    return (c/(4150000000));
}
void handler2(int signum){
    union sigval k;
    k.sival_int = rdtsc();
    printf("%llu\n", k.sival_int);
    sigqueue (x, SIGTERM, k);
}
int main(int argc, char *argv[]){
    int x = atoi(argv[1]);
    signal(SIGALRM, handler2);
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