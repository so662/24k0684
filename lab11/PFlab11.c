/*Tasks are as follows: Take the following structures and create functions that perform CRUD (create,
read, update delete) operations in a file or multiple files depending on the need based on your understanding.
Add a comment that exlpains your choice.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct player
{
    char name[20];
    char team[20];
};

struct bowl
{
    char type[10];
    char arm[5];
    struct player ply;
};

struct bat
{
    char type[10];
    char handed[8];
    struct bowl ply2;
};
void create_players()
{
    int n;
    FILE *ptr = fopen("Players.txt", "a+");
    if (!ptr)
        printf("ERROR OPENING FILE");
    printf("\2nEnter number of players you want to enter in the file : ");
    scanf("%d", &n);
    struct bat player[n];
    for (int i = 0; i < n; i++)
    {
        fflush(stdin);
        printf("\nEnter name of player %d : ", i + 1);
        scanf("%s", player[i].ply2.ply.name);
        fprintf(ptr, "Name : %s\n", player[i].ply2.ply.name);
        printf("Enter team of player %d : ", i + 1);
        scanf("%s", player[i].ply2.ply.team);
        fprintf(ptr, "Team : %s\n", player[i].ply2.ply.team);
        printf("Enter type of bowler %d (seemer/pacer/spinner/NA) : ", i + 1);
        scanf("%s", player[i].ply2.type);
        fprintf(ptr, "Bowler type : %s\n", player[i].ply2.type);
        printf("Enter bowling arm of player %d (Right/Left/NA) : ", i + 1);
        scanf("%s", player[i].ply2.arm);
        fprintf(ptr, "Bowling arm : %s\n", player[i].ply2.arm);
        fflush(stdin);
        printf("Enter type of batsmen %d (top order/middle order/lower order) : ", i + 1);
        gets(player[i].type);
        fprintf(ptr, "Batsmen type : %s\n", player[i].type);
        printf("Enter arm of batsmen %d (lefty/righty): ", i + 1);
        fgets(player[i].handed, 10, stdin);
        fprintf(ptr, "Batting arm : %s", player[i].handed);
    }

    fclose(ptr);
    printf("Players created and saved successfully!\n");
}
void read_players()
{
    int i = 0, j = 1;
    FILE *ptr = fopen("Players.txt", "r");
    if (!ptr)
    {
        printf("Error opening file.\n");
        return;
    }
    char arr2[100];
    printf("\n------------ Players List -----------\n\n");
    while (fgets(arr2, sizeof(arr2), ptr))
    {printf("%s", arr2);}
    printf("\n");
    fclose(ptr);
}
void delete_player()
{
    FILE *ptr = fopen("Players.txt", "r");
    FILE *temp = fopen("Temp.txt", "w");
    char arr[30], arr2[30], arr3[30] = "Name : ";
    bool found = false;
    fflush(stdin);
    printf("Enter name of the player you want to delete : ");
    gets(arr);
    strcat(arr3, arr);
    while (fgets(arr2, 30, ptr) != NULL)
    {
        arr2[strcspn(arr2, "\n")] = '\0';
        if (strcmp(arr3, arr2) == 0)
        {
            found = true;
            printf("\nFound and Deleted !\n");
            for (int i = 0; i < 5; i++)
            {
                fgets(arr2, 30, ptr);
            }
        }
        else
        {
            fprintf(temp, "%s\n", arr2);
        }
    }
    if (found == true)
    {
        fclose(ptr);
        fclose(temp);
        remove("Players.txt");
        rename("Temp.txt", "Players.txt");
    }
    else
    {
        printf("\nNot Found !\n");
        fclose(ptr);
        fclose(temp);
        remove("Temp.txt");
    }
}
int main()
{
    int choice;
    while (true)
    {
        printf("\n--- Player Management System ---\n");
        printf("1. Add Players\n");
        printf("2. Read Players\n");
        printf("3. Delete Player\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            create_players();
            break;
        case 2:
            read_players();
            break;
        case 3:
            delete_player();
            break;
        case 4:
            printf("Exiting program. Goodbye!\n");
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
}
