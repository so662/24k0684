
#include <iostream>
#include <exception>
using namespace std;

class InvalidTemperatureException : public exception {};

template<typename T>
T convertToFahrenheit(T celsius) {
    if (celsius < -273.15)
        throw InvalidTemperatureException();
    return celsius * 9 / 5 + 32;
}

int main() {
    try {
        cout << "Attempting to convert -300C..." << endl;
        double f = convertToFahrenheit(-300.0);
        cout << "Fahrenheit: " << f << endl;
    } catch (InvalidTemperatureException& ex) {
        cout << "Caught InvalidTemperatureException - what(): " << ex.what() << endl;
    }
    return 0;
}