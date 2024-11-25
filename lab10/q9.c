/*Write a recursive function bubbleSort that takes an array and its size. It performs the
bubble sort algorithm by repeatedly comparing adjacent elements and swapping them if
they are in the wrong order.*/
#include<stdio.h>
#include<stdbool.h>
void bubble_sort(int arr[],int size)
{ 
    int temp;
    bool flag = false; 
    for(int j = 0 ; j < (size-1) ; j++)
    { 
        if(arr[j] > arr[j+1])
        {
            temp = arr[j+1];
            arr[j+1] = arr[j];
            arr[j] = temp;
            flag = true;
        }  
    }
    if(size == 1 || flag == false)
    return;
    bubble_sort(arr,size-1);
}
int main()
{
    int size;
    printf("\nEnter size of Array : ");
    scanf("%d",&size);
    int arr[size];
    for (int i = 0 ; i < size; i++)
    {
        printf("Enter element-%-2d : ",i+1);
        scanf("%d",&arr[i]);
    }
    printf("\n<----- YOUR ARRAY ------>\n");
    for(int j = 0;j < size;j++)
        printf("Element-%-2d : %d\n",j +1,arr[j]);
    bubble_sort(arr,size);
    printf("\n<----- SORTED ARRAY ------>\n");
    for(int j = 0 ; j < size; j++)
        printf("Element-%-2d : %d\n",j+1,arr[j]);
}
