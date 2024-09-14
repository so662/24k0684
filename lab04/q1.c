#include <stdio.h>
int main()
{
	int a;
	printf("enter a number : ");
	scanf("%d", &a);
	if (a > 0 && a % 3 == 0){
		printf("it is a multiple of 3");
	}else{
		printf("not a multiple of 3");
	}
}	

		