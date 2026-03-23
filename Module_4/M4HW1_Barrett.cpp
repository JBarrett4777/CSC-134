// CSC 134
// M4HW1
// Janiya Barrett
// 3/23/26 

#include <iostream>
using namespace std;

int main(){
    // Declare Variables
    int firstNum, secondNum, answer;
    secondNum = 1;
    answer = firstNum * secondNum;

    // Ask for input
    cout << "Enter a number from 1 to 12: " << endl;
    cin >> firstNum;

    for (int i=1; i<= 12; i++) {
        answer = firstNum * i;
        cout << firstNum << " times " << i << " is " << answer << endl;
    }
    while (firstNum <= 12 ){
        
    }
}