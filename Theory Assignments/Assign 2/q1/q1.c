//Name = Soofiyan imran
//Date = 7-oct-2024
//

#include<stdio.h>
#include<stdbool.h>
int main()
{
	int arr[5],i,small1 ,small2;
	bool found = false;
	for(i = 0; i < 5; i++)
	{
		printf("Enter Element-%d : ",i);
		scanf("%d",&arr[i]);
	}
	small1 = arr[0];//making element 0 as smallest element to compare
	for(i = 1; i < 5; i++)
	{
		if(arr[i] < small1)
		{
			small1 = arr[i];			
		}
	}//updating smallest value by comparing with other values
	for(i = 0; i < 5; i++)
	{
		if (arr[i] != small1)			
		{
			small2 = arr[i];
			found = true;
			break;
		}
	}//making second smallest value which must not be equal to smallest
	for(i = 0 ; i < 5; i++)
	{
		if(arr[i] < small2 && arr[i] != small1)
		{
			small2 = arr[i];
		}
	}//updating second smallest value by comparing and checking that it must not equal to smallest
	
	if(found == true)
		printf("The Second smallest element in the array is : %d",small2);
	else
		printf("NO second smallest element found");
}
