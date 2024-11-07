#include<stdio.h>
#include<strings.h>
#include<stdbool.h>
int main()
{
	int i ,j = 0 ,k,count;
	char arr[100],arr2[100];
	printf("Enter words(seprated by commas) : ");
	gets(arr);
	for(i = 0;i < strlen(arr);i++)
	{
		if( arr[i] == arr[i-1])
			{
				count+= 1;
			}
		else arr2[j++] = arr[i];
	}
  printf("compressed words : \n");
  i =0;
  while(i < strlen(arr2))
  {
  if(arr2[i] == '['|| arr2[i] == ']'||arr2[i] == '"'|| arr2[i] == ' ')
		i++;
	else
	{
		printf("%c",arr2[i]);
    	i++;
	}
  if(arr2[i] == ',')
	{
		printf("\n");
		i++;
	}
	
	
   }
  printf("\nletters removed = %d", count);
}

