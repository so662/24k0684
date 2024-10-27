#include<stdio.h>
#include<stdbool.h>
int main()
{
    int i,j,start,end;
    
    printf("Give starting point : ");
    scanf("%d",&start);
    printf("Give ending point : ");
    scanf("%d",&end);
    if(start < 2)
    start = 2;
    printf("\n\n----------prime numbers are----------\n\n");
    for(i = start; i<=end; i++)
    {
        bool prime = false;
        for(j = 2 ; j < i; j++)
        {
           
            if(i%j == 0)
            {
                prime = true;
            }
            
        }
        if (prime == false)
            printf("%d\n",i);
    }
}