#include <iostream>

using namespace std;

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int** arr = new int*[size];

    for (int i = 0; i < size; i++) {
        arr[i] = new int;
        cout << "Enter value for element " << i + 1 << ": ";
        cin >> *arr[i];
    }

    cout << "\nValues stored in the dynamic array:\n";
    for (int i = 0; i < size; i++) {
        cout << "Element " << i + 1 << ": " << *arr[i] << endl;
    }

    for (int i = 0; i < size; i++) {
        delete arr[i];
    }
    delete[] arr;

    return 0;
}
