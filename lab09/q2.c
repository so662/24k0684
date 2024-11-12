#include<stdio.h>
void evenodd(int n)
{
    if (n%2 == 0)
    {
        printf("%d is even",n);
    }
    else
    {
        printf("%d is odd",n);
    }   
}
int main()
{
    int n;
    printf("Enter number : ");
    scanf("%d",&n);
    evenodd(n);
}
