#include "iostream"
#include "string"
using namespace std;
class Patient{
    protected:
    string name;
    string id;
    public :
    Patient(string name ,string  id): name(name),id(id){}
    virtual void displayTreatment() = 0;
    virtual void CalculateCost() = 0;

};
class Inpatient: public Patient{
    public:
    Inpatient(string name ,string id): Patient(name ,id){};
    void displayTreatment(){
        cout  << "Name : " << name << " | " << "id : " <<id << endl; 
        cout <<"Cancer treatment" << endl;

    }
    void CalculateCost(){
        cout << "Calculating cost .............." << endl;
        cout << "$15000" << endl;
    }
};
class OutPatient : public Patient{
    public:
    OutPatient(string name ,string id): Patient(name ,id){};
    void displayTreatment(){
        cout  << "Name : " << name << " | " << "id : " <<id << endl; 
        cout <<"Fever treatment" << endl;
    }
    void CalculateCost(){
        cout << "Calculating cost .............." << endl;
        cout << "$150" << endl;
    }
};
int main()
{
    Inpatient I1("Ahmed", "123were");
    I1.displayTreatment();
    I1.CalculateCost();
    OutPatient O1("Soofiyan" , "123wef");
    O1.displayTreatment();
    O1.CalculateCost();

}