#include<stdio.h>
#include<stdlib.h>
void selection(unsigned int a[], int n){
    int i, j, min;
    for(i = 0; i < n-1; i++){
        min = i;
        for (j = i+1; j < n; j++)
            if (a[j] < a[min])
                min = j; 
        unsigned int temp = *&a[min];
        *&a[min] = *&a[i];
        *&a[i] = temp;
    }
}
int bin(unsigned int a[], int l, int h, unsigned int x){
    if(h >= l){
        int mid = l + (h - l) / 2;
        if (a[mid] == x)
            return mid;
        if (a[mid] > x)
            return bin(a, l, mid - 1, x);
        return bin(a, mid + 1, h, x);
    }
    return -1;
}
int main(){
    int n;
    unsigned int x;
    printf("Enter number of elemnents: ");
    scanf("%d", &n);
    unsigned int a[n];
    printf("Enter elements of array:\n");
    for(int i = 0; i < n; i++)
        scanf("%u", &a[i]);
    selection(a, n);
    printf("Enter element to be searched: ");
    scanf("%u", &x);
    int result = bin(a, 0, n - 1, x);
    if(result == -1)
        printf("Element is not in array");
    else
        printf("Element is at index %d", result);
    return 0;
}