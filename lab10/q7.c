#include <stdio.h>
void temp(int n)
{
    static int count = 0;
    if(n > 25)
    {count++;}
    printf("\nFunction is being called %d times\n",count);

}
int main()
{
    int n,choice = 0;
    while(choice != 2)
    {
        printf("---------Check for Temperature --------\n\n1.check\n2.Exit\nchoose an option : ");
        scanf("%d",&choice);
        if (choice == 1)
        { 
            printf("Enter Temperature : ");
            scanf("%d",&n);
            temp(n);
        }
        else if (choice == 2)
        {
            printf("\nExiting program.............\n");
        }
        else
        {
            printf("\nCHoose a valid option\n");
        }
        
    }
    return 0;
}
