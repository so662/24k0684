#include<stdio.h>
int main()
{
	int n;
	int i = 0;
	printf("ENTER NUMBER : ");
	scanf("%d",&n);
	while(n != 0)
	{
		n = n/10;
		i = i + 1;
	}
	if(i == 1 || i == 0)
		printf("NOT A MULTIPLE DIGIT NUMBER");
	else
		printf("MULTIPLE DIGIT NUMBER");
}
