/*Design a structure to store information about travel packages, including package name,
destination, duration, cost, and number of seats available. Write a program that allows
users to book a travel package and display available packages.*/
#include<stdio.h>
struct travel_package
{
    int list;
    char name[20];
    char destination[30];
    int duration;
    float cost;
    int no_of_seats;
};
int book(struct travel_package package)
{
    if(package.no_of_seats >= 0)
    {
        package.no_of_seats--;
        printf("\nSeat booked successfully! Remaining seats: %d\n", package.no_of_seats);
    }
    else printf("\nSorry, no available seats on this package.\n");
    return package.no_of_seats;
}
char print(struct travel_package package)
{
    printf("%2d. %-30s %-16s %4ddays       $%-8.2f        %-4d  \n", package.list,package.name, package.destination,package.duration, package.cost, package.no_of_seats);
}

int main()
{
    int k = 10;
    struct travel_package package[10] = {
        {1, "Adventure Tour", "Paris", 7, 1200.50, 20},
        {2, "Beach Escape", "Hawaii", 5, 800.30, 15},
        {3, "Mountain Trek", "Nepal", 10, 1500.75, 12},
        {4, "City Lights", "New York", 4, 950.00, 25},
        {5, "Cultural Experience", "India", 14, 2000.00, 30},
        {6, "Safari Tour", "Kenya", 12, 1800.60, 10},
        {7, "European Classics", "Italy", 8, 1300.20, 18},
        {8, "Tropical Paradise", "Maldives", 6, 1100.40, 22},
        {9, "Desert Adventure", "Dubai", 9, 1600.10, 16},
        {10, "Historical Journey", "Egypt", 11, 1400.90, 14}
    };
    int choice ,num;
    do
    {
       
        printf("\n<------- Travel Packages Management System -------->\n\n");
        printf("1. Display Available Packags\n");
        printf("2. Book a tour\n");
        printf("3. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("\nNo.      Name                     Destination        Duration        Cost       Available seats\n");
                printf("------------------------------------------------------------------------------------------------\n");
                for(int i = 0;i < k;i++)
                {
                    print(package[i]);
                }
                printf("------------------------------------------------------------------------------------------------\n");
                break;
            case 2:
                printf("\nNo.      Name                     Destination        Duration        Cost       Available seats\n");
                printf("------------------------------------------------------------------------------------------------\n");
                for(int i = 0;i < k;i++)
                {
                    print(package[i]);
                }
                printf("------------------------------------------------------------------------------------------------\n");
                printf("\n\nEnter package number (1 to 10): ");
                scanf("%d", &num);
                if (num >= 1 && num <= 10) 
                package[num-1].no_of_seats = book(package[num - 1]);
 
                else printf("\nInvalid package number.\n");
                break;
            case 3:
                printf("\nExiting program. Thank you!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");   
        }
    }
    while(choice != 3);
}
