#include<stdio.h>
int main()
{
    int i,j,end;
    printf("Give ending point : ");
    scanf("%d",&end);
    printf("\n\n----------odd numbers are----------\n\n");
    for(i = end; i >= 0; i-=2)
    {
        for(j = end; j >= i; j-=1)
        {
            if(j%2 != 0)
            {
                printf("%d ",j);
            }
        }
        printf("\n");
    }
}
