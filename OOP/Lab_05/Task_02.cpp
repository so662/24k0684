#include "iostream"
using namespace std;
class Student {
    private:
        int Id;
        string name;
        int* marks;
        int numMarks;
    public:
        Student(int Id, string name, int* newmarks, int numMarks) : Id(Id), name(name), numMarks(numMarks) {
            marks = new int[numMarks];
            for (int i = 0; i < numMarks; i++) {
                marks[i] = newmarks[i];
            }
        }
        Student(const Student& s) {
            Id = s.Id;
            name = s.name;
            numMarks = s.numMarks;
            marks = new int[numMarks];
            for (int i = 0; i < numMarks; i++) {
                marks[i] = s.marks[i];
            }
        }
        ~Student() {
            delete[] marks;
        }
        void print()  {
            cout << "Student ID: " << Id << endl;
            cout << "Name: " << name << endl;
            cout << "Course Marks: ";
            for (int i = 0; i < numMarks; i++) {
                cout << marks[i] << " ";
            }
            cout << "| Address: " << marks << endl;
        }
};
int main() {
    int marks1[] = {100, 95, 90};
    int marks2[] = {85, 80, 75};
    Student s1(1, "John Doe", marks1, 3);
    Student s2 = s1;
    Student s3(2, "Jane Doe", marks2, 3);
    s1.print();
    s2.print();
    s3.print();
    return 0;
}