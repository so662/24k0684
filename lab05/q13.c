#include<stdio.h>
int main()
{
	
	char  D,E,a,key;
	printf("ENTER CHARACTER TO PERFORM ENCRYPTION : ");
	scanf("%c",&a);
	printf("ENTER KEY : ");
	scanf("%d", &key);
	E = a^key;
	printf("\nENCRYPTER CHARACTER IS %c",E);
	D = E^key;
	printf("\nDECRYPTED CHARACTER IS %c",D) ;
}
