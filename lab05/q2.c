#include<stdio.h>
int main()
{
	int n ;
	printf("ENTER NUMBER TO CHECK : ");
	scanf("%d", &n);
	if(n > 0)
		printf("POSITIVE");
	else if(n == 0)
		printf("ZERO");
	else 
		printf("NEGATIVE");
}