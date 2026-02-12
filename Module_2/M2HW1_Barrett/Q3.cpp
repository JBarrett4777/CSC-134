/*
CSC 134
M2HW1 - Gold (Q3)
Janiya Barrett
2/9/26
*/

#include <iostream>
using namespace std;

int main() {
    // Variables
    double pizzas, pizza_slices, visitors;

    // Get input from the user
    cout << "How many pizzas did you order? ";
    cin >> pizzas;

    cout << "How many slices per pizza? ";
    cin >> pizza_slices;

    cout << "How many visitors are coming? ";
    cin >> visitors;

    // Do calculations 
    double total_slices = pizzas * pizza_slices;
    double needed_slices = visitors * 3;
    double leftover = total_slices - needed_slices;

    // Output(What the user sees)
    cout << "There are " << leftover << " slices left over." << endl;

    return 0;
}
