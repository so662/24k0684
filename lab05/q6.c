#include<stdio.h>
int main()
{
	int n;
	printf("ENTER NUMBER : ");
	scanf("%d",&n);
	n > 0 ? printf("POSITIVE"):n == 0? printf("ZERO"):printf("NEGATIVE");
}