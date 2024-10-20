#include<stdio.h>
int main()
{
	int sum = 0,t;
	printf("HOW MANY NUMBERS YOU WANT TO SUM  :  ");
	scanf("%d",&t);
	int n[t];
	printf("ENTER NUMBERS\n");
	for(int i = 0 ; i<t ; i++){
		printf("%d : ",i +1);
		scanf("%d",&n[i]);
		sum = sum + n[i];
	}
	printf("THE SUM IS : %d",sum);
}
		
	