#include "iostream"
#include "string"
using namespace std;
class Car
{
private:
    string brand;
    string model;
    int fuelCapacity;
    int currentFuelLevel;

public:
    Car(string b = "xyz", string m = "abc", int fc = 0, int cfl = 0)
    {
        brand = b;
        model = m;
        fuelCapacity = fc;
        currentFuelLevel = cfl;
    }
    void drivingtheCar(int distance)
    {
        if (currentFuelLevel > 0)
        {

            if (distance > fuelCapacity)
            {
                cout << "Car can't be driven for " << distance << " km\n";
                cout << "Fuel tank capacity is " << fuelCapacity << " litres\n";
                cout << "Current fuel level is " << currentFuelLevel << " litres\n";
                return;
            }
            currentFuelLevel = currentFuelLevel - distance;
            cout << "Car is driven for " << distance << " km\n";
            cout << "Current fuel level is " << currentFuelLevel << " litres\n";
        }
        else
        {
            cout << "Car is out of fuel\n";
        }
    }
    void refuel(int fuel)
    {
        if (currentFuelLevel + fuel > fuelCapacity)
        {
            cout << "Fuel tank capacity is " << fuelCapacity << " litres\n";
            cout << "Car can't be refueled with " << fuel << " litres\n";
            cout << "Current fuel level is " << currentFuelLevel << " litres\n";
            return;
        }
        currentFuelLevel = currentFuelLevel + fuel;
        cout << "Car is refueled with " << fuel << " litres\n";
        cout << "Current fuel level is " << currentFuelLevel << " litres\n";
    }
    void checkFuelStatus()
    {
        cout << "Current fuel level is " << currentFuelLevel << " litres\n";
    }
    void Menu()
    {
        cout << "1. Drive the car\n";
        cout << "2. Refuel the car\n";
        cout << "3. Check fuel status\n";
        cout << "4. Exit\n";
        int choice;
        cout << "Enter choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            int distance;
            cout << "Enter distance to drive : ";
            cin >> distance;
            drivingtheCar(distance);
            break;
        case 2:
            int fuel;
            cout << "Enter fuel to refuel : ";
            cin >> fuel;
            refuel(fuel);
            break;
        case 3:
            checkFuelStatus();
            break;
        case 4:
            exit(0);
            break;
        default:
            cout << "Invalid choice\n";
            break;
        }
    }
};
int main()
{
    cout << "-----------------------------------\n";
    cout << "Enter car details\n";
    cout << "-----------------------------------\n";
    string brand;
    string model;
    int fuelCapacity;
    int currentFuelLevel;
    cout << "Enter brand : ";
    cin >> brand;
    cout << "Enter model : ";
    cin >> model;
    cout << "Enter fuel capacity : ";
    cin >> fuelCapacity;
    do
    {
        cout << "Enter current fuel level : ";
        cin >> currentFuelLevel;
        if (currentFuelLevel > fuelCapacity)
        {
            cout << "Current fuel level can't be greater than fuel capacity\n";
        }

    } while (currentFuelLevel > fuelCapacity);

    Car car(brand, model, fuelCapacity, currentFuelLevel);
    cout << "-----------------------------------\n";
    while (true)
    {
        cout << "-----------------------------------\n";
        cout << "     Car Management System\n";
        cout << "-----------------------------------\n";
        cout << "    Developed by Soofiyan Imran\n";
        cout << "-----------------------------------\n";
        car.Menu();
    }
}