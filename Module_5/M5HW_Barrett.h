#ifndef M5HW_H
#define M5HW_H

#include <iostream>
#include <iomanip>
using namespace std;

// List PROTOTYPES of all the choices up here
// rename these to something that makes sense!
void question_1();
void question_2();
void question_3();
void question_4();
void question_5();

// List FULL FUNCTIONS of all the choices at the bottom
void question_1() {
    double rainfall_1, rainfall_2, rainfall_3, rainfall_average;
    string month1, month2, month3;

    cout << "Enter month: ";
    cin >> month1;
    cout << "Enter rainfall for "<< month1 << ": ";
    cin >> rainfall_1;

    cout << "Enter month: ";
    cin >> month2;
    cout << "Enter rainfall for "<< month2 << ": ";
    cin >> rainfall_2;

    cout << "Enter month: ";
    cin >> month3;
    cout << "Enter rainfall for "<< month3 << ": ";
    cin >> rainfall_3;

    rainfall_average = (rainfall_1 + rainfall_2 + rainfall_3) / 3.0; 

    cout << fixed << setprecision(2);
    cout << "The average rainfall for " << month1 << ", " << month2 << ", and " << month1 << " is " << rainfall_average << " inches";
}

void question_2() {
    double width, length, height, volume;

    cout << "Enter width: ";
    cin >> width;
    cout << "Enter length: ";
    cin >> length;
    cout << "Enter height: ";
    cin >> height;

    while ( width <=0 || length <=0 || height <=0) {
            cout << "Error: All dimensions must be greater than 0. \n";
            cout << "Enter width: ";
            cin >> width;
            cout << "Enter length: ";
            cin >> length;
            cout << "Enter height: ";
            cin >> height;
        }

    volume = width * length * height;
    cout << "The volume of the block is " << volume << endl;
}

void question_3() {
    
}

void question_4() {
    
}

void question_5() {
    
}


#endif // M5HW_H