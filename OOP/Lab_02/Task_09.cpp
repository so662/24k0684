#include "iostream"
using namespace std;

struct product {
    string productID;
    string name;
    int quantity; 
    float price;  
};

void input(product* p, int i) {
    cout << "Enter the details of the product " << i + 1 << endl;
    cout << "-----------------------------------" << endl;
    cout << "Enter the product ID: ";
    cin >> p->productID;
    cout << "Enter the name of the product: ";
    cin >> p->name;
    cout << "Enter the quantity of the product: ";
    cin >> p->quantity;
    cout << "Enter the price of the product: ";
    cin >> p->price;
    cout << "-----------------------------------" << endl;
}

void display(product* p, int n) {
    cout << "The details of the products are: " << endl;
    cout << "-----------------------------------" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Product " << i + 1 << endl;
        cout << "Product ID: " << p[i].productID << endl; 
        cout << "Name: " << p[i].name << endl;
        cout << "Quantity: " << p[i].quantity << endl;
        cout << "Price: " << p[i].price << endl;
        cout << "-----------------------------------" << endl;
    }
}

float totalprice(product* p, int n) {
    float total = 0; 
    for (int i = 0; i < n; i++) {
        total += (p[i].quantity * p[i].price); 
    }
    return total;
}

int main() {
    int n;
    cout << "Enter the number of products: ";
    cin >> n;
    product* p = new product[n];

    for (int i = 0; i < n; i++) {
        input(&p[i], i);
    }
    display(p, n); 

    float total = totalprice(p, n); 
    cout << "-----------------------------------" << endl;
    cout << "The total price of the products is: " << total << endl;

    delete[] p; 
}
