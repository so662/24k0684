#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct InventoryItem {
    int itemID;
    char itemName[20];
};

int main() {
    InventoryItem item1;
    item1.itemID = 101;
    strcpy(item1.itemName, "abcdefghijklmnopqrs");

    ofstream outFile("inventory.dat", ios::binary);
    outFile.write((char*)&item1, sizeof(InventoryItem));
    outFile.close();

    InventoryItem item2;
    ifstream inFile("inventory.dat", ios::binary);
    inFile.read((char*)&item2, sizeof(InventoryItem));
    inFile.close();

    cout << "Loaded Item ID: " << item2.itemID << endl;
    cout << "Loaded Item Name: " << item2.itemName << endl;

    return 0;
}
