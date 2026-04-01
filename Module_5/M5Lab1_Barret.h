#ifndef M5LAB1_H
#define M5LAB1_H

#include <iostream>
using namespace std;

// List PROTOTYPES of all the choices up here
// rename these to something that makes sense!
void drink();
void bottle();
void rock();
void fish();


// List FULL FUNCTIONS of all the choices at the bottom
void drink() {
    int secondChoice;
    cout << "You decide to drink it." << endl;
    cout << "Your shields go to 100, but you start glowing so bright that players can see you from across the map." << endl; 
    cout << "You run for a bush, but an enemy is apporaching. Do you: " << endl;
    cout << "1. Hide in the bush and stay still" << endl;
    cout << "2. Build a defensive tower" << endl;
    cout << "> ";
    cin >> secondChoice;
    if (secondChoice == 1) {
        cout << "The glow shines through the leaves! They found you. GAME OVER." << endl;
    } else if (secondChoice == 2){
        cout << "You build a massive metal fort. People see you, but they can't hit you. You survive the glow!" << endl;
    } else {
        cout << "INVALID!!! You took toooo long to decide and you got sniped. GAME OVER." << endl;
    }
}

void bottle() {
    int secondChoice;
    cout << "You decide to botte it and save it for later." << endl;
    cout << "But... it turns into a stink bomb in your inventory. Gross." << endl;
    cout << "You've had this volatile stink bomb in your inventory for quite some time. Do you: " << endl;
    cout << "1. Throw it at the sweaty player (who plays with intense effort!) building nearby" << endl;
    cout << "2. Save it for the final circle" << endl;
    cout << "> ";
    cin >> secondChoice;
    if (secondChoice == 1) {
        cout << "They start coughing and fall off their build. You take their loot!" << endl;
    } else if (secondChoice == 2) {
         cout << "You accidentally activated it while trying to get rid of it. You stink yourself out of the match!" << endl;
    } else {
        cout << "INVALID!!! You took toooo long to decide and you got sniped. GAME OVER." << endl;
    }
}

void rock() {
    int secondChoice;
    cout << "You decide to throw a rock at it." << endl;
    cout << "AHH! The puddle turns into a Slurp monster and starts chasing you all around the map."; 
    cout << "It's been hours and the Slurp monster is still chasing you. Do you: " << endl;
    cout << "1. Lead the monster into an emeny squad" << endl;
    cout << "2. Try to tame it" << endl;
    cout << "> ";
    cin >> secondChoice;
    if (secondChoice == 1) {
        cout << "TOTAL CHAOS! The monster attacks the squad, and you slip away in the commotion!" << endl;
    } else if (secondChoice == 2) {
        cout << "IT'S A SLURP MONSTER, not a wolf! It eats your mushroom (and you sheild), then STOMPS YOU!" << endl;
    } else {
        cout << "INVALID!!! You took toooo long to decide and you got sniped. GAME OVER." << endl;
    }
}

void fish() {
    int secondChoice;
    cout << "You decide to fish in it." << endl;
    cout << "You pull out your fishing rod and cast a line into the puddle. \nInstead of a fish, you hook a Mythic Midas Flopper that turns \nyour entire inventory (including your pickaxe) into solid gold. \nYou're rich, but you're now moving WAYYYY slower because you're \nliterally carrying heavy metal.";
    cout << "You've had this volatile stink bomb in your inventory for quite some time. Do you: " << endl;
    cout << "1. Drop your gold weapons to gain speed" << endl;
    cout << "2. Use the Midas Flopper to turn a vehicle into gold" << endl;
    cout << "> ";
    cin >> secondChoice;
    if (secondChoice == 1) {
        cout << "You're fast again, but now you only have a grey pistol. You get eliminated in your next fight." << endl;
    } else if (secondChoice == 2)  {
        cout << "You created a GOLDEN WHIPLASH! It's heavy, but the engine is so powerful it doesn't matter. You drive to VICTORY!" << endl;
    } else {
        cout << "INVALID!!! You took toooo long to decide and you got sniped. GAME OVER." << endl;
    }
}


#endif // M5LAB1_H