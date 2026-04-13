// CSC 134
// M5LAB1
// Janiya Barrett
// 4/13/26 


#include <iostream>
#include "M5HW_Barrett.h"
using namespace std;

int main() {
    char choose_again; // Variable to store 'y' or 'n'

    do {
        int choice;
        bool validChoice = false; // To keep the menu open if they pick a wrong number

        cout << "\nWelcome to the M5HW Menu" << endl << endl;
      

        // Choice Menu Loop
        while (!validChoice) {
            cout << "What do you want to do: " << endl;
            cout << "1. Question 1" << endl;
            cout << "2. Question 2" << endl;
            cout << "3. Question 3" << endl;
            cout << "4. Question 4" << endl;
            cout << "5. Question 5" << endl;
            cout << "> ";
            cin >> choice;

            if (choice == 1) {
                question_1();
                validChoice = true;
            } 
            else if (choice == 2) {
                question_2();
                validChoice = true;
            } 
            else if (choice == 3) {
                question_3();
                validChoice = true;
            } 
            else if (choice == 4) {
                question_4();
                validChoice = true;
            } 
            else if (choice == 5) {
                question_5();
                validChoice = true;
            } 
            else {
                cout << "\n[!] I didn't understand that. Try again," << endl;
            }
        }

        cout << "\n\nWould you like to choose another question? (y/n): ";
        cin >> choose_again;

        while (choose_again != 'y' && choose_again != 'Y' && choose_again != 'n' && choose_again != 'N') {
            cout << "[!] Invalid input. Type 'y' to choose another question or 'n' to exit: ";
            cin >> choose_again;
        }

    } while (choose_again == 'y' || choose_again == 'Y');
        cout << "Goodbye!" << endl;
        return 0;
}