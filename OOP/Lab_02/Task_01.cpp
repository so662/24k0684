#include <iostream>
#include <string>
using namespace std;

struct book
{
    string title;
    string author;
    int year;
};

void displayMenu()
{
    cout << "\n============================\n";
    cout << "          BOOK MENU         \n";
    cout << "============================\n";
    cout << "1. Add Books\n";
    cout << "2. Search Books by Year\n";
    cout << "3. View All Books\n";
    cout << "4. Exit\n";
    cout << "============================\n";
    cout << "Enter your choice: ";
}

int main()
{
    int n = 0;
    int choice;
    cout << "\nHow many books do you want to add? ";
    cin >> n;
    book *ptr = new book[n];
    do
    {

        displayMenu();
        cin >> choice;

        if (choice == 1)
        {

            for (int i = 0; i < n; i++)
            {
                cout << "\nEnter details for book " << i + 1 << "\n";
                cout << "Title: ";
                cin >> ptr[i].title;
                cout << "Author: ";
                cin >> ptr[i].author;
                cout << "Published Year: ";
                cin >> ptr[i].year;
                cout << "----------------------------\n";
            }
        }
        else if (choice == 2)
        {
            if (n == 0)
            {
                cout << "\nNo books available to search.\n";
            }
            else
            {
                int year;
                cout << "\nEnter the published year to search for: ";
                cin >> year;
                bool found = false;
                cout << "\nBooks published after " << year << ":\n";
                cout << "--------------------------------------\n";
                for (int i = 0; i < n; i++)
                {
                    if (ptr[i].year > year)
                    {
                        cout << "Title: " << ptr[i].title << " | "
                             << "Author: " << ptr[i].author << " | "
                             << "Year: " << ptr[i].year << "\n";
                        found = true;
                    }
                }
                if (!found)
                {
                    cout << "No books found published after " << year << ".\n";
                }
            }
        }
        else if (choice == 3)
        {
            if (n == 0)
            {
                cout << "\nNo books available.\n";
            }
            else
            {
                cout << "\nComplete Book List:\n";
                cout << "========================================\n";
                for (int i = 0; i < n; i++)
                {
                    cout << "Book " << i + 1 << "\n";
                    cout << "Title: " << ptr[i].title << "\n";
                    cout << "Author: " << ptr[i].author << "\n";
                    cout << "Year: " << ptr[i].year << "\n";
                    cout << "--------------------------------------\n";
                }
            }
        }
        else if (choice == 4)
        {
            cout << "\nThank you for using the Book Management System!\n";
        }
        else
        {
            cout << "\nInvalid choice! Please enter a number between 1 and 4.\n";
        }
    } while (choice != 4);

    delete[] ptr;
    return 0;
}