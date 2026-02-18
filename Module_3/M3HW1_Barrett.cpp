// CSC 134
// M3HW1 - Gold
// Janiya Barrett
// 2/18/26

#include <iostream>
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

        //Introduction
        cout << "Hello. I’m a C++ programmer!" << endl;
        cout << "Do you like me? Please type yes or no. " << endl; //(ENDED RIGHT HERE)
        // Put your code for Program 1 here
    } 
    else if (choice == 2) {
        cout << "Here is question two..." << endl;
        // Put your code for Program 2 here
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
