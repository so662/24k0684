#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age;
    string contactNumber;
    string address;

public:
    Person(string name, int age, string contactNumber, string address) 
        : name(name), age(age), contactNumber(contactNumber), address(address) {}

    void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Contact Number: " << contactNumber << endl;
        if (!address.empty()) {
            cout << "Address: " << address << endl;
        }
    }

    void updateInfo(string n, int a, string c, string add) {
        name = n;
        age = a;
        contactNumber = c;
        address = add;
    }
};

class Patient : public Person {
private:
    int patientID;
    string medicalHistory;
    string doctorAssigned;

public:
    Patient(string name, int age, string contactNumber, int patientID, string medicalHistory, string doctorAssigned, string address = "") 
        : Person(name, age, contactNumber, address), patientID(patientID), medicalHistory(medicalHistory), doctorAssigned(doctorAssigned) {}

    void displayInfo() {
        Person::displayInfo();
        cout << "Patient ID: " << patientID << endl;
        cout << "Medical History: " << medicalHistory << endl;
        cout << "Doctor Assigned: " << doctorAssigned << endl;
    }
};

class Doctor : public Person {
private:
    string specialization;
    double consultationFee;
    string patientsList[10];
    int numPatients;

public:
    Doctor(string name, int age, string contactNumber, string specialization, double consultationFee, string address ) 
        : Person(name, age, contactNumber, address), specialization(specialization), consultationFee(consultationFee), numPatients(0) {}
    void addPatient(string patientName) {
        if (numPatients < 10) {
            patientsList[numPatients++] = patientName;
        } else {
            cout << "Cannot add more patients for " << name << endl;
        }
    }
    void displayInfo() {
        Person::displayInfo();
        cout << "Specialization: " << specialization << endl;
        cout << "Consultation Fee: $" << consultationFee << endl;
        cout << "Patients List: ";
        for (int i = 0; i < numPatients; i++) {
            cout << patientsList[i];
            if (i < numPatients - 1) {
                cout << ", ";
            }
        }
        cout << endl;
    }
};

class Nurse : public Person {
private:
    string assignedWard;
    string shiftTimings;

public:
    Nurse(string name, int age, string contactNumber, string assignedWard, string shiftTimings, string address ) 
        : Person(name, age, contactNumber, address), assignedWard(assignedWard), shiftTimings(shiftTimings) {}

    void displayInfo() {
        Person::displayInfo();
        cout << "Assigned Ward: " << assignedWard << endl;
        cout << "Shift Timings: " << shiftTimings << endl;
    }
};

class Administrator : public Person {
private:
    string department;
    double salary;

public:
    Administrator(string name, int age, string contactNumber, string department, double salary, string address) 
        : Person(name, age, contactNumber, address), department(department), salary(salary) {}

    void updateInfo(string name, int age, string contactNumber, string d, double s, string address ) {
        Person::updateInfo(name, age, contactNumber, address);
        department = d;
        salary = s;
    }
};

int main() {
    Patient patient1("Hamza Ahmed", 28, "123-456-7890", 101, "Asthma", "Dr. Soofiyan Ali", "123 Main St"); 
    Doctor doctor1("Dr. Soofiyan Ali", 50, "987-654-3210", "Pulmonology", 250.0, "456 Elm St"); 
    Nurse nurse1("Ali Khan", 32, "555-123-4567", "Ward B", "Night Shift", "789 Oak St"); 
    Administrator admin1("Ahmed Raza", 45, "444-555-6666", "Finance", 6000.0, "321 Pine St"); 
    doctor1.addPatient("Hamza Ahmed"); 
    cout << "Patient Info:" << endl; 
    patient1.displayInfo(); 
    patient1.updateInfo("Hamza Ahmed", 29, "123-456-7890","123 Main St");
    cout << endl;
    cout << "Updated Patient Info:" << endl;
    patient1.displayInfo();
    cout << endl; 
    cout << "Doctor Info:" << endl; 
    doctor1.displayInfo(); 
    doctor1.addPatient("Ali Khan");
    doctor1.addPatient("Ahmed Raza");
    cout << endl;
    cout << "Updated Doctor Info:" << endl;
    doctor1.updateInfo("Dr. Soofiyan Ali", 52, "987-654-3210","456 Elm St");
    doctor1.displayInfo();
    cout << endl; 
    cout << "Nurse Info:" << endl; 
    nurse1.displayInfo(); 
    nurse1.updateInfo("Ali Khan", 35, "555-123-4567","789 Oak St");
    cout << endl;
    cout << "Updated Nurse Info:" << endl;
    nurse1.displayInfo();
    cout << endl; 
    cout << "Administrator Info:" << endl; 
    admin1.displayInfo(); 
    admin1.updateInfo("Tariqa ", 50 ,"444-555-6666","Psycology ",6000.0,"321 Pine St");
    cout << endl;
    cout << "Updated Administrator Info:" << endl;
    admin1.displayInfo();
    cout << endl; 
    return 0;
}