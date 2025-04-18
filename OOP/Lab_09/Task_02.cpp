#include "iostream"
using namespace std;
class MenuItem{
    protected:
    string dishName;
    double price;
    public:
    MenuItem(string dishName ,double price): dishName(dishName),price(price){}
    virtual void ShowDetails() = 0;
    virtual void prepare() = 0;
};
class Appetizer : public MenuItem{
    public:
    Appetizer(string dishName ,double price) : MenuItem(dishName ,price) {}
    void ShowDetails(){
        cout << "dishName : " << dishName << endl;
        cout << "Price : $" << price << endl;
    }
    void prepare()
    {
        cout << "Preparing Appetizer............." << endl;
    }
};
class MainCourse : public MenuItem{
    public:
    MainCourse(string dishName ,double price) : MenuItem(dishName ,price) {}
    void ShowDetails(){
        cout << "dishName : " << dishName << endl;
        cout << "Price : $" << price << endl;
    }
    void prepare()
    {
        cout << "Preparing Maincourse............" << endl;
    }
}; 
int main(){
    Appetizer A1("xyz" , 100.0);
    A1.prepare();
    A1.ShowDetails();
    MainCourse m1("abc" , 150.0);
    m1.prepare();
    m1.ShowDetails();
}
