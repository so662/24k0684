#include<stdio.h>
int main()
{
    int i,j,n;
    printf("Enter matrix rows (eg 3 = 3*3 matrix) : ");
    scanf("%d",&n);
    int arr[n][n],trans[n][n];
    for(i = 1 ;i <= n;i++)
    {
        for(j =1;j<=n;j++)
        {
        printf("Enter arr[%d][%d] : ",i,j);
        scanf("%d",&arr[i][j]);
        }
    }
    printf("\n##----------Your Matrix----------##\n\n");
   
    for(i = 1 ;i <= n;i++)
    {
        for(j =1;j<=n;j++)
        {
        printf(" |%2d| ",arr[i][j]);
        
        }
        printf("\n\n");
    }
    for(i = 1 ;i <= n;i++)
    {
        for(j =1;j<=n;j++)
        {
        trans[i][j] = arr[j][i];
        
        }
    }
    printf("\n\n##----------Transpose Matrix----------##\n\n");
       for(i = 1 ;i <= n;i++)
    {
        for(j =1;j<=n;j++)
        {
            printf(" |%2d| ",trans[i][j]);
        
        }
        printf("\n\n");
    }
}