#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class ATM {
private:
    double balance;
    string pin;
    int attempts;
    bool locked;

public:
    ATM(string p, double b) : pin(p), balance(b), attempts(0), locked(false) {}

    // Verify PIN and handle lockout
    void login(string input) {
        if (locked) throw runtime_error("Account is locked.");

        if (input == pin) {
            cout << "Login successful!";
            attempts = 0;
        } else {
            attempts++;
            if (attempts >= 3) {
                locked = true;
                throw runtime_error("Too many wrong attempts. Your account LOCKED for 24 hours");
            }
            throw invalid_argument("Wrong PIN. Attempts left only " + to_string(3 - attempts));
        }
    }

    void deposit(double amount) {
        if (amount <= 0)
        throw invalid_argument("Cannot deposit negative or zero amounts.");
        
        balance += amount;
        cout << "Deposited: " << amount <<" Rs."<< endl;
    }

    void withdraw(double amount) {
        if (amount <= 0) throw invalid_argument("Cannot withdraw negative or zero amounts.");
        if (amount > balance) throw runtime_error("Insufficient balance!");
        balance -= amount;
        cout << "Withdrew: " << amount <<" Rs."<<endl;
    }

    void showBalance() {
        cout << "Current Balance: " << balance <<" Rs." << endl;
    }

    bool isLocked() { return locked; }
};

int main() {
    ATM myBank("1234", 500.0);
    string inputPin;
    bool loggedIn = false;

    cout << "=== ATM LOGIN ===\n";
    while (!loggedIn) {
        cout << "Enter PIN: ";
        cin >> inputPin;
        try {
            myBank.login(inputPin);
            loggedIn = true;
        } catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
            if (myBank.isLocked()) return 0;
        }
    }

    int choice;
    double amount;
    do {
        cout << "\n1. Balance  2. Deposit  3. Withdraw  4. Exit\nChoice: ";
        cin >> choice;

        try {
            if (choice == 1) myBank.showBalance();
            else if (choice == 2) {
                cout << "Amount: "; cin >> amount;
                myBank.deposit(amount);
            }
            else if (choice == 3) {
                cout << "Amount: "; cin >> amount;
                myBank.withdraw(amount);
            }
        } catch (const exception& e) {
            cout << "Transaction Failed: " << e.what() << endl;
        }
    } while (choice != 4);

    cout << "Goodbye!\n";
    return 0;
}