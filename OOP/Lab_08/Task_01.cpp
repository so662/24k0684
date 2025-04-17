#include "iostream"
#include "cmath"
using namespace std;
class complex
{
    double real;
    double imag;

public:
    complex(double r = 0, double i = 0) : real(r), imag(i) {}
    complex operator+(complex &c1)
    {
        return complex(real + c1.real, imag + c1.imag);
    }
    complex operator-(complex &c1)
    {
        return complex(real - c1.real, imag - c1.imag);
    }
    complex operator*(complex &c1)
    {
        return complex(real * c1.real - imag * c1.imag, real * c1.imag + imag * c1.real);
    }
    complex operator/(complex &c1)
    {
        double denominator = c1.real * c1.real + c1.imag * c1.imag;
        return complex((real * c1.real + imag * c1.imag) / denominator, (imag * c1.real - real * c1.imag) / denominator);
    }
    complex operator<<(complex &c1)
    {
        if (imag < 0)
        {
            imag = imag * -1;
            cout << real << " - " << imag << "i" << endl;
        }
        else
            cout << real << " + " << imag << "i" << endl;
        return complex(real, imag);
    }
    friend void magnitude(complex &c1);
};
void magnitude(complex &c1)
{
    double mag = sqrt(c1.real * c1.real + c1.imag * c1.imag);
    cout << "Magnitude: " << mag << endl;
};

int main()
{
    complex c1(3, 4), c2(1, 2);
    complex c3 = c1 + c2;
    cout << "Addition: " << endl;
    c3 << c1;
    complex c4 = c1 - c2;
    cout << "Subtraction: " << endl;
    c4 << c1;
    complex c5 = c1 * c2;
    cout << "Multiplication: " << endl;
    c5 << c1;
    complex c6 = c1 / c2;
    cout << "Division: " << endl;
    c6 << c1;
    magnitude(c1);
    return 0;
}