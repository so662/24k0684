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
    Car (string b = "unknown",string m = "generic",float rp = 0.0)
    {
        brand = b ;
        model = m;
        rental_price = rp;
        status = true;
        
    }
    void rental_request(){
        if (status == false )
            status = true;
        else cout << "Not Available" << endl;
    }
    void display(){
        cout << "Brand : " << brand << endl;
        cout << "Model : " << model << endl;
        cout << "Rental price : " << rental_price << endl;
        cout << "Status : " << status << endl;
        
    }

};
int main()
{
    string brand = "toyota", model = "Nissan";
    float rental_price = 10.5;
    Car c(brand,model,rental_price);
    c.rental_request();
    c.display();
}
