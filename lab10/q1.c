//1. Write a recursive function that calculates the sum of digits of a number. For example, if
//the input is 123, the output should be 6.
#include<stdio.h>
int sum(int num)
{
    if(num == 0)
    return 0;
    else 
    {
        return num%10 + sum(num/10);
    }
}
int main()
{
    int num;
    printf("ENTER NUMBER :");
    scanf("%d",&num);
    printf("THE SUM IS : %d",sum(num));
}