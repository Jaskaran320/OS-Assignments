#include<stdio.h>
int main()
{
   int n = 0;
   char str[10000], temp;
   printf("Enter string: ");
   gets(str);
   for(int i = 0; str[i] != '\0'; i++)
      n++;
   for(int i = 0; i < n/2; i++){
      temp = str[i];
      str[i] = str[n-i-1];
      str[n-i-1] = temp;
   }
   printf("Reversed String: %s", str);
}