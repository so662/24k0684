#include <iostream>
#include <sstream>
#include <exception>
using namespace std;

class DimensionMismatchException : public std::exception {
    string msg;
public:
stringstream ss;
    DimensionMismatchException(int r1, int c1, int r2, int c2) {
        
        ss<< "DimensionMismatchException - Matrices must have same dimensions";
    
    msg = ss.str();
    }
    void what()  { cout << msg << endl; }
};

template<typename T>
class Matrix {
    int rows, cols;
    T** data;
public:
    Matrix(int r, int c) : rows(r), cols(c) {
        data = new T*[rows];
        for(int i=0; i<rows; ++i)
            data[i] = new T[cols];
    }
    ~Matrix() {
        for(int i=0; i<rows; ++i) delete[] data[i];
        delete[] data;
    }
    void input() {
        for(int i=0; i<rows; ++i)
            for(int j=0; j<cols; ++j)
                cin >> data[i][j];
    }
    Matrix<T> operator+(const Matrix<T>& other) const {
        if(rows != other.rows || cols != other.cols)
            throw DimensionMismatchException(rows, cols, other.rows, other.cols);
        Matrix<T> result(rows, cols);
        for(int i=0; i<rows; ++i)
            for(int j=0; j<cols; ++j)
                result.data[i][j] = data[i][j] + other.data[i][j];
        return result;
    }
    void print() const {
        for(int i=0; i<rows; ++i) {
            for(int j=0; j<cols; ++j)
                cout << data[i][j] << " ";
            cout << endl;
        }
    }
};

int main() {
    try {
        int r1, c1, r2, c2;
        cout << "Enter rows and cols for Matrix A: ";
        cin >> r1 >> c1;
        Matrix<int> A(r1, c1);
        A.input();

        cout << "Enter rows and cols for Matrix B: ";
        cin >> r2 >> c2;
        Matrix<int> B(r2, c2);
        B.input();

        Matrix<int> C = A + B;
        cout << "A + B =\n";
        C.print();
    } catch( DimensionMismatchException& ex) {
        ex.what();
    }
    return 0;
}