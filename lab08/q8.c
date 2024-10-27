#include<stdio.h>
int main()
{
	int i,j,n,k;
	printf("Enter number : ");
	scanf("%d",&n);
	for(i = 1; i <= n; i++)
	{
		for(j = n-1-i; j >= 0; j--)
		{
			printf(" ");	
		}
		for(k = 1; k <= i; k++)
		{
			printf("* ");
		}
		printf("\n");
	}
	for(i = n-1; i > 0; i--)
	{
		for(j = i; j < n; j++)
		{
			printf(" ");	
		}
		for(k = i; k > 0; k--)
		{
			printf("* ");
		}
		printf("\n");
	}
		
}
