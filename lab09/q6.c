#include<stdio.h>
#include<strings.h>

void swapintegers(int a,int b)
{
    int c;
    c = a;
    a = b;
    b = c;
   printf("\n\na = %d\nb = %d",a,b);
}
int main()
{
    int a,b;
	printf("ENTER Number : \na = ");
    scanf("%d",&a);
    printf("b = " );
    scanf("%d",&b);
    swapintegers(a,b);
}
