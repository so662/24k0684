#include <iostream>
using namespace std;
class Car{
    private : 
    string brand;
    string model;
    float rental_price;
    bool status ;
    float* revenue;
    public :
    Car (string b = "unknown",string m = "generic",float rp = 0.0,float* revenue = new float(0.0)) : brand(b), model(m), rental_price(rp), status(false){}
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
    void total_revenue_generated(int days)
    {
        if (status == false)
            cout << "Car is not rented yet" << endl;
        else
        {
            revenue = new float(rental_price * days);
            cout << "Total revenue generated : " << *revenue << endl;
        }
    }
    void display(){
        cout << "-----------------------------------" << endl;
        cout << "Car details : " << endl;
        cout << "Brand : " << brand << endl;
        cout << "Model : " << model << endl;
        cout << "Rental price : " << rental_price << endl;
        cout << "Status : " << status << endl;
        cout << "Discounted price : " << rental_price << endl;
        cout << "Revenue : " << *revenue << endl;
        
    }
};
int main()
{
    Car c1;
    c1.display();
    string brand = "toyota", model = "Nissan";
    float rental_price = 10.5;
    Car c(brand,model,rental_price);
    c.display();
    c.rental_request();
    c.total_revenue_generated(6);
    c.display();
    c.applydiscount(6);
    c.display();
    c.total_revenue_generated(6);
    c.display();
}   
    
        