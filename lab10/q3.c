/*1. Write a program that uses structures to manage flight information, including flight
number, departure city, destination city, date, and available seats. Create functionalities
to book a seat and display flight details.*/
#include <stdio.h>
struct flight
{
    char flight_number[20];
    char departure_city[20]; 
    char destination_city[20];
    char date[20];
    int available_seats;
};
void print_flight(struct flight my_flight)
{
    printf("\n\nFLIGHT DETAILS\n\n");
    printf("flight_number : %s\n",my_flight.flight_number);
    printf("departure_city : %s\n",my_flight.departure_city);
    printf("destination_city : %s\n",my_flight.destination_city);
    printf("date : %s\n",my_flight.date);
    printf("available_seats : %d\n",my_flight.available_seats);
}
int book(struct flight my_flight)
{
    if(my_flight.available_seats >= 0)
    {
        my_flight.available_seats--;
        printf("Seat booked successfully! Remaining seats: %d\n", my_flight.available_seats);
    }
    else printf("Sorry, no available seats on this flight.\n");
    return my_flight.available_seats;
}
int main()
{
    struct flight my_flight[5] = {
        {"AA123", "New York", "Los Angeles", "2024-12-01", 100},
        {"BA456", "London", "Paris", "2024-12-05", 80},
        {"CA789", "Beijing", "Tokyo", "2024-12-10", 120},
        {"DL101", "Chicago", "Miami", "2024-12-15", 150},
        {"UA202", "San Francisco", "Seattle", "2024-12-20", 90}
    };
    int choice ,num;
    do
    {
       
        printf("\n<------- Flight Management System -------->\n\n");
        printf("1. Display flight details\n");
        printf("2. Book a seat\n");
        printf("3. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("\nEnter Flight Number(1 to 5) : ");
                scanf("%d",&num);
                if(num > 0 && num <= 5)
                print_flight(my_flight[num-1]);
                else printf("\nINVALID FLIGHT NUMBER\n");
                break;
            case 2:
                printf("\nEnter flight number (1 to 5): ");
                scanf("%d", &num);
                if (num >= 1 && num <= 5) 
                my_flight[num-1].available_seats = book(my_flight[num - 1]);
 
                else printf("\nInvalid flight number.\n");
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