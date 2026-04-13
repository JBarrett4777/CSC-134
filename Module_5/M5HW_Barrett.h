#ifndef M5HW_H
#define M5HW_H

#include <iostream>
using namespace std;

// List PROTOTYPES of all the choices up here
// rename these to something that makes sense!
void question_1();
void question_2();
void question_3();
void question_4();
void question_6();

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

    rainfall_average = (rainfall_1 + rainfall_2 + rainfall_3) / 3.0; //(TODO:FINISH QUESTION 1 BY ADDUING THE LAST STATEMENT)

}

void question_2() {
    
}

void question_3() {
    
}

void question_4() {
    
}

void question_5() {
    
}


#endif // M5HW_H