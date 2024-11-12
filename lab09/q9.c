#include<stdio.h>
#include<string.h>
void reversed(char arr[],char reverse[])
{
    int i,j;
    for(i = 0,j = strlen(arr)-1 ; i < strlen(arr);i++,j--)
    {
        reverse[i] = arr[j];
        printf("%c",reverse[i]);
    }
    return;
}
int main()
{
    int i,j;
    char arr[100],reverse[100];
    printf("Enter String : ");
    gets(arr);
    reversed(arr,reverse);
}
