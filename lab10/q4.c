/*Write a program that use a structure to hold information about movies, such as title,
genre, director, release year, and rating. Write a program that allows users to add new
movies, search for movies by genre, and display all movie details.*/
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
struct movies
{
    int list;
    char title[50];
    char genre[50];
    char director[50]; 
    int year;
    float rating;

};
char print(struct movies movie)
{
    printf("%2d. %-50s %-15s %-30s %4d   %.1f/10\n", movie.list, movie.title, movie.genre, movie.director, movie.year, movie.rating);
}
void search(char arr[],struct movies my_movies[],int j)
{
    bool found = false;
    for (int i = 0; i < j; i++)
    {
        
        if(strcasecmp(arr,my_movies[i].genre)== 0)
        {
            print(my_movies[i]);
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
    struct movies my_movies[100] = {
        {1,"The Shawshank Redemption", "Drama", "Frank Darabont", 1994, 9.3},
        {2,"Forrest Gump", "Drama", "Robert Zemeckis", 1994, 8.8},
        {3,"Mad Max: Fury Road", "Action", "George Miller", 2015, 8.1},
        {4,"John Wick", "Action", "Chad Stahelski", 2014, 7.4},
        {5,"Interstellar", "Fiction", "Christopher Nolan", 2014, 8.6},
        {6,"Blade Runner 2049", "Fiction", "Denis Villeneuve", 2017, 8.0},
        {7,"Spider-Man: Into the Spider-Verse", "Animation", "Bob Persichetti, Peter Ramsey", 2018, 8.4},
        {8,"Toy Story 4", "Animation", "Josh Cooley", 2019, 7.7},
        {9,"The Big Lebowski", "Comedy", "Joel Coen, Ethan Coen", 1998, 8.1},
        {10,"Superbad", "Comedy", "Greg Mottola", 2007, 7.6},
        {11,"Se7en", "Thriller", "David Fincher", 1995, 8.6},
        {12,"Gone Girl", "Thriller", "David Fincher", 2014, 8.1},
        {13,"The Notebook", "Romance", "Nick Cassavetes", 2004, 7.8},
        {14,"Pride and Prejudice", "Romance", "Joe Wright", 2005, 7.8},
        {15,"The Lord of the Rings: The Fellowship of the Ring", "Fantasy", "Peter Jackson", 2001, 8.8},
        {16,"Harry Potter and the Sorcerer's Stone", "Fantasy", "Chris Columbus", 2001, 7.6},
        {17,"Get Out", "Horror", "Jordan Peele", 2017, 7.7},
        {18,"A Quiet Place", "Horror", "John Krasinski", 2018, 7.5},
        {19,"The Secret Life of Walter Mitty", "Adventure", "Ben Stiller", 2013, 7.3},
        {20,"Into the Wild", "Adventure", "Sean Penn", 2007, 8.1}
    };
    int choice ,num;
    do
    {
        printf("\n\n<------- Movie Management System -------->\n\n");
        printf("1. Display All movies With details\n");
        printf("2. Search for Movie (By genre)\n");
        printf("3. Add new Movie\n");
        printf("4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
            printf("\nNo.  Title                                             Genre           Director                       Year   Rating\n");
            printf("-------------------------------------------------------------------------------------------------------------------\n");
                for(int i = 0;i < k;i++)
                {
                    print(my_movies[i]);
                }
                break;
            case 2:
                printf("\nEnter Genre To search : ");
                scanf("%s",arr);
                printf("\n");
                printf("\nNo.  Title                                             Genre           Director                       Year   Rating\n");
                printf("-------------------------------------------------------------------------------------------------------------------\n");
                search(arr,my_movies,k);
                break;
            case 3:
                k++;
                my_movies[k-1].list = k ;
                fflush(stdin);
                printf("\nEnter movie Title : ");
                gets(my_movies[k-1].title);
                fflush(stdin);
                printf("\nEnter movie Genre : ");
                gets(my_movies[k-1].genre);
                fflush(stdin);
                printf("\nEnter movie Director : ");
                gets(my_movies[k-1].director);
                fflush(stdin);
                printf("\nEnter movie Year (i.e 2024) : ");
                scanf("%d",&my_movies[k-1].year);
                printf("\nEnter movie Rating(Out of 10) : ");
                scanf("%f",&my_movies[k-1].rating);
                printf("\nCongratulations! Movie Added Successfully\n");
              break;
            case 4:
                printf("\n-------------Thanks for using it------------\n");
            break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } 
    while (choice != 4);      
}
