#include<stdio.h>
int main()
{
	int A,M,F,T,TOTAL;
	printf("TOTAL ATTENDANCE IN PERCENTAGE OUT OF 100 : ");
	scanf("%d",&A);
	if(A >= 80)
	{
		printf("TOTAL ASSIGMENT MARKS OUT OF 20 : ");
		scanf("%d",&M); 
		printf("MID TERM MARKS out of 30 : ");
		scanf("%d",&T);
		printf("FINAL MARKS out of 50 : ");
		scanf("%d",&F); 
		TOTAL = M + T + F;
		printf("PERCENTAGE = %d \n",TOTAL);
		if(TOTAL >= 80)
			printf("GRADE = A");
		else if(TOTAL >= 70)
			printf("GRADE = B");
		else if(TOTAL >= 60)
			printf("GRADE = C");
		else if(TOTAL >= 50)
			printf("GRADE = D");
		else
			printf("GRADE = U/FAIL");
	}
	else
		printf("ATTENDANCE MUST BE GREATER THAN 80 FOR GRADE");
}
	
	
	
