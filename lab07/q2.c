#include<stdio.h>
int main()
{
	int n = 0,k;
	printf("ENTER NUMBER OF VALUES YOU WANT TO SEE IN REVERSE ORDER : ");//how many values you want to put in array
	scanf("%d",&n);
	int a[n] ;
	printf("ENTER NUMBERS\n\n");
	int i,j;
	for( i = 0 ; i<n ; i++){
		printf("%d : ",i +1);
		scanf("%d",&a[i]);
		
	}
	k = (sizeof(a)/sizeof(a[0]))-1;
	printf("\nREVERSE ORDER\n\n");
	for( i = 0, j = 1 ; k>=i ; k--,j++){
		printf("%d : %d \n",j,a[k]);
	}
}
