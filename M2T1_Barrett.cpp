/*
CSC 134
M2T1
Janiya Barrett
2/2/26
*/ 

#include <iostream>
using namespace std;

int main() {

    // Variables
    string name;        // will be entered by the user
    int num_apples;     // how many apples
    double cost_each;   // the price per apple

    // Ask the user for each value
    cout << "What's your name: ";
    cin >> name;

    cout << "How many apples are in stock? ";
    cin >> num_apples;

    cout << "What is the cost of each apple? ";
    cin >> cost_each;

    // Output after input
    cout << "Welcome to the " << name << " apple farm!" << endl;
    cout << "There are " << num_apples << " apples in stock." << endl;
    cout << "They cost $" << cost_each << " each." << endl;

    // Find out the total price
    double total_cost = num_apples * cost_each;
    cout << "The price for all of them is: $" << total_cost << endl;

    cout << endl;
    return 0; // no errors
}