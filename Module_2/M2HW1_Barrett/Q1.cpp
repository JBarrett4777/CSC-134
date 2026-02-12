/*
CSC 134
M2HW1 - Gold (Q1)
Janiya Barrett
2/9/26
*/

#include <iostream>
#include <iomanip> // for decimal places
using namespace std;

int main() {
    // Variables
    string name;
    double starting_balance, deposit, withdrawal;

    // Get input from user
    cout << "What's your name: ";
    cin >> name;

    cout << "Enter starting account balance: ";
    cin >> starting_balance;

    cout << "Enter deposit amount: ";
    cin >> deposit;

    cout << "Enter withdrawal amount: ";
    cin >> withdrawal;

    // Make account number and add final balance variable
    int account_num = 676767;
    double final_balance = starting_balance + deposit - withdrawal;
    
    // Final display (What the user sees)
    cout << setprecision(2) << fixed;
    cout << "\n--- Account Summary ---\n";
    cout << "Name on account: " << name << endl;
    cout << "Account number: " << account_num << endl;
    cout << "Final account balance: $" << final_balance << endl;

    return 0;
}
