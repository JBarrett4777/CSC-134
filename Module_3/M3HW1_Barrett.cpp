// CSC 134
// M3HW1 - Gold
// Janiya Barrett
// 2/18/26

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int choice;

    cout << "--- M2HW1 MENU ---" << endl;
    cout << "1. Question One" << endl;
    cout << "2. Question Two" << endl;
    cout << "3. Question Three" << endl;
    cout << "4. Question Four" << endl;
    cout << "5. Exit" << endl;
    cout << "----------------------" << endl;
    cout << "Select an option: ";
    cin >> choice;

    if (choice == 1) {
        // Variables
        string answer;

        // Introduction and get user input
        cout << "Hello. I’m a C++ programmer!" << endl;
        cout << "Do you like me? Please type yes or no. " << endl; 
        cin >> answer;

        //Functions (If/else statements)
        if (answer == "yes") {
            cout << "That's great! I'm sure we'll ger along. " << endl;
        }
        else if (answer == "no") {
            cout << "Well, maybe you'll learn to like me later" << endl;
        }
        else {
            cout << "If you're not sure... that's OK. " << endl;
        }

    } 
    else if (choice == 2) {
        double meal_price, tax, tip, total;
        int order_type;
        const double TAX_RATE = 0.08;
        const double TIP_RATE = 0.15;

        // Ask the user for the meal price
        cout << "Please enter the price of your meal: " << endl;
        cin >> meal_price;

        // Ask whether the order is dine-in or takeout
        cout << "Please enter 1 if the order is dine in, and 2 if it is to go: " << endl;
        cin >> order_type;

        // Calculate tax
        tax = meal_price * TAX_RATE;

        // Add tip only if dine-in
        if (order_type == 1){
            tip = meal_price * TIP_RATE;
        }

        // Calculate Total
        total = meal_price + tax + tip;

        // Print a formatter reciept with meal price, tax, maybe tip, and total
        cout << setprecision(2) << fixed;
        cout << endl;
        cout << "YOUR ORDER" << endl << "------------------" << endl; //STOPPED HERE (FINISH ADDING RECIPT FORMAT)
    } 
    else if (choice == 3) {
        cout << "Here is question three..." << endl;
        // Put your code for Program 3 here
    } 
    else if (choice == 4) {
        cout << "Here is question four..." << endl;
        // Put your code for Program 4 here
    } 
    else if (choice == 5) {
        cout << "Goodbye!" << endl;
    } 
    else {
        cout << "Sorry, I don’t have that option!" << endl;
    }

    return 0;
}
