#include <iostream>
using namespace std;
class Vehicle {
    protected:
    string brand ;
    int speed ;
    public :
    Vehicle (string brand ,int speed ) : brand(brand),speed(speed){}
    void displayDetails(){
        cout << "brand : " << brand << endl;
        cout << "speed : " << speed << endl;
    }
};
class Car : private Vehicle{
    protected :
    int seats;
    public :
    Car(string brand ,int speed ,int seats) : Vehicle ( brand , speed ),seats(seats){}
    void displayDetails(){
        Vehicle :: displayDetails();
        cout << "Seats : " << seats << endl;
    }
};
class ElectricCar : private Car{
    protected :
    int batterylife;
    public :
    ElectricCar(string brand ,int speed ,int seats,int batterylife) : Car(brand , speed ,seats),batterylife(batterylife){}
    void displayDetails(){
        Car :: displayDetails();
        cout << "Battery : " << batterylife << endl;
    }

};
int main()
{
    ElectricCar b1("xyz",23,34,56);
    b1.displayDetails();
}