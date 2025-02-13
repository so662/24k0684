
#include "iostream"
#include "string"
using namespace std;
class Wallet {
    public:
    string ownerName;
    float totalBalance;
    string transactionHistory;
    void addmoney(float amount) {
        totalBalance += amount;
        transactionHistory += "Added " + to_string(amount) + " to wallet\n";
    }
    void spendmoney(float amount) {
        if (totalBalance >= amount) {
            totalBalance -= amount;
            cout << "-----------------------------------\n";
            getchar();
            cout << "Enter purpose of spending : ";
            string purpose;
            getline(cin,purpose);
            transactionHistory += "Spent " + to_string(amount) + " from wallet for " + purpose + "\n";
        } else {
            cout << "Oh no! Insufficient funds\n";
            cout << "-----------------------------------\n";
            transactionHistory += "Insufficient balance\n";

        }
    }
    void transactionhistory() {
        cout << transactionHistory;
    }

};
void menu() {
    cout << "----Developer : Soofiyan Imran----\n";
    cout << "1. Add money\n";
    cout << "2. Spend money\n";
    cout << "3. Transaction history\n";
    cout << "4. Show balance\n";
    cout << "5. Exit\n";
}
int main() {
    Wallet wallet;
    cout << "Enter owner name : ";
    getline(cin,wallet.ownerName);
   
    wallet.totalBalance = 0;
    wallet.transactionHistory = "";

    int choice;
    float amount;
    while (true) {
        cout << "-----------------------------------\n";
        menu();
        cout << "Enter choice : ";
        cin >> choice;
        cout << "\n-----------------------------------\n";
        switch (choice) {
            case 1:
                cout << "Enter amount to add : ";
                cin >> amount;
                wallet.addmoney(amount);
                break;
            case 2:
                cout << "Enter amount to spend : ";
                cin >> amount;
                wallet.spendmoney(amount);
                break;
            case 3:
                wallet.transactionhistory();
                break;
            case 4:
                cout << "Total balance : " << wallet.totalBalance << endl;
                break;
            case 5:
                cout << "Exiting................\n";
                return 0;
            default:
                cout << "Invalid choice\n";
        }
    }
}





