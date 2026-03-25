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


#endif // M5LAB1_H