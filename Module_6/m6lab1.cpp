// M6LAB1
// CSC 134
// Janiya Barrett
// 4/15/26

#include <iostream>
#include <vector>
#include <algorithm>   // std::shuffle
#include <random>      // std::mt19937
#include <limits>      // std::numeric_limits

using namespace std;

// --- Function Prototypes ---
void loadMagazine(vector<char>& mag, int slime, int water);
void displayStatus(int pHP, int dHP, const vector<char>& mag);
char fireShot(vector<char>& mag);

int main() {
    // Game State
    vector<char> magazine;
    int playerHP = 3;
    int dealerHP = 3;
    bool isPlayerTurn = true;

    cout << "===============================" << endl;
    cout << "   WELCOME TO SLIME ROULETTE   " << endl;
    cout << "===============================" << endl;

    while (playerHP > 0 && dealerHP > 0) {
        // 1. Reload if the magazine is empty
        if (magazine.empty()) {
            cout << "\n[!] The magazine is empty. Reloading..." << endl;
            // Randomly determine a mix for the new round
            loadMagazine(magazine, 3, 2); 
            displayStatus(playerHP, dealerHP, magazine);
        }

        if (isPlayerTurn) {
            cout << "\n-- YOUR TURN --" << endl;
            cout << "1. Shoot Dealer" << endl;
            cout << "2. Shoot Yourself" << endl;
            cout << "Choice: ";
            
            int choice;
            while (!(cin >> choice) || (choice < 1 || choice > 2)) {
                cout << "Invalid choice. Pick 1 or 2: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            char shot = fireShot(magazine);
            cout << "\n> You pull the trigger..." << endl;
            
            if (shot == 'S') {
                cout << "> [!] SLIME! It deals damage." << endl;
                if (choice == 1) dealerHP--;
                else playerHP--;
                isPlayerTurn = false; // Turn ends on damage
            } else {
                cout << "> [.] click... it's just Water." << endl;
                if (choice == 1) {
                    isPlayerTurn = false; // Turn ends if you shot the dealer with water
                } else {
                    cout << "> Lucky! Shooting yourself with water grants an extra turn." << endl;
                    // isPlayerTurn stays true
                }
            }
        } 
        else {
            // 2. Dealer Turn (Basic AI)
            cout << "\n-- DEALER'S TURN --" << endl;
            cout << "The Dealer eyes you up..." << endl;
            
            char shot = fireShot(magazine);
            
            // Dealer logic: Always shoots player (for now)
            cout << "> The Dealer shoots at YOU..." << endl;
            
            if (shot == 'S') {
                cout << "> [!] SLIME! You take damage." << endl;
                playerHP--;
                isPlayerTurn = true;
            } else {
                cout << "> [.] click... it was Water." << endl;
                isPlayerTurn = true;
            }
        }

        // Show status after each shot
        if (playerHP > 0 && dealerHP > 0) {
            displayStatus(playerHP, dealerHP, magazine);
        }
    }

    // --- End Game ---
    cout << "\n===============================" << endl;
    if (playerHP <= 0) {
        cout << "   GAME OVER - YOU PERISHED    " << endl;
    } else {
        cout << "   VICTORY - THE DEALER FELL   " << endl;
    }
    cout << "===============================" << endl;

    return 0;
}

// --- Full Functions ---

void loadMagazine(vector<char>& mag, int slime, int water) {
    mag.clear(); 
    for (int i = 0; i < slime; i++) mag.push_back('S');
    for (int i = 0; i < water; i++) mag.push_back('W');

    random_device rd;
    mt19937 gen(rd());
    shuffle(mag.begin(), mag.end(), gen);
}

void displayStatus(int pHP, int dHP, const vector<char>& mag) {
    int s = 0, w = 0;
    for (char shell : mag) {
        if (shell == 'S') s++;
        else w++;
    }
    cout << "-------------------------------" << endl;
    cout << "HP | Player: " << pHP << "  Dealer: " << dHP << endl;
    cout << "Mag| Slime: " << s << "  Water: " << w << " (Total: " << mag.size() << ")" << endl;
    cout << "-------------------------------" << endl;
}

char fireShot(vector<char>& mag) {
    char shell = mag.back();
    mag.pop_back();
    return shell;
}