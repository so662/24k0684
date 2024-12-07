#include<stdio.h>
void print(int arr[],int size)
{
    if(size == 0)
    return;
    printf("%d\n",arr[size-1]);
    print(arr,size-1);
}
int main()
{
    int n;
    printf("Array size: ");
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    };
    print(arr,n);
}