// CSC 134
// M1LAB1 - We're selling something
// Janiya Barrett
// 1/21/2026

#include <iostream>
using namespace std;

int main() {
    // Declare my variables
    string item_name = "v-bucks";   
    int item_count = 100;       // how many we have
    double item_cost = 0.79;    // price per item
    double total_cost;          //don't know yet

    //Do the work - Welcome them to the store.
    cout  << "Welcome to the " << item_name << " store." << endl;
    cout << "We have " << item_count << " " << item_name << "." << endl;
    cout << "They cost $" << item_cost << " each." << endl;

    // Calculate the total price
    total_cost = item_count * item_cost;
    //Print the total
    cout << "To buy all of them will cost $" << total_cost << endl;

    return 0;
}