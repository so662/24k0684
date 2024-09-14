#include <stdio.h>
	int main()
{
	char b;
	int num1,num2,Ans;
	printf("Enter number 1 : ");
	scanf("%d",&num1);
	printf("Enter number 2 : ");
	scanf("%d",&num2);
	printf("Enter operator : ");
	scanf(" %c", &b);
	switch(b)
	{
		case '+':
		Ans = num1+num2;
		break;
		case '-':
		Ans = num1-num2;
		break;
		case '*':
		Ans = num1*num2;
		break;
		case '/':
		Ans = num1/num2;
		break;
		default: 
		printf("INVALID OPERATOR");
	}
	printf("The Answer = %d",Ans);
	return 0;
}