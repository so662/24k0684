#include "iostream"
#include "iomanip"
using namespace std;
void input (int*** ptr ,int n,int m , int o)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < o; k++)
            {
                cout << "Enter element [" << i << "][" << j << "][" << k << "] : ";
                cin >> ptr[i][j][k];
            }
        }
    }
}
void display(int*** ptr ,int n,int m , int o)
{
    cout << "The 3D array is : " << endl;
    for (int i = 0 ; i < n ; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < o; k++)
            {
                cout << setw(3) << ptr[i][j][k] << "  ";

            }
         cout << "\n";   
        }
    cout << "\n";    
    }
}

int main()
{
    int n,m,o;
    cout << "Enter number of rows for 3D array : ";
    cin >> n;
    cout << "Enter number of columns for 3D array: ";
    cin >> m;
    cout << "Enter number of depth for 3D array: ";
    cin >> o;
    int ***ptr = new int**[n];
    for (int i = 0; i < n; i++)
    {
        ptr[i] = new int*[m];
        for (int j = 0; j < m; j++)
        {
            ptr[i][j] = new int[o];
        }
    }
    input(ptr,n,m,o);
    display(ptr,n,m,o);
    for (int i = 0; i < n; i++)
    {
        for (int j =  0; j < m; j++)
        {
            delete[] ptr[i][j];
        }
        delete[] ptr[i];
    }
    delete[] ptr;
    cout << "Memory is freed" << endl;
    display(ptr,n,m,o);   
}