#include<string.h>
#include<stdio.h>
int main()
{
	int n,i,j,k;
	printf("Enter Count : ");
	scanf("%d",&n);
	int arr2[n];
	char arr[n][100];
	for(i = 0; i < n;i++)
	{
		printf("Enter values %d : ",i);
		scanf("%d",&arr2[i]);
	}
	printf("\n\n------HORIZONTAL HISTOGRAM------\n\n");
	for(i = 0; i < n; i++)
	{
		printf("%2d   ",arr2[i]);
		for(j =0; j < arr2[i];j++)
		{
			printf("* ");
		}
		printf("\n");
	}
	k = arr2[0];
	for (i = 1; i < n; i++)
	{
		if (arr2[i] > k)
		k = arr2[i];
	}
	for (i = 0; i < n ; i++)
	{
		for(j = 0 ;j < k; j++)
		{
			if(j < arr2[i])
				arr[i][j] = '*';
			else arr[i][j] = ' ';
		}
	}
	
printf("\n\n------VERTICAL HISTOGRAM------\n\n");
	for (j = k-1  ; j >= 0 ; j--)
	{
		for(i = 0 ; i < n; i++)
		{
			printf(" %2c",arr[i][j]);
		}
		printf("\n");
	}
	for(j =0; j < n;j++)
		{
			printf(" %2d",arr2[j]);
		}	
}
