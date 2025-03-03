#include <iostream>
using namespace std;
class Car{
    private : 
    string brand;
    string model;
    float rental_price;
    bool status ;
    public :
    Car (string b = "unknown",string m = "generic",float rp = 0.0) : brand(b), model(m), rental_price(rp), status(false) {}
    void rental_request(){
        if (status == false )
            status = true;
        else cout << "Not Available for rent" << endl;
    }
    void applydiscount(int days)
    {
        if (days > 5)
            rental_price = rental_price - (rental_price * 0.05);
        else if(days > 10)
                rental_price = rental_price - (rental_price * 0.1);
    }
    void display(){
        cout << "Brand : " << brand << endl;
        cout << "Model : " << model << endl;
        cout << "Rental price : " << rental_price << endl;
        cout << "Status : " << status << endl;
        cout << "Discounted price : " << rental_price << endl;
        
    }
};
int main()
{
    string brand = "toyota", model = "Nissan";
    float rental_price = 10.5;
    Car c(brand,model,rental_price);
    c.display();
    c.rental_request();
    c.display();
    c.applydiscount(6);
    c.display();
    c.rental_request();
    c.display();
}   
    
        