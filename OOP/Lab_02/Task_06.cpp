#include <iostream>
#include <string>
using namespace std;

struct student
{
    string roll;
    string name;
    float marks1, marks2, marks3;
};

void input(student *s ,int i)
{
    cout << "-----------------------" << endl;
    cout << "Enter student " << i + 1 << " details: " << endl;
    cout << "-----------------------" << endl;
    getchar();
    cout << "Enter roll number: ";
    getline(cin, s->roll);
    cout << "Enter name: ";
    getline(cin, s->name);
    cout << "Enter marks in subject 1: ";
    cin >> s->marks1;
    cout << "Enter marks in subject 2: ";
    cin >> s->marks2;
    cout << "Enter marks in subject 3: ";
    cin >> s->marks3;
    cout << "-----------------------" << endl;
}

void Cal_avg(student *s)
{
    float avg = (s->marks1 + s->marks2 + s->marks3) / 3;
    cout << "Average marks: " << avg << endl;
}

void display(student *s)
{
    
    cout << "============================" << endl;
    cout << endl;
    cout << "Roll number: " << s->roll << endl;
    cout << "Name: " << s->name << endl;
    cout << "Marks in subject 1: " << s->marks1 << endl;
    cout << "Marks in subject 2: " << s->marks2 << endl;
    cout << "Marks in subject 3: " << s->marks3 << endl;
}

int main()
{
    int n;
    cout << "Enter the number of students: ";
    cin >> n;
    student s[n];
    for (int i = 0; i < n; i++)
    {
        input(&s[i],i);
    }
    for (int i = 0; i < n; i++)
    {
        cout << endl;
        cout << "============================" << endl;
        cout << "Student " << i + 1 << " details: " << endl;
        display(&s[i]);
        Cal_avg(&s[i]);
    }
}
