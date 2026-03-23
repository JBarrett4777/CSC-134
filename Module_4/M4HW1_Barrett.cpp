// CSC 134
// M4HW1
// Janiya Barrett
// 3/23/26 

#include <iostream>
using namespace std;

int main() {
    int firstNum = 0; // Initialize with 0

    cout << "Enter a number from 1 to 12: ";
    cin >> firstNum;

    // Check if the number is valid first
    while (firstNum < 1 || firstNum > 12) {
        cout << "Invalid. Please enter a number from 1 to 12: ";
        cin >> firstNum;
    }

    // Now run the multiplication table
    for (int i = 1; i <= 12; i++) {
        int answer = firstNum * i;
        cout << firstNum << " times " << i << " is " << answer << endl;
    }

    return 0;
}