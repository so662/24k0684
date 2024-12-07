#include<stdio.h>
int add_numbers()
{
    int a,b;
    printf("\nEnter number 1 : ");
    scanf("%d",&a);
    printf("\nEnter number 2 : ");
    scanf("%d",&b);
    return a + b;
}
int main()
{
    printf("\nResult = %d\n",add_numbers());
    return 0;
}
