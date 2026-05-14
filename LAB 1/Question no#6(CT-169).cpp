//Question no#6
#include <iostream>
using namespace std;
double savingsWithdraw(double amount, double balance)
{
    double charge = amount * 0.02;
    double tax = 0;
    if (amount > 50000)
    {
        tax = amount * 0.05;
    }
    balance = balance - amount - charge - tax;
    cout << "Account Type: Savings" << endl;
    cout << "Charge (2%): " << charge << endl;
    cout << "Tax: " << tax << endl;
    return balance;
}
double currentWithdraw(double amount, double balance)
{
    double charge = 100;
    double tax = 0;

    if (amount > 50000)
    {
        tax = amount * 0.05;
    }
    balance = balance - amount - charge - tax;

    cout << "Account Type: Current" << endl;
    cout << "Charge: " << charge << endl;
    cout << "Tax: " << tax << endl;

    return balance;
}
int main()
{
    char accountType;
    int accountNumber;
    double withdrawAmount;
    double balance = 200000;

    cout << "Enter account type (S for Savings, C for Current): ";
    cin >> accountType;
    cout << "Enter account number: ";
    cin >> accountNumber;
    cout << "Enter withdrawal amount: ";
    cin >> withdrawAmount;
    if (withdrawAmount > 100000)
    {
        cout << "You cannot withdraw more than 100000 at a time." << endl;
        return 0;
    }
    if (accountType == 'S' || accountType == 's')
    {
        balance = savingsWithdraw(withdrawAmount, balance);
    }
    else if (accountType == 'C' || accountType == 'c')
    {
        balance =
            currentWithdraw(withdrawAmount, balance);
    }
    else
    {
        cout << "Invalid account type!" << endl;
        return 0;
    }
    cout << "Remaining Balance: " << balance << endl;
    return 0;
}
