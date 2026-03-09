// CSC 134
// M4LAB1
// Janiya Barrett
// 3/9/26

#include <iostream>
using namespace std;

int main(){
    // Variables
    int height, width;

    // Ask user the width and height
    cout << "Enter the height: ";
    cin >> height;
    cout << "Enter the width: ";
    cin >> width;

   for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
        cout << "* ";
    }
    cout << endl;
}

    return 0;
}