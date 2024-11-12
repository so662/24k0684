#include<stdio.h>
int prime(int j);
int main()
{
    int j;
    printf("Enter number : ");
    scanf("%d",&j);
    if(prime(j) == 1)
    printf("%d is a prime number ", j);
    else 
    printf("%d is not a prime number ", j);
}
int prime(int j)
{
	int i;
    for ( i = 2; i <= j/2; i++)
    {
        if(j % i == 0)
        return 0;
        
    }
    return 1;
}
