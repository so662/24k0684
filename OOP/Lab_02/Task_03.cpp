#include <iostream>
#include <string>
using namespace std;
struct Employee
{
    string name;
    double hours_worked;
    double hourly_rate;
};
int main()
{
    int n;

    cout << "Enter Number of Employees : ";
    cin >> n;
    double total_salary[n];
    Employee *emp = new Employee[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter employee name : ";
        cin >> emp[i].name;
        cout << "Enter employee hours worked : ";
        cin >> emp[i].hours_worked;
        cout << "Enter employee hourly rate : ";
        cin >> emp[i].hourly_rate;
        cout << "-----------------------------------" << endl;
        total_salary[i] = emp[i].hourly_rate * emp[i].hours_worked;
    }
    cout << "EMPLOYEE DETAILS " << endl;
    cout << "============================" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Employee name : " << emp[i].name << endl;
        cout << "Employee hours worked : " << emp[i].hours_worked << endl;
        cout << "Employee hourly rate : " << emp[i].hourly_rate << endl;
        cout << "Total Salary : " << total_salary[i] << endl;
        cout << "---------------------------------------" << endl;
    }
}
