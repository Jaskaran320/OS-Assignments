#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
int random(){
    int x = rand();
    x = x % 10;
    if(x == 0)
        return 10;
    else
        return x;
}
void print(int** matrix, int* column){
    for(int i = 0; i < 6; i++){
        for (int j = 0; j < column[i]; j++)
            printf("%d ", matrix[i][j]);        
        printf("\n");
    }
}
int main(){
    srand(time(0));
    int** matrix = (int**)malloc(6 * sizeof(int*));
    matrix[0] = (int *)malloc(7 * sizeof(int*));
    matrix[1] = (int *)malloc(4 * sizeof(int*));
    matrix[2] = (int *)malloc(6 * sizeof(int*));
    matrix[3] = (int *)malloc(3 * sizeof(int*));
    matrix[4] = (int *)malloc(7 * sizeof(int*));
    matrix[5] = (int *)malloc(2 * sizeof(int*));
    int column[6] = {7, 4, 6, 3, 7, 2};
    for (int i = 0; i < 6; i++){
        for (int j = 0; j < column[i]; j++)
        {
            matrix[i][j] = random();
        }        
    }
    print(matrix, column);
    while(true){
        int x;
        printf("Press 1 to change, Press 2 to print matrix, Press 0 to exit\n");
        scanf("%d", &x);
        if(x == 1){
            int row, col;
            printf("Enter index of row you want to change: ");
            scanf("%d", &row);
            row--;
            printf("Enter the new number of columns in this row, currently it has %d columns: ", column[row]);
            scanf("%d",&col);
            column[row] = col;
            matrix[row] = (int *)realloc(matrix[row],col * sizeof(int *));
            for(int i = 0; i < column[row]; i++)
                matrix[row][i] = random();
        }
        else if(x == 2)
            print(matrix, column);
        else if(x == 0)
            break;
        else
            printf("Invalid Input\n");
    }
    return 0;
}