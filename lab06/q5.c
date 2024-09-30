#include<stdio.h>
int main()
{
	int i,j;
	printf("65536,");
	for(i = 65536 , j = 2 ; j < 10 ; j++)
	{
		i = i/j;
		printf("%d,",i);
	}
}

