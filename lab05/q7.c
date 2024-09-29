#include<stdio.h>
int main()
{
	int a,b,c;
	printf("ENTER NUMBER 1 : ");
	scanf("%d",&a);
	printf("ENTER NUMBER 2 : ");
	scanf("%d" ,&b);
	c = (a^b)^b;
	b = (a^b)^a;
	a = c ;
	printf("NUMBER 1 = %d\nNUMBER 2 = %d",b,a);
}