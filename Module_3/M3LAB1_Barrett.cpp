// CSC 134
// M3LAB1
// Janiya Barrett
// 2/23/26

#include <iostream>
using namespace std;

// List PROTOTYPES of all the choices up here
// rename these to something that makes sense!
void drink();
void bottle();
void rock();
void fish();

// main() goes here
int main() {

    int choice;
    // main() starts the game
    cout << "THE FORBIDDEN SLURP JUICE (FORTNITE)" << endl << endl;
    cout << "A you're running to find loot, you come across a glowing blue puddle in the middle of a road." << endl;
    cout << "Do You: " << endl; // make these into real choices!
    cout << "1. Drink it" << endl;
    cout << "2. Bottle it" << endl;
    cout << "3. Throw a rock at it" << endl;
    cout << "4. Fish in it" << endl;

    cout << "> "; // Give them a prompt to type
    cin >> choice;

    if (1 == choice) {
        drink();
    }
    else if (2 == choice) {
        bottle();
    }
    else if (3 == choice) {
        rock();
    }
    else if (4 == choice) {
        fish();
    }
    else {
        cout << "I didn't understand that" << endl;
        cout << "You took too long to decide and got sniped. GAME OVER" << endl;
    }

    return 0; // end of game
}

// List FULL FUNCTIONS of all the choices at the bottom
void drink() {
    cout << "You decide to drink it." << endl;
    cout << "Your shields go to 100, but you start glowing so bright that players can see you from across the map."; 
}

void bottle() {
    cout << "You decide to botte it and save it for later." << endl;
    cout << "But... it turns into a stink bomb in your inventory. Gross.";
}
void rock() {
    cout << "You decide to throw a rock at it." << endl;
    cout << "AHH! The puddle turns into a Slurp monster and starts chasing you all around the map."; 
}

void fish() {
    cout << "You decide to fish in it." << endl;
    cout << "You pull out your fishing rod and cast a line into the puddle. \nInstead of a fish, you hook a Mythic Midas Flopper that turns \nyour entire inventory (including your pickaxe) into solid gold. \nYou're rich, but you're now moving WAYYYY slower because you're \nliterally carrying heavy metal."; 
}
