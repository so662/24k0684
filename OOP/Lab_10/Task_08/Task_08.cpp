#include <iostream>
#include <fstream>
using namespace std;

int main() {
    fstream file("config.txt", ios::out);
    file << "AAAAABBBBBCCCCC";
    file.close();

    fstream updateFile("config.txt", ios::in | ios::out);
    updateFile.seekp(5);
    updateFile << "XXXXX";
    updateFile.close();

    ifstream readFile("config.txt");
    string content;
    getline(readFile, content);
    cout << "Updated content: " << content << endl;
    readFile.close();

    return 0;
}
