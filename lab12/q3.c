#include <stdio.h>
#include<stdlib.h>
int main(int argc, char const *argv[])
{
    int n,sum = 0;
    printf("Enter size of Array : ");
    scanf("%d",&n);
    int *ptr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        printf("Enter Element-%d : ",i);
        scanf("%d",&ptr[i]);
        sum = sum + ptr[i];
    }
    printf("Sum = %d\n",sum);
    free(ptr);
    return 0;
}
