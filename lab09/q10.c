#include<stdio.h>
int min(int arr[],int count)
{
	int i,small = arr[0];
	for(i = 1; i < count; i++)
	{
		if(arr[i] < small)
		{
			small = arr[i];			
		}
	}
	return small;
}
int max(int arr[],int count)
{
	int i,large = arr[0];
	for(i = 1; i < count; i++)
	{
		if(arr[i] > large)
		{
			large = arr[i];			
		}
	}
	return large;
}
int main()
{
	int i,count;
    printf("Enter number of values : ");
    scanf("%d",&count);
	int arr[count];
	for(i = 0; i < count; i++)
	{
		printf("Enter Element-%d : ",i);
		scanf("%d",&arr[i]);
	}
	printf("Minimum : %d\n",min(arr,count));
	printf("Maximum : %d\n",max(arr,count));
}
