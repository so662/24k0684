#include<stdio.h>
#include<stdlib.h>
void mm( int **arr ,int **arr1 ,int m ,int n,int p, int q)
{
    int arr2[m][q];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < q; j++)
        {
            arr2[i][j] = 0;
            for (int k = 0; k < p; k++)
            {
                arr2[i][j] +=  arr[i][k] * arr1[k][j];
                
            }  
        }  
    }
    for (int j = 0; j < m; j++)
    {
        for (int k = 0; k < q; k++)
        {
            printf("|%-3d| ",arr2[j][k]);
        } 
        printf("\n"); 
    }  
    return;
}

int main()
{
    int m,n,p,q;
    printf("Enter row of Matrix 1 : ");
    scanf("%d",&m);
    printf("Enter column of Matrix 1 : ");
    scanf("%d",&n);
    int *arr[m];
    for (int i = 0;i < m; i ++)
    {
        arr[i] = (int *)malloc(n*sizeof(int));
    }
    for(int i = 0;i < m;i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("Enter Matrix[%d][%d] : ",i+1,j+1);
            scanf("%d",&arr[i][j]);
        }
    }
    printf("Enter row of Matrix 2 : ");
    scanf("%d",&p);
    printf("Enter column of Matrix 2 : ");
    scanf("%d",&q);
    if (n != p)
    {
        printf("\nInvalid! Cannot multiply");
        return 0;
    }
    int *arr1[p];
    for (int i = 0;i < p; i ++)
    {
        arr1[i] = (int *)malloc(q*sizeof(int));
    }
    printf("\n");
    for(int i = 0;i < p;i++)
    {
        for(int j = 0; j < q; j++)
        {
            printf("Enter Matrix[%d][%d] : ",i+1,j+1);
            scanf("%d",&arr1[i][j]);
        }
    }
    printf("\n");
    mm(arr,arr1,m,n,p,q);

}
