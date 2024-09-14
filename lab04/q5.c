#include<stdio.h>
int main()
{
	char ID[4];
	char CN[20];
	int UC,SC;
	float B;
	printf("Enter your ID : ");
	scanf("%s",&ID);
	printf("Enter your name : ");
	scanf("%s",&CN);
	printf("Enter Units consumed : ");
	scanf("%d",&UC);
	printf("\n\n\nCustomer ID : %s\n",ID);
	printf("Customer Name : %s\n",CN);
	printf("Units Consumed : %d\n",UC);
	if(UC>= 0 && UC< 200){
		B = UC * 16.20;
		printf("Amount Charges @Rs.16.20 per unit: %f\n",B);
	}else if(UC>= 200 && UC< 300){
		B = UC * 20.10;
		printf("Amount Charges @Rs.20.10 per unit: %f\n",B);
	}else if(UC>= 300 && UC< 500){
		B = UC * 27.10;
		printf("Amount Charges @Rs.27.10 per unit: %f\n",B);
	}else if(UC>= 500){
		B = UC * 35.90;
		printf("Amount Charges @Rs.35.90 per unit: %f\n",B);
	}else 
		return 0;
	if(B > 18000){
		SC = B * 0.15;
		B = B + SC;
	}else
		SC = 0;
	printf("Surcharge Amount: %d\n",SC);
	printf("Net Amount Paid by the Customer: %.2f\n",B);
}
	
	


	
	