#include <stdio.h>
#include <stdlib.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <linux/sched.h>
#include <linux/syscalls.h>
#include <linux/module.h>
#define vruntime_change 448
int main() {
    long x = scanf("Enter time: %ld", &x);
    int res = syscall(vruntime_change, x, 0);
    printf("System call returned %d.\n", res);
    return 0;
}