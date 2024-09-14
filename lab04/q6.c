#include<stdio.h>
int main()
{
	int n;
	printf("Enter number (between 1 to 9) for spelling : ");
	scanf("%d",&n);
	switch(n)
	{
		case 1 :
			printf("one");
			break;
		case 2 :
			printf("two");
			break;
		case 3 :
			printf("three");
			break;
		case 4 :
			printf("four");
			break;
		case 5 :
			printf("five");
			break;
		case 6 :
			printf("six");
			break;
		case 7 :
			printf("seven");
			break;
		case 8 :
			printf("eight");
			break;
		case 9 :
			printf("nine");
			break;
		default :
			if(n > 9)
				printf("OOPS ! Number is greater than 9");
			else
				printf("Invalid input! Please enter a number between 1 and 9\n");
	}
	return 0;
}