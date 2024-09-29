#include<stdio.h>
int main()
{
	int n,i,c;
	printf("ENTER NUMBER : ");
	scanf("%d",&n);
	while(n == 1)
	{	
		i = n | 0;
		if(i == 1)
			c = c + 1;
		n = n>>1;
	}
	printf("THE NUMBER OF ONES IS %d ",c);
}
