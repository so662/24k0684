#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream file("sensor_log.txt");
    
    file << "Sensor 1: 25.5 C\n";
    cout << "Write position after first line: " << file.tellp() << endl;

    file << "Sensor 2: 98.1 %RH\n";
    cout << "Write position after second line: " << file.tellp() << endl;

    file.close();
    return 0;
}
