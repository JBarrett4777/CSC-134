/*
CSC 134
M2HW1 - Gold (Q1)
Janiya Barrett
2/9/26
*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    string name;
    double startingBalance, deposit, withdrawal;

    cout << "Enter your full name: ";
    getline(cin, name);   // allows spaces

    cout << "Enter starting account balance: ";
    cin >> startingBalance;

    cout << "Enter deposit amount: ";
    cin >> deposit;

    cout << "Enter withdrawal amount: ";
    cin >> withdrawal;

    // Generate an account number (simple example)
    int accountNumber = 123456;

    double finalBalance = startingBalance + deposit - withdrawal;

    cout << fixed << setprecision(2);
    cout << "\n--- Account Summary ---\n";
    cout << "Name on account: " << name << endl;
    cout << "Account number: " << accountNumber << endl;
    cout << "Final balance: $" << finalBalance << endl;

    return 0;
}
