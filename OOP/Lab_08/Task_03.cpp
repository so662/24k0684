#include "iostream"
using namespace std;
class Vector{
    int x, y;
    public:
    Vector(int a, int b): x(a), y(b){};
    Vector operator + (Vector &v){
        return Vector(x + v.x, y + v.y);
    }
    Vector operator - (Vector &v){
        return Vector(x - v.x, y - v.y);
    }
    Vector operator * (int scalar){
        return Vector(x * scalar, y * scalar);
    }
    friend void dotProduct(Vector &v1, Vector &v2);
    void operator << (Vector &v){
        cout << "(" << v.x << ", " << v.y << ")" << endl;
    }
};
void dotProduct(Vector &v1, Vector &v2){
    int result = (v1.x * v2.x) + (v1.y * v2.y);
    cout << "Dot Product: " << result << endl;
}
int main()
{
    Vector v1(3, 4), v2(1, 2);
    Vector v3 = v1 + v2;
    Vector v4 = v1 - v2;
    Vector v5 = v1 * 5;
    cout << "Vector 1: ";
    v1 << v1;
    cout << "Vector 2: ";
    v2 << v2;
    cout << "Vector 3 (v1 + v2): ";
    v3 << v3;
    cout << "Vector 4 (v1 - v2): ";
    v4 << v4;
    cout << "Vector 5 (v1 * 5): ";
    v5 << v5;
    dotProduct(v1, v2);
    return 0;
}