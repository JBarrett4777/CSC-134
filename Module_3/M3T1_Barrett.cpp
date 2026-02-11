/*
CSC 134
M3T1 - Finding the area of two rectangles
Janiya Barrett
2/11/26
*/

#include <iostream>
using namespace std;

int main() {
    // Variables
    double length1, width1, area1;
    double length2, width2, area2;

    // Ask user for info
    cout << "What is the rectangle's length? ";
    cin >> length1;
    cout << "What is the rectangle's width? ";
    cin >> width1;

    cout << "What is the second rectangle's length? ";
    cin >> length2;
    cout << "What is the second rectangle's width? ";
    cin >> width2;


    // Do calculations
    area1 = length1 * width1;
    area2 = length2 * width2;

    // Print the answer
    cout << "Rectangle #1: " << length1 << " by " << width1 << " is area: " << area1 << endl;
    cout << "Rectangle #2: " << length2 << " by " << width2 << " is area: " << area2 << endl;

    // Which one is larger?
    if (area1 > area2) {
        cout << "The first rectangle is bigger." << endl;
    }
    if (area2 > area1) {
        cout << "The second rectangle is bigger." << endl;
    }
    if (area1 == area2) {
        cout << "They are the same size." << endl;
    }

    return 0;
}