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

    // Part 2 -- Get the input (STOPPED RIGHT HERE)
    cout << "Enter crate length: ";
    cin >> length;

    cout << "Enter crate width: ";
    cin >> width;

    cout << "Enter crate height: ";
    cin >> height;

    double volume = length * width * height;
    double cost = volume * COST_PER_CUBIC_FOOT;
    double charge = volume * CHARGE_PER_CUBIC_FOOT;
    double profit = charge - cost;

    cout << fixed << setprecision(2);
    cout << "\n--- Crate Report ---\n";
    cout << "Volume: " << volume << " cubic feet\n";
    cout << "Cost: $" << cost << endl;
    cout << "Charge: $" << charge << endl;
    cout << "Profit: $" << profit << endl;

    return 0;
}
