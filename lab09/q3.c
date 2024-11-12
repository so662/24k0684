#include <stdio.h>
#include <string.h>
int main()
{
    int i, n;
    char source[100], destination[100];
    printf("Enter source string : ");
    gets(source);
    printf("Enter destination string : ");
    gets(destination);
    printf("Enter number of characters you want to concatenate : ");
    scanf("%d", &n);
    strncat(destination, source, n);
    printf("%s", destination);
}
