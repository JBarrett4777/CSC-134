/*
CSC 134
M2HW1 - Gold (Q1)
Janiya Barrett
2/9/26
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double length, width, height;
    double costPerCubicFoot = 0.30;   // updated
    double chargePerCubicFoot = 0.52; // updated

    cout << "Enter crate length: ";
    cin >> length;

    cout << "Enter crate width: ";
    cin >> width;

    cout << "Enter crate height: ";
    cin >> height;

    double volume = length * width * height;
    double cost = volume * costPerCubicFoot;
    double charge = volume * chargePerCubicFoot;
    double profit = charge - cost;

    cout << fixed << setprecision(2);
    cout << "\n--- Crate Report ---\n";
    cout << "Volume: " << volume << " cubic feet\n";
    cout << "Cost: $" << cost << endl;
    cout << "Charge: $" << charge << endl;
    cout << "Profit: $" << profit << endl;

    return 0;
}
