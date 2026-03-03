// CSC 134
// M3HW1 - Gold
// Janiya Barrett
// 2/18/26

#include <iostream>
#include <iomanip>
#include <cstdlib> // for random
#include <ctime> // for time
using namespace std;

// Programs
void question1();
void question2();
void question3();
void question4();

int main() {
    int choice;
    // Main starts here
    cout << "--- M2HW1 MENU ---" << endl;
    cout << "1. Question One" << endl;
    cout << "2. Question Two" << endl;
    cout << "3. Question Three" << endl;
    cout << "4. Question Four" << endl;
    cout << "------------------" << endl;
    cout << "Select an option: "; // The prompt for the user to type
    cin >> choice;

    if (1 == choice) {
        question1();
    } 
    else if (2 == choice) {
        question2();
    } 
    else if (3 == choice) {
        question3();   
    } 
    else if (4 == choice) {
        question4();
    } 
    else {
        cout << "I didn't understand that" << endl;
    }

    return 0;
}

// All of the functions listed for the choices 
void question1(){
    string answer;

    // Introduction and get user input
    cout << "Hello. I’m a C++ programmer!" << endl;
    cout << "Do you like me? Please type yes or no. " << endl; 
    cin >> answer;

    //Functions (If/else statements)
    if (answer == "yes") {
        cout << "That's great! I'm sure we'll get along. " << endl;
    }
    else if (answer == "no") {
        cout << "Well, maybe you'll learn to like me later" << endl;
    }
    else {
        cout << "If you're not sure... that's OK. " << endl;
    }
}
void question2(){
    // Variables
    double meal_price, tax, tip, total;
    int order_type;
    const double tax_rate = 0.08;
    const double tip_rate = 0.15;

    // Ask the user for the meal price
    cout << "Please enter the price of your meal: " << endl;
    cin >> meal_price;

    // Ask whether the order is dine-in or takeout
    cout << "Please enter 1 if the order is dine in, and 2 if it is to go: " << endl;
    cin >> order_type;

    // Calculate tax
    tax = meal_price * tax_rate;

    // Add tip only if dine-in
    if (order_type == 1){
        tip = meal_price * tip_rate;
    } else {
        tip = 0;
    }
    // Calculate Total
    total = meal_price + tax + tip;

    // Print a formatter reciept with meal price, tax, maybe tip, and total
    cout << setprecision(2) << fixed;
    cout << endl;
    cout << "YOUR ORDER" << "\n------------------\n" << endl; 
    cout << "Meal Price: $" << meal_price << endl;
    cout << "Tax (7%):   $" << tax << endl;
    cout << "Tip (15%):  $" << tip << endl;
    cout << "------------------\n";
    cout << "Total:      $" << total << endl;

}
void question3() {
    void drink();
    void bottle();
    void rock();
    void fish();

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

void question4(){
    int roll();
    int seed = time(0);
    srand(seed);
    int num1, num2, total, input;
    num1 = roll();
    num2 = roll();
    total = num1 + num2;
    cout << "What is " << num1 << " + " << num2 << "? " << endl;
    cin >> input;
    if (input == total) {
        cout << "Correct!" << endl;
    }
    else {
        cout << "Incorrect." << endl;
    }
    cout << "The sum is: " << total << endl;
}

    int roll(){
    // ran() gives a large random number
    // %6 divides by 6, and keeps the remainder
    // finally, add 1 so it's 1 to 6, not 0 to 5
    int my_roll = (rand() % 6 ) + 1;
    return my_roll;
    }