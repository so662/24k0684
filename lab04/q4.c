#include<stdio.h>
int main()
{
	int n = 0;
	float D,A;
	printf("Enter Amount : ");
	scanf("%d",&n);
	if(n>= 500 && n<= 2000)
		D = n * 0.05;
	else if(n>= 2000 && n< 4000)
		D = n * 0.1;
	else if(n>= 4000 && n< 6000)
		D = n * 0.2;
	else if(n>= 6000)
		D = n * 0.35;
	else{
		printf("Amount is not applicable for discount");
		return 0;
	}A = n - D;
	printf("The amount is %d\n", n);
	printf("You saved %.2f\n", D);
	printf("The discounted amount is %.2f", A);
}
		