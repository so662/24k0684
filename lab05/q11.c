#include<stdio.h>
int main()
{
	int n1,n2,n3;
	printf("ENTER NUMBER 1 : ");
	scanf("%d",&n1);
	printf("ENTER NUMBER 2 : ");
	scanf("%d",&n2);
	printf("ENTER NUMBER 3 : ");
	scanf("%d",&n3);
	if(n1>n2 && n1>n3)
		printf("NUMBER 1 = %d is greatest",n1);
	else if(n2>n1 && n2>n3)
		printf("NUMBER 2 = %d is greatest",n2);
	else
		printf("NUMBER 3 = %d is greatest",n3);
}
