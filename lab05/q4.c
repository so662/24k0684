#include<stdio.h>
int main()
{
	int a;
	int c;
	printf("ENTER AGE : ");
	scanf("%d", &a);
	printf("ENTER PAKISTAN CITIZENSHIP STATUS (1 OR 0) : ");
	scanf("%d", &c);
	if(a > 18 && c)
		printf("YOU ARE ELIGIBLE FOR VOTE");
	else
		printf("YOU ARE NOT ELIGIBLE FOR VOTE");
}