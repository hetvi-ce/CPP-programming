#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

string logs[100];
int logIndex = 0;

void addLog(string msg) {
    logs[logIndex++] = msg;
}

class BankAccount {
    double balance;
public:
    BankAccount(double initialBalance) : balance(initialBalance) {}

    void deposit(double amount) {
        addLog("Entered deposit()");
        if (amount <= 0) {
            addLog("Exception thrown in deposit(): invalid amount");
            throw invalid_argument("Deposit amount must be positive.");
        }
        balance += amount;
        addLog("Deposit successful. Balance: " + to_string(balance));
        addLog("Exiting deposit()");
    }

    void withdraw(double amount) {
        addLog("Entered withdraw()");
        if (amount <= 0) {
            addLog("Exception thrown in withdraw(): invalid amount");
            throw invalid_argument("Withdrawal amount must be positive.");
        }
        if (amount > balance) {
            addLog("Exception thrown in withdraw(): insufficient funds");
            throw runtime_error("Insufficient balance for withdrawal.");
        }
        balance -= amount;
        addLog("Withdrawal successful. Balance: " + to_string(balance));
        addLog("Exiting withdraw()");
    }

    double getBalance() {
        return balance;
    }
};

void processTransaction(BankAccount& account, string type, double amount) {
    addLog("Entered processTransaction()");
    if (type == "deposit") {
        account.deposit(amount);
    } else if (type == "withdraw") {
        account.withdraw(amount);
    }
    addLog("Exiting processTransaction()");
}

void runTransaction(BankAccount& account, string type, double amount) {
    addLog("Entered runTransaction()");
    try {
        processTransaction(account, type, amount);
    }
    catch (const invalid_argument& e) {
        addLog("Caught invalid_argument in runTransaction(): " + string(e.what()));
        addLog("Stack unwinding complete.");
    }
    catch (const runtime_error& e) {
        addLog("Caught runtime_error in runTransaction(): " + string(e.what()));
        addLog("Stack unwinding complete.");
    }
    addLog("Exiting runTransaction()");
}

int main() {
    BankAccount account(1000.0);
    addLog("Account created with balance: 1000.0");

    int choice;
    double amount;

    cout << "1. Deposit" << endl;
    cout << "2. Withdraw" << endl;
    cout << "Enter choice: ";
    cin >> choice;

    cout << "Enter amount: ";
    cin >> amount;

    if (choice == 1) {
        runTransaction(account, "deposit", amount);
    } else if (choice == 2) {
        runTransaction(account, "withdraw", amount);
    } else {
        cout << "Invalid choice." << endl;
    }

    cout << "\n--- Transaction Log ---" << endl;
    for (int i = 0; i < logIndex; i++) {
        cout << logs[i] << endl;
    }

    cout << "\nFinal Balance: " << account.getBalance() << endl;

    return 0;
}
