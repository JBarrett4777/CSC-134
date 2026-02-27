// CSC 134
// M3HW1 - Gold
// Janiya Barrett
// 2/18/26

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

// Programs
void question1();
void question2();
void question3();
void question4();

int main() {
    int choice;
    // Main starts here
    cout << "--- M2HW1 MENU ---" << endl;
    cout << "1. Question One" << endl;
    cout << "2. Question Two" << endl;
    cout << "3. Question Three" << endl;
    cout << "4. Question Four" << endl;
    cout << "------------------" << endl;
    cout << "Select an option: "; // The prompt for the user to type
    cin >> choice;

    if (1 == choice) {
        question1();
    } 
    else if (2 == choice) {
        question2();
    } 
    else if (3 == choice) {
        question3();   
    } 
    else if (4 == choice) {
        question4();
    } 
    else {
        cout << "I didn't understand that" << endl;
    }

    return 0;
}

// List of ALL functions of all the choices at the bottom
void question1(){
    string answer;

    // Introduction and get user input
    cout << "Hello. I’m a C++ programmer!" << endl;
    cout << "Do you like me? Please type yes or no. " << endl; 
    cin >> answer;

    //Functions (If/else statements)
    if (answer == "yes") {
        cout << "That's great! I'm sure we'll get along. " << endl;
    }
    else if (answer == "no") {
        cout << "Well, maybe you'll learn to like me later" << endl;
    }
    else {
        cout << "If you're not sure... that's OK. " << endl;
    }
}
void question2(){
    // Variables
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
    cout << "YOUR ORDER" << endl << "\n------------------\n" << endl; 
    cout << "Meal Price: $" << meal_price << endl;
    cout << "Tax (7%):   $" << tax << endl;
    cout << "Tip (15%):  $" << tip << endl;
    cout << "-------------------\n";
    cout << "Total:      $" << total << endl;

}
void question3(){

}
void question4(){

}