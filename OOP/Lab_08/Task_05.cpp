#include "iostream"
using namespace std;
class MatrixHelper;
class Matrix2D{
    int r1c1, r1c2, r2c1, r2c2;
public:
    Matrix2D(int a, int b, int c, int d) : r1c1(a), r1c2(b), r2c1(c), r2c2(d) {}
    Matrix2D operator+(Matrix2D m){
        return Matrix2D(r1c1 + m.r1c1, r1c2 + m.r1c2, r2c1 + m.r2c1, r2c2 + m.r2c2);
    }
    Matrix2D operator-(Matrix2D m){
        return Matrix2D(r1c1 - m.r1c1, r1c2 - m.r1c2, r2c1 - m.r2c1, r2c2 - m.r2c2);
    }
    Matrix2D operator*(Matrix2D m){
        return Matrix2D(r1c1 * m.r1c1 + r1c2 * m.r2c1, r1c1 * m.r1c2 + r1c2 * m.r2c2, r2c1 * m.r1c1 + r2c2 * m.r2c1, r2c1 * m.r1c2 + r2c2 * m.r2c2);
    }
    void operator <<(Matrix2D m){
        cout << "[" << m.r1c1 << "   " << m.r1c2 << "]" << endl;
        cout << "[" << m.r2c1 << "   " << m.r2c2 << "]" << endl;
    } 
    friend void determinant(Matrix2D m);
    friend class MatrixHelper;
};
void determinant(Matrix2D m){
    int det = (m.r1c1 * m.r2c2) - (m.r1c2 * m.r2c1);
    cout << "Determinant: " << det << endl;
}
class MatrixHelper{
    public :
    Matrix2D update(Matrix2D &m, int a, int b, int c, int d){
        m.r1c1 = a;
        m.r1c2 = b;
        m.r2c1 = c;
        m.r2c2 = d;
        return m;
    }
};
int main(){
    Matrix2D m1(1, 2, 3, 4), m2(5, 6, 7, 8);
    MatrixHelper mh;
    cout << "Matrix 1:" << endl;
    m1 << m1;
    cout << "Matrix 2:" << endl;
    m1 << m2;
    cout << "Addition:" << endl;
    Matrix2D m3 = m1 + m2;
    m1 << m3;
    cout << "Subtraction:" << endl;
    Matrix2D m4 = m1 - m2;
    m1 << m4;
    cout << "Multiplication:" << endl;
    Matrix2D m5 = m1 * m2;
    m1 << m5;
    determinant(m5);
    mh.update(m1, 9, 10, 11, 12);
    cout << "Updated Matrix 1:" << endl;
    m1 << m1;    
}