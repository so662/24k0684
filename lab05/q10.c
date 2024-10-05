#include<stdio.h>
int main()
{
	int i,n;
	printf("ENTER NUMBER : ");
	scanf("%d",&n);
	while (n > 10)
	{
		i = n%10;
		n = n/10 + i ;
	}
	
	printf("THE SUM IS %d",n);
}
