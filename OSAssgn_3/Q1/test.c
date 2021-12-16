#include <stdio.h>
#include <stdlib.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <linux/sched.h>
#include <linux/syscalls.h>
#include <linux/module.h>
#define Vruntime_change 449
int main() {
    unsigned long long int x = scanf("Enter time in nanoseconds: %llu", &x);
    if (x < 0) {
        printf("Invalid time\n");
    }
    else {
        int pid = fork();
        int res = syscall(Vruntime_change, pid, x);
        printf("System call returned %d.\n", res);
    }
    return 0;
}