#include<stdio.h>
#include<string.h>
#include<stdbool.h>
int main()
{
    int i,j,l,k,v[100];
	char x,words[][100] = {"eat", "tea", "tan", "ate", "nat", "bat"};
    char temp[100][100];
    int rows = sizeof(words) / sizeof(words[0]);
    bool found = false,first = false;
	
	for ( i = 0; i < rows; i++)
    {
        strcpy(temp[i],words[i]);
    }
    for(i = 0; i < rows; i++)
    {        
        for(j = 0 ; j < strlen(words[i])-1; j++)
        {
           for (k = 0; k < strlen(words[i])-1; k++)
           {
            if(temp[i][k] > temp[i][k+1])
                {
                    x = temp[i][k];
                    temp[i][k] = temp[i][k+1];
                    temp[i][k+1] = x;

                }
           }
        }
    }
    j = 0;
    printf("\n{");
	while(j < rows)
	{
		found = false;
		first = false;
		for (i = j; i < rows; i++)
	    {	
			if(strcmp(temp[j],temp[i])==0 && v[i] != i)
	        {
	            printf("['%s']",words[i]);
	            first = true;
	            v[i] = i;
			    if (i != j)
					{
					found = true;
					}
	        }
        }

	    if (found == true || (first== true && found != true) && j != rows-1)
	        printf("}\n{");
         
		j++;
    }
       printf("}");
}



