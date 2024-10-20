#include<stdio.h>
int main()
{
	int arr[10],i;
	printf("ENTER NUMBER OF VALUES\n");
	for(i = 0;i<10;i++){
		printf("Enter number %d : ",i);
		scanf("%d",&arr[i]);
}
	int max = arr[0];
	int min = arr[0];
	for(i = 0;i<10;i++){
		if(arr[i]>max)
			max = arr[i];
		else if(arr[i]<min)
			min = arr[i];
	}
	printf("\n###----------------###\n\nMAXIMUM = %d\n\n###----------------###\n\nMINIMUM = %d",max,min);
}
