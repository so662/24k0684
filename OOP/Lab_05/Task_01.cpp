#include <iostream>
using namespace std;
class Apartment {
    private:
        int Id;
        string address;
        string* owners_name;
    public:
        Apartment(int id, string addr, string name) : Id(id), address(addr), owners_name(new string(name)) {}
        Apartment(Apartment &a) {
            Id = a.Id;
            address = a.address;
            owners_name = a.owners_name;
        }
        void print() {
            cout << "Apartment ID: " << Id << endl;
            cout << "Address: " << address << endl;
            cout << "Owner's name: " << *owners_name << endl;
        }
};
int main() {
    string name = "John Doe";
    Apartment a1(1, "123 Main St", name);
    Apartment a2(a1);
    a1.print();
    a2.print();
    return 0;
}