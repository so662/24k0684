#include<stdio.h>
int main()
{
	int n;
	printf("Enter number : ");
	scanf("%d", &n);
	if(n%2 == 0 && n%5 == 0)
		printf("YES");
	else
		printf("NO");
}		 