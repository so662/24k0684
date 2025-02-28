#include <iostream>
using namespace std;
class Employee{
    protected: 
    string name;
    float salary;
    public : 
    Employee(string name,float salary) : name(name),salary(salary){}
    void displayDetails(){
        cout << "name : " << name << endl;
        cout << "Salary : " << salary << endl;
    }
};
class Manager : private Employee{
    protected :
    float bonus;
    public : 
    Manager(string name,float salary,float bonus) : Employee(name,salary),bonus(bonus){}
    void displayDetails()
    {
        Employee :: displayDetails();
        cout << "Bonus : " << bonus << endl;
    }
};
int main(){
    Manager m1("Soofiyan", 2000.5,20.5);
    m1.displayDetails();
}