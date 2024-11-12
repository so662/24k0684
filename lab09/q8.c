#include<stdio.h>
#include<strings.h>
float calc(float ,float ,char);

float calc(float i,float j,char ope)
{
    float result;
	if(ope == '+')
    result =  i + j;
    else if(ope == '-')
    result = i - j;
    else if(ope == '*')
    result = i * j;
    else if(ope == '/')
    {
		if (j != 0)
	    result =  i/j;
	    else 
		{
		printf("Division by zero is not allowed\n");
		return 0;
		}
	}
    else return 0;
	return result;  
}
int main()
{
    float i,j,k,g;
    char ope;
    printf("enter number : ");
    scanf("%f",&i);
    printf("enter number 2 : ");
    scanf("%f",&j);
    printf("enter operator : ");
    scanf(" %c",&ope);
    k = calc(i,j,ope);
    if(ope != '+' && ope != '-' && ope != '*' && ope != '/')
        printf("Invalid operator!\n");
    else if(k != 0)
		printf("%.2f %c %.2f = %.2f ",i,ope,j,k);	
	else return;
}
