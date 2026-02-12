/*
CSC 134
M2HW1 - Gold (Q2)
Janiya Barrett
2/9/26
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    //Part 1 -- Declare variables
    // Constant variables
    const double COST_PER_CUBIC_FOOT = 0.3;
    const double CHARGE_PER_CUBIC_FOOT = 0.52;

    // Crate variables
    double length, width, height, volume; // All in feet

    //Money variables
    double cost, customer_price, profit; // All in $

    // Part 2 -- Get the input 
    cout << "Welcome to the Crate Program." << endl;
    cout << "Enter the create dimensions." << endl;

    cout << "What's the crate length? ";
    cin >> length;
    cout << "What's the crate width? ";
    cin >> width;
    cout << "What's the crate height? ";
    cin >> height;

    // Part 3 -- Do the Calculations
    volume = length * width * height;
    // Find the cost and the customer_price
    cost = volume * COST_PER_CUBIC_FOOT;
    customer_price = volume * CHARGE_PER_CUBIC_FOOT;
    profit = customer_price - cost;

    // Part 4 -- Print the output
    cout << setprecision(2) << fixed;
    cout << "CRATE INFO" << endl;
    cout << "Volume is " << volume << " cubic feet." << endl;
    cout << "Wholesale price is $" << cost << endl;
    cout << "Customer price is $" << customer_price << endl;
    cout << "Profit per crate: $" << profit << endl;

    return 0;
}
