#include <iostream>
#include <string>
using namespace std;
void task_01(string arr[], string arr2[], int j, int k)
{
    cout << "##-------------- Event 1 ----------------##" << endl;
    for (int i = 0; i < j; i++)
    {
        cout << "Enter Name " << i + 1 << " : ";
        cin >> arr[i];
    }
    cout << "##-------------- Event 2 ----------------##" << endl;
    for (int i = 0; i < k; i++)
    {
        cout << "Enter Name " << i + 1 << " : ";
        cin >> arr2[i];
    }
    return;
}
void show(string arr[], string arr2[], int j, int k)
{
    cout << "##-------------- Event 1 ----------------##" << endl;
    for (int i = 0; i < j; i++)
    {
        cout << "Name " << i + 1 << " : " << arr[i] << endl;
    }
    cout << "##-------------- Event 2 ----------------##" << endl;
    for (int i = 0; i < k; i++)
    {
        cout << "Name " << i + 1 << " : " << arr2[i] << endl;
    }
    return;
}

void task_02(string arr[], string arr2[], int j, int k)
{
    string name;
    cout << "Enter Name : ";
    cin >> name;
    for (int i = 0; i < j; i++)
    {
        if (name == arr[i])
        {
            cout << "Name found in Event 1" << endl;
            return;
        }
    }
    for (int i = 0; i < k; i++)
    {
        if (name == arr2[i])
        {
            cout << "Name found in Event 2" << endl;
            return;
        }
    }
    cout << "Not found" << endl;
    return;
}
void task_03(int j, int k)
{
    cout << "Total Donations : $" << (k + j) * 10 << endl;
}
void task_04(string arr[], string arr2[], int j, int k)
{
    cout << "##-------------- Event 1 ----------------##" << endl;
    for (int i = j - 1; i >= 0; i--)
    {
        cout << "Name " << j - 1 << " : " << arr[i] << endl;
    }
    cout << "##-------------- Event 2 ----------------##" << endl;
    for (int i = k - 1; i >= 0; i--)
    {
        cout << "Name " << k - 1 << " : " << arr2[i] << endl;
    }
    return;
}
void task_05(int j, int k)
{
    cout << "Event 1 : ";
    for (int i = 0; i < j; i++)
    {
        cout << "*";
    }
    cout << endl;
    cout << "Event 2 : ";
    for (int i = 0; i < k; i++)
    {
        cout << "*";
    }
    cout << endl;
    return;
}
int main()
{
    cout << endl
         << endl;
    int j;
    do
    {
        cout << "Enter participants for Event 1 (Max 5): ";
        cin >> j;
    } while (j > 5);
    string arr[j];
    int k;
    do
    {
        cout << "Enter participants for Event 2 (Max 5): ";
        cin >> k;

    } while (k > 5);
    string arr2[k];
    cout << endl
         << endl;
    task_01(arr, arr2, j, k);
    int opt;
    cout << endl
         << endl;
    do
    {
        cout << "##--------------- MODDED BY SOOFIYAN IMRAN ---------------##" << endl
             << "1 : Show names!" << endl
             << "2 : Search for person! " << endl
             << "3 : Total Donations" << endl
             << "4 : Display participants names in reverse order " << endl
             << "5 : Event popularity in Bar Chart " << endl
             << "6 : Exit " << endl
             << endl;
        cout << "Enter option : ";
        cin >> opt;
        cout << endl;
        if (opt == 1)
        {
            show(arr, arr2, j, k);
            cout << endl
                 << endl;
        }
        else if (opt == 2)
        {
            task_02(arr, arr2, j, k);
            cout << endl
                 << endl;
        }
        else if (opt == 3)
        {
            task_03(j, k);
            cout << endl
                 << endl;
        }
        else if (opt == 4)
        {
            task_04(arr, arr2, j, k);
            cout << endl
                 << endl;
        }
        else if (opt == 5)
        {
            task_05(j, k);
            cout << endl
                 << endl;
        }
        else if (opt == 6)
        {
            cout << "Exiting Program.........." << endl;
            cout << endl
                 << endl;
        }
        else
            cout << "Invalid Choice !" << endl;
    } while (opt != 6);
    return 0;
}