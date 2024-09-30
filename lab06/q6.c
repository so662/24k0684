#include<stdio.h>
int main()
{
	int i,j,sum,k;
	printf("1,2,");
	for(i = 1 , j = 2 , k = 0; k < 7 ; k++)
	{
		sum = i * j;
		i = j;
		j = sum;
		printf("%d,",sum);
	}
}