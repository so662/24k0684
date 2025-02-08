#include "iostream"
#include "string"
using namespace std;

void input(string *ptr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Enter String : ";
        cin >> ptr[i];
    }
}
void display(string* ptr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "String " << i + 1 << " in array is : " << ptr[i] << endl;
    }
}
void sort(string* ptr, int n)
{
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n-1; i++)
        {
            if(ptr[i] > ptr[i + 1]) 
            {
                string temp = ptr[i];
                ptr[i] = ptr[i + 1];
                ptr[i + 1] = temp;
            }
        }
    }
}

int main()
{
    int n;
    cout << "Enter Number Of Strings : ";
    cin >> n;
    string *ptr = new string[n];
    input(ptr, n);
    display(ptr, n);
    sort(ptr, n);

    cout << "-----------------------------\n"<< "After Sorting : " << endl;
    display(ptr, n);
}