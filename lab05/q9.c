#include<stdio.h>
int main()
{
	int n;
	printf("ENTER YEAR : ");
	scanf("%d",&n);
	if(n%4 == 0 && n%100 != 0 || n%400 == 0)
		printf("LEAP YEAR");
	else
		printf("NOT A LEAP YEAR");
}