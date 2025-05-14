#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream file("data_records.txt");
    if (!file) {
        cerr << "Failed to open file." << endl;
        return 1;
    }
    string line;
    getline(file, line);
    getline(file, line);
    streampos pos = file.tellg();
    cout << "Position after second record: " << pos << endl;
    pos -= 2;
    file.seekg(pos);
    getline(file, line);
    cout << "Third record: " << line << endl;
    file.close();
    return 0;
}
