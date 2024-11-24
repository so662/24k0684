/*Create a structure to store details about cars in a dealership, including make, model,
year, price, and mileage. Write a program that allows users to add new cars, display a
list of available cars, and search for cars by make or model.*/
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
struct car
{
    int list;
    char make[20]; 
    char model[20];
    int price; 
    int year;
    int mileage;
};
char print(struct car car)
{
    printf("%2d. %-15s %-15s $%-8d     %4d   %9d  KM\n", car.list,car.make, car.model,car.price, car.year, car.mileage);
}
void search_by_make(char arr[],struct car my_car[],int j)
{
    bool found = false;
    for (int i = 0; i < j; i++)
    {
        
        if(strcasecmp(arr,my_car[i].make)== 0)
        {
            print(my_car[i]);
            found = true;
        }
    }
    if(found == false)
    printf("\nNOT FOUND\n");
}
void search_by_model(char arr[],struct car my_car[],int j)
{
    bool found = false;
    for (int i = 0; i < j; i++)
    {
        
        if(strcasecmp(arr,my_car[i].model)== 0)
        {
            print(my_car[i]);
            found = true;
        }
    }
    if(found == false)
    printf("\nNOT FOUND\n");
}

int main()
{
    char arr[20];
    int k = 20;
    struct car my_car[100] = {
        {1, "Toyota", "Camry", 25000, 2022, 15000},
        {2, "Ford", "Mustang", 35000, 2021, 12000},
        {3, "Honda", "Civic", 20000, 2020, 18000},
        {4, "BMW", "3 Series", 40000, 2023, 5000},
        {5, "Chevrolet", "Malibu", 23000, 2022, 13000},
        {6, "Audi", "A4", 45000, 2021, 8000},
        {7, "Nissan", "Altima", 22000, 2020, 25000},
        {8, "Subaru", "Impreza", 21000, 2022, 16000},
        {9, "Toyota", "Corolla", 21000, 2021, 20000},
        {10, "Mercedes", "C-Class", 50000, 2022, 7000},
        {11, "Ford", "Explorer", 45000, 2021, 15000},
        {12, "Honda", "Accord", 27000, 2022, 10000},
        {13, "Tesla", "Model 3", 55000, 2023, 3000},
        {14, "Kia", "Seltos", 25000, 2021, 12000},
        {15, "Hyundai", "Sonata", 24000, 2020, 22000},
        {16, "Jeep", "Grand Cherokee", 60000, 2022, 8000},
        {17, "Volkswagen", "Jetta", 23000, 2021, 15000},
        {18, "Chevrolet", "Traverse", 49000, 2023, 4000},
        {19, "BMW", "X5", 65000, 2022, 6000},
        {20, "Lexus", "RX 350", 52000, 2021, 9000}
    };
    int choice ,num;
    do
    {
        printf("\n\n<------- Soofiyan Car Dealership -------->\n\n");
        printf("1. Display All Cars With details\n");
        printf("2. Search for Car (By Make)\n");
        printf("3. Search for Car (By Model)\n");
        printf("4. Add new Car\n");
        printf("5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
            printf("\nNo. Make            Model           Price         Year       Mileage\n");
            printf("-----------------------------------------------------------------------\n");
                for(int i = 0;i < k;i++)
                {
                    print(my_car[i]);
                }
                break;
            case 2:
                fflush(stdin);
                printf("\nEnter Make To search : ");
                gets(arr);
                printf("\n");
                 printf("\nNo. Make            Model           Price         Year       Mileage\n");
            printf("-----------------------------------------------------------------------\n");
                search_by_make(arr,my_car,k);
                break;
            case 3: 
                fflush(stdin);
                printf("\nEnter Model To search : ");
                gets(arr);
                printf("\n");
                printf("\nNo. Make            Model           Price         Year       Mileage\n");
            printf("-----------------------------------------------------------------------\n");
                search_by_model(arr,my_car,k);
                break;
            case 4:
                k++;
                my_car[k-1].list = k ;
                fflush(stdin);
                printf("\nEnter Car Make : ");
                gets(my_car[k-1].make);
                fflush(stdin);
                printf("\nEnter Car Model : ");
                gets(my_car[k-1].model);
                fflush(stdin);
                printf("\nEnter Car Price(in dollars) : $");
                scanf("%d",&my_car[k-1].price);
                fflush(stdin);
                printf("\nEnter Car Year (i.e 2000) : ");
                scanf("%d",&my_car[k-1].year);
                printf("\nEnter Car Mileage (in KM) : ");
                scanf("%d",&my_car[k-1].mileage);
                printf("\nCongratulations! Car Added Successfully\n");
              break;
            case 5:
                printf("\n-------------Thanks for using it------------\n");
                break;
            default:
                printf("\n\nInvalid choice. Please try again.\n");
                break;
        }
    } 
    while (choice != 5);      
}














