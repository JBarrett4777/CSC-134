/*
CSC 134
M2HW1 - Gold (Q1)
Janiya Barrett
2/9/26
*/

#include <iostream>
using namespace std;

int main() {
    int pizzas, slicesPerPizza, visitors;

    cout << "How many pizzas are ordered? ";
    cin >> pizzas;

    cout << "How many slices per pizza? ";
    cin >> slicesPerPizza;

    cout << "How many visitors are coming? ";
    cin >> visitors;

    int totalSlices = pizzas * slicesPerPizza;
    int slicesNeeded = visitors * 3;
    int leftovers = totalSlices - slicesNeeded;

    cout << "\nLeftover slices: " << leftovers << endl;

    return 0;
}
