// CSC 134
// M5LAB1
// Janiya Barrett
// 3/25/26 


#include <iostream>
#include "M5Lab1_Barret.h"
using namespace std;

int main() {
    char playAgain; // Variable to store 'y' or 'n'

    do {
        int choice;
        bool validChoice = false; // To keep the menu open if they pick a wrong number

        cout << "\n--- THE FORBIDDEN SLURP JUICE (FORTNITE) ---" << endl << endl;
        cout << "As you're running to find loot, you come across a glowing blue puddle." << endl;

        // Choice Menu Loop
        while (!validChoice) {
            cout << "Do You: " << endl;
            cout << "1. Drink it" << endl;
            cout << "2. Bottle it" << endl;
            cout << "3. Throw a rock at it" << endl;
            cout << "4. Fish in it" << endl;
            cout << "> ";
            cin >> choice;

            if (choice == 1) {
                drink();
                validChoice = true;
            } else if (choice == 2) {
                bottle();
                validChoice = true;
            } else if (choice == 3) {
                rock();
                validChoice = true;
            } else if (choice == 4) {
                fish();
                validChoice = true;
            } else {
                cout << "\n[!] I didn't understand that. Try again before you get sniped!" << endl;
                // Since validChoice is still false, it loops back to the menu
            }
        }

        // Ask to play again
        cout << "\n\nWould you like to drop back into the match? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing! GG." << endl;

    return 0;
}