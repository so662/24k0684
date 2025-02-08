#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int *arr = new int[n];

    cout << "Enter " << n << " integers:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Element " << i + 1 << ": ";
        cin >> *(arr + i);
    }

    cout << "Array elements are: ";
    for (int i = 0; i < n; i++)
    {
        cout << *(arr + i) << " ";
    }
    cout << endl;

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += *(arr + i);
    }

    cout << "Sum of the array elements: " << sum << endl;

    delete[] arr;

    return 0;
}
