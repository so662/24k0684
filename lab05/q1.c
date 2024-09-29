#include<stdio.h>
int main()
{
	int n;
	printf("WHAT IS YOUR AGE : ");
	scanf("%d",&n);
	if(n < 12 & n > 0)
		printf("Child");
	else if(n < 20)
		printf("Teenager");
	else if(n < 64)
		printf("Adult");
	else if(n > 64)
		printf("Senior");
	else 
		printf("Invalid Input");
}
