/*
CSC 134
M2LAB1
Janiya Barrett
1/28/26

Find volume of crate
Find cost, customer_price, and profit
Print everything out
*/ 

#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    // Part 1 -- Declare Variables
    // Coonstant variables (don't change)
    const double COST_PER_CUBIC_FOOT = 0.23;
    const double CHARGE_PER_CUBIC_FOOT = 0.5;

    //Crate variables
    double length, width, height, volume; // all in feet

    //Money variables
    double cost, customer_price, profit; // all in $

    // Part 2 -- Get the input
    cout << "Welcome to the Crate Program." << endl;
    cout << "Enter the crate dimensions." << endl;

    cout << "What's the crate length? ";
    cin >> length;
    cout << "What's the crate width? ";
    cin >> width;
    cout << "What's the crate height? ";
    cin >> height;

    // Part 3 -- Do the Calculations


    // Part 4 -- Print the output


    return 0;
}
