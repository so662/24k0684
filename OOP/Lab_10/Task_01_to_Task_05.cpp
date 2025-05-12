#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    ifstream file("vehicles.txt");

    if (!file.is_open()) {
        cout << "Error: Could not open the file." << endl;
        return 1;
    }

    string line;

    while (getline(file, line)) {
        if (line.empty() || line[0] == '#') {
        } else {
            istringstream split(line);
            string type, id, name, yearStr, extraDetails, certification;

            getline(split, type, ',');
            getline(split, id, ',');
            getline(split, name, ',');
            getline(split, yearStr, ',');
            getline(split, extraDetails, ',');
            getline(split, certification, ',');

            cout << "Type: " << type << endl;
            cout << "ID: " << id << endl;
            cout << "Name: " << name << endl;
            cout << "Year in string: " << yearStr << endl;
            cout << "Extra Details: " << extraDetails << endl;
            cout << "Certification: " << certification << endl;

            int year = stoi(yearStr);
            cout << "Year in integer: " << year << endl;

            if (type == "AutonomousCar") {
                size_t colonfound = extraDetails.find(':');
                if (colonfound != string::npos) {
                    string v1 = extraDetails.substr(colonfound + 1);
                    float v2 = stof(v1);
                    cout << "Software Version: " << v2 << " for ID: " << id << endl;
                }
            } else if (type == "ElectricVehicle") {
                size_t colonfound = extraDetails.find(':');
                if (colonfound != string::npos) {
                    string batteryStr = extraDetails.substr(colonfound + 1);
                    int battery = stoi(batteryStr);
                    cout << "Battery Capacity: " << battery << " for ID: " << id <<  endl;
                }
            } else if (type == "HybridTruck") {
                size_t colonfound = extraDetails.find(':');
                size_t bracketPos = extraDetails.find('|');
                size_t batteryPos = extraDetails.find("Battery:");
                if (colonfound != string::npos && bracketPos != string::npos && batteryPos != string::npos) {
                    string cargoStr = extraDetails.substr(colonfound + 1, bracketPos - colonfound - 1);
                    string batteryStr = extraDetails.substr(batteryPos + 8);
                    int cargo = stoi(cargoStr);
                    int battery = stoi(batteryStr);
                    cout << "Cargo: " << cargo << ", Battery: " << battery << " for ID: " << id << endl;
                }
            } else {
                cout << "Unknown vehicle type: " << type << " for ID: " << id << endl;
            }

            cout << "-------------------------" << endl;
        }
    }

    file.close();
    return 0;
}
