#include <iostream>
#include <iomanip>

#include <string>
using namespace std;

int main()
{
    int r1, r2, c1, c2;
    do
    {
        cout << "Enter rows for Matrix 1 : ";
        cin >> r1;
        cout << "Enter columns for Matrix 1 : ";
        cin >> c1;
        cout << "Enter rows for Matrix 2 : ";
        cin >> r2;
        cout << "Enter columns for Matrix 2 : ";
        cin >> c2;
    } while (r1 != r2 && c1 != c2);

    int** result1 = new int *[r1];
    for (int i = 0; i < r1; i++)
    {
        result1[i] = new int[c1];
    }
    int** result2 = new int *[r2];
    for (int i = 0; i < r2; i++)
    {
        result2[i] = new int[c2];
    }
    int** ptr1 = new int *[r1];
    for (int i = 0; i < r1; i++)
    {
        ptr1[i] = new int[c1];
    }
    int** ptr2 = new int *[r2];
    for (int i = 0; i < r2; i++)
    {
        ptr2[i] = new int[c2];
    }
    cout << "-----------------------------------" << endl;
    cout << "Enter Matrix 1 : " << endl;
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            cout << "Enter Element[" << i << "][" << j << "] : ";
            cin >> ptr1[i][j];
        }
    }
    cout << "-----------------------------------" << endl;
    cout << "Enter Matrix 2 : " << endl;
    for (int i = 0; i < r2; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            cout << "Enter Element[" << i << "][" << j << "] : ";
            cin >> ptr2[i][j];
        }
    }

    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            result1[i][j] = ptr1[i][j] + ptr2[i][j];
        }    
    }
    cout << "-----------------------------------" << endl;
    cout << "Matrix 1 : " << endl;
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            cout << setw(3) << ptr1[i][j] << " | "; 

        }
        cout << endl;
    }
    cout << "-----------------------------------" << endl;
    cout << "Matrix 2 : " << endl;
    for (int i = 0; i < r2; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            cout << setw(3) << ptr2[i][j] << " | "; 

        }
        cout << endl;
    }
    cout << "-----------------------------------" << endl;
    cout << "-----------------------------------" << endl;
    cout << "Addition Matrix : " << endl;
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            cout << setw(3) << result1[i][j] << " | ";

        }
        cout << endl;
    }
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            result2[i][j] = ptr1[i][j] - ptr2[i][j];
        }    
    }
    cout << "-----------------------------------" << endl;
    cout << "-----------------------------------" << endl;
    cout << "Subtraction Matrix(Matrix 1 - Matrix 2) : " << endl;
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            cout << setw(3) << result2[i][j] << " | "; 

        }
        cout << endl;
    }

    for (int i = 0; i < r1; i++)
    {
        delete[] ptr1[i];
    }
    delete[] ptr1;
    for (int i = 0; i < r2; i++)
    {
        delete[] ptr2[i];
    }
    delete[] ptr2;
    for (int i = 0; i < r1; i++)
    {
        delete[] result1[i];
    }
    delete[] result1;
    for (int i = 0; i < r2; i++)
    {
        delete[] result2[i];
    }
    delete[] result2;
    return 0;

}
