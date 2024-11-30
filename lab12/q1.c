#include<stdio.h>
#include<stdlib.h>
struct student
{
    char name[50];
    int marks;
};
int main()
{
    int n,total = 0;
    float avg;
    printf("Enter number of students : ");
    scanf("%d",&n);
    struct student *std;
    std = (struct student *)malloc(n *sizeof(struct student));
    if(std == NULL)
    {
        printf("MEMORY ALLOCATION FAILED!");
        return 0;
    }
    for(int i = 0 ; i < n; i++)
    {
        fflush(stdin);
        printf("Enter student %d name : ",i+1);
        fgets(std[i].name,50,stdin);
        printf("Enter %s's Marks : ",std[i].name);
        scanf("%d",&std[i].marks);
        total = total + std[i].marks;
    }
    avg = total/n;
    printf("total average marks of %d students is %.2f: ",n,avg);
}
