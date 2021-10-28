#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
void a(){
    printf("in a()\n");
    printf("Enter integer: ");
    long long int x;
    scanf("%lld", &x);
    printf("%lld\n", x);
    extern void b(long long int x);
    b(x);
}
int main(int argc, char **argv){
    printf("in main of a\n");
    a();
    return(0);
}