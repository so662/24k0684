#include "iostream"
#include "string"
using namespace std;
class Car{
    private : 
    string brand;
    string model;
    float rental_price;
    bool status ;
    public :
    Car (string b = "unknown",string m = "generic",float rp = 0.0,bool s = true)
    {
        brand = b ;
        model = m;
        rental_price = rp;
        status = s;
        
    }
    Car(const Car &c)
    {
        brand = c.brand;
        model = c.model;
        rental_price = c.rental_price;
        status = c.status;
    }
    ~Car(){
        cout << "object is being deleted"<< endl;
    }
    void display(){
        cout << "Brand : " << brand << endl;
        cout << "Model : " << model << endl;
        cout << "Rental price : " << rental_price << endl;
        cout << "Status : " << status << endl;
        
    }

};
int main(){
    Car c1 ("toyota","corolla",150.0,true);
    c1.display();
    Car c2 = c1;
    c2 .display();
}