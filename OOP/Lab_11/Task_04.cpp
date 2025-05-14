// Task 4
#include <iostream>
#include <cstring>
#include <exception>
using namespace std;

class DatabaseException : public exception {
public:
    void what()  {
        cout << "A database error occurred." << endl;
    }
};
class ConnectionFailedException : public DatabaseException {};
class QueryTimeoutException : public DatabaseException {};

template<typename T>
class DatabaseConnector {
public:
    void connect(const char* dbname) {
        if (strcmp(dbname, "invalid_db") == 0)
            throw ConnectionFailedException();
        if (strcmp(dbname, "slow_db") == 0)
            throw DatabaseException();
    }
};

int main() {
    DatabaseConnector<int> db;
    try {
        cout << "Attempting to connect to invalid_db..." << endl;
        db.connect("invalid_db");
    } catch ( ConnectionFailedException& ex) {
        cout << "Caught ConnectionFailedException - what(): " ; ex.what() ;
    }
    try {
        cout << "\nAttempting to connect to slow_db..." << endl;
        db.connect("slow_db");
    } catch ( DatabaseException& ex) {
        cout << "Caught a general DatabaseException - what(): " ;ex.what() ;;
    }
    return 0;
}