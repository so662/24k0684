#include<stdio.h>

int i, j, k,l = 0;
void firsthalf(int n)
{
	
	
	for(i = 1;i < n;i++)
        {
            for(k = 2*(n - 1);k >= i && i < n ;k--)
            {
                printf(" ");
            } 
			printf("*");
			
            for(j = 1; j < l ; j = j+1)
            {
                printf(" ");
            }
            l = l + 2;
            if(i != 1)
            	printf("*"); 
            printf("\n");

        }
        for(k = 0 ; k < n ; k++)
        {
           	printf("*",k);
		}
		for(j =0; j < (2*(n - 1) - 1);j++)
		{
			printf(" ");
		}
		for(k = 0 ; k < n ; k++)
        {
            	printf("*");
		}
		printf("\n");          
 
}
void secondhalf(int n)
{
	l = 5;

	for(k = 5; k <= n; k= k+2)
	{
		l = l + 8;
	}
	for(i = 1; i < n;i++)
	{
		for(j = 0; j < i; j++)
		{
			printf(" ");
		}
		
		printf("*");
		for(k = 0; k < l ;k++)
		{
			printf(" ");
		}
		l = l-2;
		printf("*");
		printf("\n");
	}
}
void thirdhalf(int n)
{
	k = 1;
	for(j = n-2; j > 0; j--)
	{
		for(i =j;i > 0;i--)
		{
			printf(" ");
		}
		printf("*");
		for(i = j ;i > 0;i--)
		{
			printf(" ");
		}
		printf("*");
		
		for(i = 1;i <= k;i++)
		{
			printf(" ");
		}
		k = k+4;
		printf("*");
		for(i = j ;i > 0;i--)
		{
			printf(" ");
		}
		printf("*");
		printf("\n");
	}
	j = 7;

	for(l = 5; l <= n; l= l+2)
	{
		j = j + 8;
	}
	printf("*");
	for(i = 0 ;i < j;i++)
	{
		printf(" ");
	}
	printf("*");
	
}
int main()
{
    int n;
    printf("Enter number : ");
	scanf("%d",&n);
	firsthalf(n);
	secondhalf(n);
	thirdhalf(n);        
}
