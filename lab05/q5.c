#include <stdio.h>
int main()
{
	int n1,n2;
	printf("ENTER NUMBER 1 : ");
	scanf("%d", &n1);
	printf("ENTER NUMBER 2 : ");
	scanf("%d", &n2);
	n1 > n2 ? printf("NUMBER 1 = %d is greater.\n",n1) : printf("NUMBER 2 = %d is greater.\n",n2);
	return 0;
}