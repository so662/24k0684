// Task 5
#include <iostream>
#include <exception>
using namespace std;

class NegativeStockException : public exception {};
class OverCapacityException : public exception {};

template<typename T>
class InventoryItem {
    T stock;
    T max_stock;
public:
    InventoryItem(T max_s) : stock(0), max_stock(max_s) {}
    void setStock(T s) {
        if (s < 0)
            throw NegativeStockException();
        if (s > max_stock)
            throw OverCapacityException();
        stock = s;
    }
};

int main() {
    InventoryItem<int> item(100);
    try {
        cout << "Attempting to set stock to -5..." << endl;
        item.setStock(-5);
    } catch (NegativeStockException& ex) {
        cout << "Caught NegativeStockException - what(): " << ex.what() << endl;
    }
    try {
        cout << "\nAttempting to set stock to 120 (max 100)..." << endl;
        item.setStock(120);
    } catch (OverCapacityException& ex) {
        cout << "Caught OverCapacityException - what(): " << ex.what() << endl;
    }
    return 0;
}