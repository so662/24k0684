#include<stdio.h>
int main()
{
	int i,k,n;
	printf("ENTER NUMBER : ");
	scanf("%d",&n);
	for(i = 2 , k = 0; i < n ; i++)
	{
		if(n % i == 0)
		{
			k = 1;
			break;
		}
	}
	if(k == 1)
		printf("COMPOSITE");
	else
		printf("PRIME");
}