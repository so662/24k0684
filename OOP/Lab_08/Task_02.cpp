#include "iostream"
using namespace std;
class Manager;
class Account{
    int accNo;
    double balance;
    public:
    Account(int a, double b): accNo(a), balance(b) {};
    friend class Manager;
    friend void transferFunds(Account &a1, Account &a2, double amount);
    };
class Manager{
    public :
    void display(Account &a){
        cout << "Account No: " << a.accNo << endl;
        cout << "Balance: " << a.balance << endl;
    }
    void deposit (Account &a, double amount){
        a.balance += amount;
        cout << "Deposited: " << amount << endl;
    }
    void withdraw (Account &a, double amount){
        if (a.balance >= amount){
            a.balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        }
        else{
            cout << "Insufficient balance" << endl;
        }
    }
};
void transferFunds(Account &a1, Account &a2, double amount){
    if (a1.balance >= amount){
        a1.balance -= amount;
        a2.balance += amount;
        cout << "Transferred: " << amount << " from Account No: " << a1.accNo << " to Account No: " << a2.accNo << endl;
    }
    else{
        cout << "Insufficient balance in Account No: " << a1.accNo << endl;
    }
}
int main(){
    Account a1(101, 5000.0), a2(102, 3000.0);
    Manager m;
    m.display(a1);
    m.display(a2);
    m.deposit(a1, 1000.0);
    m.withdraw(a2, 500.0);
    cout << "After deposit and withdrawal:" << endl;
    m.display(a1);
    m.display(a2);
    transferFunds(a1, a2, 2000.0);
    cout << "After transfer:" << endl;
    m.display(a1);
    m.display(a2);
    return 0;
}
