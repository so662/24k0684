#include "iostream"
#include "string"
using namespace std;
class Library
{
private:
    string booklist[100] = {""};
    string borrowedbooks[100] = {""};

public:
    string availablebooks[100] = {""};
    void addbook(string bookname)
    {
        for (int i = 0; i < 100; i++)
        {
            if (booklist[i] == "")
            {
                booklist[i] = bookname;
                availablebooks[i] = bookname;
                break;
            }
        }
    }
    void borrowbook(string bookname)
    {
        bool found = false;
        for (int i = 0; i < 100; i++)
        {
            if (availablebooks[i] == bookname)
            {
                borrowedbooks[i] = bookname;
                availablebooks[i] = "";
                cout << "      Book borrowed successfully        \n";
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << "     Book not found      \n";
        }

    }
    void returnbook(string bookname)
    {
        for (int i = 0; i < 100; i++)
        {
            if (borrowedbooks[i] == bookname)
            {
                availablebooks[i] = bookname;
                borrowedbooks[i] = "";
                break;
            }
        }
    }
    void display()
    {
        cout << "-----------------------------------\n";
        cout << "Developed by Soofiyan Imran\n";
        cout << "-----------------------------------\n";
        cout << "---------Complete Book List--------\n";
        for (int i = 0, j = 1; i < 100; i++)
        {
            if (booklist[i] != "")
            {
                cout << j << " : " << booklist[i] << " " << endl;
                j++;
            }
        }
        cout << "-----------------------------------\n";
        cout << "----------Books available----------\n";
        for (int i = 0, j = 1; i < 100; i++)
        {
            if (availablebooks[i] != "")
            {
                cout << j << " : " << availablebooks[i] << " " << endl;
                j++;
            }
        }
        cout << "-----------------------------------\n";
        cout << "----------Books borrowed-----------\n";

        for (int i = 0, j = 1; i < 100; i++)
        {
            if (borrowedbooks[i] != "")
            {
                cout << j << " : " << borrowedbooks[i] << " " << endl;
                j++;
            }
        }
        cout << endl;
    }
};
int main()
{
    Library library;
    while (true)
    {
        cout << "-----------------------------------\n";
        cout << "     Library Management System\n";
        cout << "-----------------------------------\n";
        cout << "    Developed by Soofiyan Imran\n";
        cout << "-----------------------------------\n";
        cout << "1. Add book\n";
        cout << "2. Borrow book\n";
        cout << "3. Return book\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        int choice;
        string bookname;

        cout << "Enter choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter book name : ";
            getchar();
            getline(cin, bookname);
            library.addbook(bookname);
            break;
        case 2:
            cout << "---------Books available----------\n";
            for (int i = 0, j = 1; i < 100; i++)
            {
                if (library.availablebooks[i] != "")
                {
                    cout << j << " : " << library.availablebooks[i] << " " << endl;
                    j++;
                }
            }
            getchar();
            cout << "Enter book name : ";
            getline(cin, bookname);
            library.borrowbook(bookname);
            break;
        case 3:
            cout << "Enter book name : ";
            getchar();
            getline(cin, bookname);
            library.returnbook(bookname);
            break;
        case 4:
            library.display();
            break;
        case 5:
            return 0;
        default:
            cout << "Invalid choice\n";
        }
    }
}