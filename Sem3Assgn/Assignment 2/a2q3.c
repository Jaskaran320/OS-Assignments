#include<stdio.h>
#include<math.h>
int add(int a, int b){
    return a+b;
}
int sub(int a, int b){
    return a-b;
}
int mul(int a, int b){
    return a*b;
}
int div(int a, int b){
    return a/b;
}
int Exp(int a, int b){
    return pow(a,b);
}
int main(){
    int x, y;
    void *a[5] = {&add, &sub, &mul, &div, &Exp};
    printf("Enter 2 integers: ");
    scanf("%d %d", &x, &y);
    char b[5][15] = {"Sum: ", "Difference: ", "Product: ", "Quotient: ", "Exponential: "};
    for(int i = 0; i <5; i++)
        printf("%s%d\n",b[i],((int (*)(int, int))(a[i]))(x, y));
    return 0;
}