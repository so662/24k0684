#include "iostream"
#include "string"
using namespace std;
class Car{
    private : 
    string* brand;
    string* model;
    float* rental_price;
    bool* status ;
    public :
    Car (string b = "unknown",string m = "generic",float rp = 0.0,bool s = true)
    {
        brand = new string(b);
        model = new string(m);
        rental_price = new float(rp);
        status = new bool(s);
    }
    Car(Car &c)
    {
        brand = new string(*c.brand);
        model = new string(*c.model);
        rental_price = new float(*c.rental_price);
        status = new bool(*c.status);
    }
    void modify(string b,string m,float rp,bool s){
        *brand = b;
        *model = m;
        *rental_price = rp;
        *status = s;
    }
    ~Car(){
        cout << "-----------------------------------" << endl;
        cout << "object is being deleted"<< endl;
    }
    void display(){
        cout << "-----------------------------------" << endl;
        cout << "Car details : " << endl;
        cout << "Brand : " << *brand << " Address : "<< brand <<endl;
        cout << "Model : " << *model << " Address : "<< model <<endl;
        cout << "Rental price : " << *rental_price << " Address : "<< rental_price <<endl;
        cout << "Status : " << *status << " Address : "<< status <<endl;
        
    }

};
int main(){
    Car c1 ("toyota","corolla",150.0,true);
    c1.display();
    Car c2(c1);
    c2 .display();
    c1.modify("suzuki","cultus",100.0,false);
    c1.display();
    c2.display();
    return 0;
}