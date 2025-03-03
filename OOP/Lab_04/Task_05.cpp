#include <iostream>
using namespace std;

class Car {
private:
    string brand;
    string model;
    float rental_price;
    bool status;
    float* revenue;
    int carID;

public:
    Car(int id, string b = "unknown", string m = "generic", float rp = 0.0)
        : carID(id), brand(b), model(m), rental_price(rp), status(false), revenue(new float(0.0)) {}

    ~Car() {
        delete revenue;
        cout << "Car with ID " << carID << " is being deleted." << endl;
    }

    void rental_request() {
        if (!status) {
            status = true;
            cout << "Car ID " << carID << " is now rented." << endl;
        } else {
            cout << "Car ID " << carID << " is not available for rent." << endl;
        }
    }

    void apply_discount(int days) {
        if (days > 10)
            rental_price *= 0.9;
        else if (days > 5)
            rental_price *= 0.95;
    }

    void total_revenue_generated(int days) {
        if (!status) {
            cout << "Car ID " << carID << " is not rented yet." << endl;
        } else {
            *revenue = rental_price * days;
            cout << "Total revenue generated for Car ID " << carID << ": $" << *revenue << endl;
        }
    }

    void display() {
        cout << "-----------------------------------" << endl;
        cout << "Car ID: " << carID << endl;
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        cout << "Rental Price: $" << rental_price << endl;
        cout << "Status: " << (status ? "Rented" : "Available") << endl;
        cout << "Total Revenue: $" << *revenue << endl;
    }
};

int main() {
    Car c1(101);
    c1.display();

    string brand = "Toyota", model = "Nissan";
    float rental_price = 10.5;
    Car c2(102, brand, model, rental_price);
    c2.display();

    c2.rental_request();
    c2.total_revenue_generated(6);
    c2.display();

    c2.apply_discount(6);
    c2.display();

    c2.total_revenue_generated(6);
    c2.display();

    return 0;
}
