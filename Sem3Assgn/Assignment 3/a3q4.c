#include<stdio.h>
#include<stdbool.h>
void selection(int a[], int n){
    int i, j, min;
    for(i = 0; i < n-1; i++){
        min = i;
        for (j = i+1; j < n; j++)
            if (a[j] < a[min])
                min = j; 
        int temp = *&a[min];
        *&a[min] = *&a[i];
        *&a[i] = temp;
    }
}
void bubble(int a[], int n){
   int i, j;
   bool swapped;
   for(i = 0; i < n-1; i++){
        swapped = false;
        for(j = 0; j < n-i-1; j++){
            if(a[j] > a[j+1]){
                int temp = *&a[j];
                *&a[j] = *&a[j+1];
                *&a[j+1] = temp;
                swapped = true;
            }
        }
        if(swapped == false)
            break;
   }
}
int main(){
    int n,x;
    printf("Enter number of elemnents: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter elements of array:\n");
    for(int i = 0; i < n; i++)
        scanf("%u", &a[i]);
    printf("Press 1 to use selection sort\nPress 2 to use bubble sort\n");
    scanf("%d", &x);
    if(x == 1){
        selection(a, n);
        for(int i = 0; i < n; i++)
        printf("%d ", a[i]);
    }
    else if(x ==2){
        bubble(a, n);
        for(int i = 0; i < n; i++)
        printf("%d ", a[i]);
    }
    else    
        printf("Invalid input\n");
}