#include "iostream"
using namespace std;
class product{
    protected:
        int productID;
        string name;
        double price;
        int stockQuantity;
    public:
        product(int id, string n, double p, int q) : productID(id), name(n), price(p), stockQuantity(q) {}
     void applyDiscount(){
        price -= price * 0.1; 
    }
     void displayProductInfo(){
        cout << "Product ID: " << productID << endl;
        cout << "Name: " << name << endl;
        cout << "Price: $" << price << endl;
        cout << "Stock Quantity: " << stockQuantity << endl;
    }
    void CalculateTotalPrice(int quantity){
        double totalPrice = price * quantity;
        cout << "Total Price for " << quantity << " units: $" << totalPrice << endl;
    }
};
class electronics: public product{
    private :
    int warrantyPeriod;
    string brand;
    public:
    electronics(int id, string n, double p, int q, int w, string b) : product(id,n,  p, q),warrantyPeriod(w),brand(b){};
    void displayProductInfo(){
        product :: displayProductInfo();
        cout << "Warranty Period : " << warrantyPeriod << endl;
        cout << "Brand : " << brand << endl;
    }

};
class clothing : public product{
    private:
        string size;
        string color;
        string fabricMaterial;
    public:
        clothing(int id, string n, double p, int q, string s, string c, string f) : product(id, n, p, q), size(s), color(c), fabricMaterial(f) {}
    void applyDiscount(){
        double seasonalDiscount = 0.15;
        price -= price * seasonalDiscount;
    }
};
class foodItem: public product{
    private :
    string expirationDate;
    int calories;
    public:
    foodItem(int id, string n, double p, int q, string e, int c) : product(id,n,p,q), expirationDate(e), calories(c){};
    void CalculateTotalPrice(int quantity){
        double totalPrice = price * quantity;
        if (quantity > 10) {
            totalPrice -= totalPrice * 0.05; 
        }
        cout << "Total Price for " << quantity << " units: $" << totalPrice << endl;
    }
};
int main(){
    electronics e1(101, "Laptop", 1200.00, 5, 2, "Dell");
    e1.displayProductInfo();
    e1.applyDiscount();
    e1.CalculateTotalPrice(3);
    cout << endl;
    clothing c1(102, "T-Shirt", 20.00, 10, "M", "Blue", "Cotton");
    c1.displayProductInfo();
    c1.applyDiscount();
    c1.CalculateTotalPrice(5);
    cout << endl;
    foodItem f1(103, "Chips", 2.50, 20, "2023-12-31", 150);
    f1.displayProductInfo();
    f1.CalculateTotalPrice(12); // Assuming the CalculateTotalPrice method is defined in the foodItem class
    cout << endl;

}
    