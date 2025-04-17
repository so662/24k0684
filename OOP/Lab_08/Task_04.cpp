#include "iostream"
using namespace std;
class InventoryManager; 
class Car
{
    string model;
    double price;

public:
    Car(string m, double p) : model(m), price(p) {}
    friend class InventoryManager;
    friend void comparePrice(Car c1, Car c2);
};
class InventoryManager
{
public:
    void updateCar(Car &car, double newPrice)
    {
        car.price = newPrice;
    }
    void display(Car car)
    {
        cout << "Model: " << car.model << " | Price: $" << car.price << endl;
    }
};
void comparePrice(Car c1, Car c2)
{
    if (c1.price > c2.price)
        cout << c1.model << " is more expensive than " << c2.model << endl;
    else if (c1.price < c2.price)
        cout << c2.model << " is more expensive than " << c1.model << endl;
    else
        cout << c1.model << " and " << c2.model << " have the same price." << endl;
}
int main()
{
    InventoryManager manager;
    Car car1("Toyota", 20000);
    Car car2("Honda", 22000);
    manager.display(car1);
    manager.display(car2);
    manager.updateCar(car1, 25000);
    manager.updateCar(car2, 26000);
    cout << "After updating price:" << endl;    
    manager.display(car1);
    manager.display(car2);
    cout << "Price comparison:" << endl;    
    comparePrice(car1, car2);
    return 0;
}