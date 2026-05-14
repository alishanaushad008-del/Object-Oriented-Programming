#include <iostream>
using namespace std;

class Account {
protected:
    double balance;

public:
    
    Account() {
        cout << "Enter initial balance: ";
        cin >> balance;
    }

   
    Account(double b) {
        balance = b;
    }

   
    virtual void deposit(double amount) {
        balance += amount;
    }

    virtual void withdraw(double amount) {
        if (amount <= balance)
            balance -= amount;
        else
            cout << "Insufficient balance\n";
    }

    void checkBalance() const {
        cout << "Current Balance: Rs. " << balance << endl;
    }
};

class InterestAccount : virtual public Account {
protected:
    double interest;

public:
    InterestAccount() : Account() {
        char choice;
        cout << "Do you want to enter a custom interest rate? (y/n) [Default is 0.30]: ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            cout << "Enter interest rate (e.g., 0.30 for 30%): ";
            cin >> interest;
        } else {
            interest = 0.30;
        }
    }

    InterestAccount(double b, double i = 0.30) : Account(b) {
        interest = i;
    }

    void deposit(double amount) override {
        balance += amount + (amount * interest);
        cout << "Deposited Rs. " << amount << " with interest applied.\n";
    }
};

class ChargingAccount : virtual public Account {
protected:
    double fee;

public:
    ChargingAccount() : Account() {
        char choice;
        cout << "Do you want to enter a custom withdrawal fee? (y/n) [Default is Rs. 25]: ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            cout << "Enter withdrawal fee: ";
            cin >> fee;
        } else {
            fee = 25.0;
        }
    }

    ChargingAccount(double b, double f = 25.0) : Account(b) {
        fee = f;
    }

   
    void withdraw(double amount) override {
        double total = amount + fee;
        if (total <= balance) {
            balance -= total;
            cout << "Withdrew Rs. " << amount << " (Fee applied: Rs. " << fee << ").\n";
        } else {
            cout << "Insufficient balance to cover amount + fee.\n";
        }
    }
};

class ACI : public InterestAccount, public ChargingAccount {
public:

    ACI() : Account(), InterestAccount(), ChargingAccount() {}

    ACI(double b)
        : Account(b), InterestAccount(b), ChargingAccount(b) {}

   
    void transfer(double amount, Account &acc) {
        if (amount <= balance) {
            balance -= amount; 
            acc.deposit(amount);
            cout << "Successfully transferred Rs. " << amount << " to Account.\n";
        } else {
            cout << "Transfer failed: Insufficient balance\n";
        }
    }

    void transfer(double amount, InterestAccount &acc) {
        if (amount <= balance) {
            balance -= amount;
            acc.deposit(amount);
            cout << "Successfully transferred Rs. " << amount << " to Interest Account.\n";
        } else {
            cout << "Transfer failed: Insufficient balance\n";
        }
    }

    void transfer(double amount, ChargingAccount &acc) {
        if (amount <= balance) {
            balance -= amount;
            acc.deposit(amount);
            cout << "Successfully transferred Rs. " << amount << " to Charging Account.\n";
        } else {
            cout << "Transfer failed: Insufficient balance\n";
        }
    }
};

int main() {
    cout << "--- Initializing Accounts ---\n";
    ACI a1(1000);
    InterestAccount ia(500);
    ChargingAccount ca(700);

    cout << "\n--- Testing ACI Functionality ---\n";
    a1.checkBalance();
    
  
    a1.deposit(200); 
    a1.checkBalance();

    a1.withdraw(100); 
    a1.checkBalance();

    cout << "Testing Transfers";
    a1.transfer(200, ia);
    cout << "ACI "; a1.checkBalance();
    cout << "IA "; ia.checkBalance();

    a1.transfer(150, ca);
    cout << "ACI "; a1.checkBalance();
    cout << "CA "; ca.checkBalance();

    return 0;
}