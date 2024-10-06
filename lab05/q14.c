#include<stdio.h>
int main()
{
	int a,i,c;
	printf("ENTER YOUR AGE : ");
	scanf("%d",&a);
	printf("ENTER INCOME : ");
	scanf("%d",&i);	
	printf("ENTER CREDIT SCORE(BETWEEN 300 TO 850) : ");
	scanf("%d",&c);	
	if(a >= 18 && i >= 60000 && c >= 500)
		printf("ELIGIBLE FOR LOAN");
	else
		printf("NOT ELIGIBLE FOR LOAN");
}








