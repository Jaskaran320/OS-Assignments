#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE *fileptr1,*fileptr2;
    char a[100];
    fileptr1=fopen("1.txt","r");
    fileptr2=fopen("2.txt","w");
    while(fread(&a,1,1,fileptr1))
        fwrite(&a,1,1,fileptr2);
    fclose(fileptr1);
    fclose(fileptr2);
    return 0;
}