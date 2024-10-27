#include<stdio.h>
int main()
{
    int i,j,k,sum1 =0,sum2 =0;
    int arr[2][3][3];
    for(i = 0 ;i < 2;i++)
    {
        for(j =0;j<3;j++)
        {
            for(k =0;k<3;k++)
            {
                printf("Enter arr[%d][%d][%d] : ",i,j,k);
                scanf("%d", &arr[i][j][k]);
            }
        }
    }
    for(i = 0 ;i < 2;i++)
    {
        for(j =0;j<3;j++)
        {
            for(k =0;k<3;k++)
            {
            printf(" |%2d| ",arr[i][j][k]);

            }
            printf("\n");
        
        }
        printf("\n");
    }
    for(i = 0 ; i<2; i++)
    {
        for(j =0;j<3;j++)
        {
            for(k =0 ;k < 3;k++)
            {
                if(i == 0)
                {
                    sum1 += arr[i][j][k];
                }
                else 
                {
                    sum2 += arr[i][j][k];
                }
            }
        }
    }
    printf("sum1 : %d\nsum2 : %d",sum1,sum2);
}
    