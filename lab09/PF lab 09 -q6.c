#include<stdio.h>
#include<string.h>
#include<strings.h>
#include<stdbool.h>
int main()
{
    int i,j,k,count;
    bool found;
    
    printf("Enter number of words : ");
    scanf("%d", &count);
    char array[count][20];
    for (i = 0; i < count; i++)
    {
    	printf("Enter word : ");
        scanf("%s",array[i]);
    }
    for (i = 0; i < count; i++)
    {
      found = false;
      for (j = 0, k = strlen(array[i])-1 ; j < strlen(array[i])/2; j++,k--)
      {
        if (array[i][j] == array[i][k])
        {
          found = true;
        }
        else
        {
          found = false;
          break;
        }
      }
      if (found == true)
        printf("YES , %s is a palindrome\n",array[i]);
        else printf("NO, %s is not a palindrome\n",array[i]);
      
    }  
}
