#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream inFile("large_log.txt", ios::in);
    if (!inFile) {
        cerr << "Error opening file!" << endl;
        return 1;
    }
    string line;

    getline(inFile, line);
    cout << "First line: " << line << endl;
    cout << "Position after first line: " << inFile.tellg() << endl;
    getline(inFile, line);
    cout << "Second line: " << line << endl;
    cout << "Position after second line: " << inFile.tellg() << endl;

    inFile.close();
    return 0;
}
