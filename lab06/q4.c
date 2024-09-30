#include<stdio.h>
int main()
{
	int sum,i,j,n;
	printf("1,3,");
	for(n = 1,i = 1,j = 3;n<9; n++)
	{
		sum = i + j;
		i = j;
		j = sum;
		printf("%d,",sum);
	}
}
