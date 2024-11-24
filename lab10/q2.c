//2. Write a recursive function that takes a string as input and returns the reversed string.
#include <stdio.h>
#include <string.h>

void reverse_string(char str[], int i,int j)
{
    char temp;
    if(j >= i)
        return;
    else  
    temp = str[j];
    str[j] = str[i];
    str[i] = temp;
 //   printf("i = %d\nj = %d\ntemp = %c \n ",i,j,reversed[j]);
    reverse_string(str,i-1,j+1);

}
int main()
{
    char str[100];
    printf("ENTER STRING : ");
    gets(str);
    reverse_string(str, strlen(str)-1,0);
    printf("%s",str);

}