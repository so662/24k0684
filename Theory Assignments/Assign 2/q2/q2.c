#include<stdio.h>
#include<strings.h>
int main()
{
	int i,j,k[100];
	char arr[100],arr3[100];
	printf("slogans = [");
	gets(arr3);
	strcpy(arr,arr3);
	int arr2[sizeof(arr)];
	for(i = 0; i < 100 ; i++)
	{
		arr2[i] = 1;
			
			   
		
	}
	for(i = 0; arr[i] != '\0'; i++)
	{
			for(j = i+1 ;j < strlen(arr) && arr[j] != ',' ; j++)
		{
			if(arr[i] == arr[j])
				{
				arr[j] = -1;
				arr2[i] = arr2[i] + 1 ;
				
				}
		}
	 } 
	
	printf("{");
	for(i = 0; i < strlen(arr); i++)
	{
		
		if(arr[i] == ',')
		printf("}\n{");
		
		
		if(arr[i] != -1 && arr[i] != '"'&& arr[i] != ']' && arr[i] != ',')
			printf("'%c': %d,",arr[i],arr2[i]);		
	}
	printf("}");
}

