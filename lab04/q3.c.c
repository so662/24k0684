#include <stdio.h>
int main()
{	
	char a;
	printf("press any key from the keyboard : ");
	scanf("%c",&a);
	if(a >= '0' && a <= '9')
		printf("it is a digit");
	else if(a >= 'A' && a <= 'Z')
		printf("it is a capital alphabet");
	else if(a>= 'a' && a <= 'z')
		printf("it is a small alphabet");
	else 
		printf("it is a special character");
}
