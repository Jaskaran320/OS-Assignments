#include<stdio.h>
int main(){
    int a[10000],b[10000], i, n, c, d;
    printf("Enter 2 elements to be swapped: ");
    scanf("%d %d",&c ,&d);
    c=c+d;
    d=c-d;
    c=c-d;
    printf("Swapped elements are: %d, %d",c, d);
    printf("Enter size of arrays: ");
    scanf("%d",&n);
    printf("Enter elements of array 1:\n");
    for(i=0;i<n;i++)
        scanf("%d", &a[i]);
    printf("Enter elements of array 2:\n");
    for(i=0;i<n;i++)
        scanf("%d", &b[i]);
    for(i=0;i<n;i++){
        a[i]=a[i]+b[i];
        b[i]=a[i]-b[i];
        a[i]=a[i]-b[i];
    }
    printf("Elements of array 1:\n");
    for(i=0;i<n;i++)
        printf("%d ", a[i]);
    printf("\nElements of array 2:\n");
    for(i=0;i<n;i++)
        printf("%d ", b[i]);
}
