#include<stdio.h>
#include<string.h>
#include<stdbool.h>
int main()
{
    int i;
    bool found = false;
    char arr[][20] = {"ahmed","muhammad","soofiyan","hamza","asim"};
    char arr2[20];
    printf("Enter string to find : ");
    scanf("%s",&arr2);
    for (i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
    {
		if (strcmp(arr2,arr[i]) == 0)
        {
        found = true;
		}
    }
    if (found == true)
    {
    	printf("Found \n");
	}
	else printf("Not found\n");

}

