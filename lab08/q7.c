#include<stdio.h>
int main()
{
    int i,j,k,l,arr1[3][3],arr2[3][3],res[3][3];
    printf("Enter first matrix values\n\n");
    for(i = 0; i < 3; i++)
    {
        for(j = 0;j < 3; j++)
        {
            printf("Enter arr[%d][%d] : ",i,j);
            scanf("%d",&arr1[i][j]);
           
        }
    }
    printf("\nEnter second matrix values\n\n");
    for(i = 0; i < 3; i++)
    {
        for(j = 0;j < 3; j++)
        {
            printf("Enter arr[%d][%d] : ",i,j);
            scanf("%d",&arr2[i][j]);
           
        }
    }
     for(i = 0 ;i < 3;i++)
    {
        for(j = 0; j < 3; j++)
        {
        res[i][j]=0;
        }
    }
    printf("\n##---------- Matrix 1 ---------##\n\n");
   
    for(i = 0 ;i < 3;i++)
    {
        for(j = 0; j < 3; j++)
        {
        printf(" |%2d| ",arr1[i][j]);
        
        }
        printf("\n\n");
    }
    printf("\n##---------- Matrix 2 ---------##\n\n");
   
    for(i = 0 ;i < 3;i++)
    {
        for(j = 0; j < 3; j++)
        {
        printf(" |%2d| ",arr2[i][j]);
        
        }
        printf("\n\n");
    }

    for(j = 0; j < 3; j++)
    {
    	for(k = 0; k < 3; k++)
    	{
    		for(l = 0; l < 3; l++)
    			res[j][k] = res[j][k] + (arr1[j][l] * arr2[l][k]);
		}
	}
	printf("\n##-------- Resultant Matrix -------##\n\n");
   
    for(i = 0 ;i < 3;i++)
    {
        for(j = 0; j < 3; j++)
        {
        printf(" |%3d| ",res[i][j]);
        
        }
        printf("\n\n");
    }
}
