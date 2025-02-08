#include "iostream"
#include "string"
#include "iomanip"
using namespace std;
void input(int **matrix1, int **matrix2, int r1, int c1, int r2, int c2)
{
    cout << "Enter the elements of the first matrix: " << endl;
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            cout << "Element [" << i << "][" << j << "]: ";
            cin >> matrix1[i][j];
        }
    }
    cout << "--------------------------------------------" << endl << endl;
    cout << "Enter the elements of the second matrix: " << endl;
    for (int i = 0; i < r2; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            cout << "Element [" << i << "][" << j << "]: ";
            cin >> matrix2[i][j];
        }
    }
}
void multiplication(int **matrix1, int **matrix2, int r1,int c1, int r2, int c2)
{
    int **result = new int *[r1];
    for (int i = 0; i < r1; i++)
    {
        result[i] = new int[c2];
    }
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < c1; k++)
            {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    cout << "=================================================" << endl << endl;
    cout << "The resultant matrix is: " << endl;
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            cout << setw(3) << result[i][j] << "|";
        }
        cout << endl;
    }
    for (int i = 0; i < r1; i++)
    {
        delete[] result[i];
    }
    delete[] result;

}
int main()
{
    int r1, c1, r2, c2;
    do
    {
        cout << "Enter the number of rows for the first matrix: ";
        cin >> r1;
        cout << "Enter the number of columns for the first matrix: ";
        cin >> c1;
        cout << "Enter the number of rows for the second matrix: ";
        cin >> r2;
        cout << "Enter the number of columns for the second matrix: ";
        cin >> c2;
        cout << "--------------------------------------------" << endl << endl;
        if (c1 != r2)
        {
            cout << "The number of columns of the first matrix must be equal to the number of rows of the second matrix." << endl;
            cout << "--------------------------------------------" << endl << endl;
            cout << "Please enter the values again." << endl;
            cout << "--------------------------------------------" << endl << endl;
        }

    } while (c1 != r2);
    int **matrix1 = new int *[r1];
    for (int i = 0; i < r1; i++)
    {
        matrix1[i] = new int[c1];
    }
    int **matrix2 = new int *[r2];
    for (int i = 0; i < r2; i++)
    {
        matrix2[i] = new int[c2];
    }
    input(matrix1, matrix2, r1, c1, r2, c2);
    multiplication(matrix1, matrix2, r1, c1, r2, c2);

    for (int i = 0; i < r1; i++)
    {
        delete[] matrix1[i];
    }
    delete[] matrix1;
    for (int i = 0; i < r2; i++)
    {
        delete[] matrix2[i];
    }
    delete[] matrix2;
    return 0;
}
