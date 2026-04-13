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
    int num;
    cout << "Enter a number (1-10): ";
    cin >> num;

    while (num < 1 || num > 10) {
        cout << "Error: Enter a number between 1 and 10. " << endl;
        cin >> num;
    }

     cout << "The Roman numeral version of " << num << " is ";

    if (num == 1) cout << "I";
    else if (num == 2) cout << "II";
    else if (num == 3) cout << "III";
    else if (num == 4) cout << "IV";
    else if (num == 5) cout << "V";
    else if (num == 6) cout << "VI";
    else if (num == 7) cout << "VII";
    else if (num == 8) cout << "VIII";
    else if (num == 9) cout << "IX";
    else if (num == 10) cout << "X";
}



void question_4() {
    int choice;

    cout << "Geometry Calculator" << endl;
    cout << "1. Calculate the Area of a Circle" << endl;
    cout << "2. Calculate the Area of a Rectangle" << endl;
    cout << "3. Calculate the Area of a Triangle" << endl;
    cout << "4. Quit" << endl;
    cout << "Enter your choice (1-4): ";
    cin >> choice;

    while (choice < 1 || choice > 4){
        cout << "The valid choices are through 1 and 4. Try again";
        cin >> choice;
    }

    if (choice == 1) {
        double radius;
        cout << "Enter the circle's radius: ";
        cin >> radius;
        if (radius < 0) {
            cout << "The radius cannot be less than zero." << endl;
        } else {
            cout << "The area is " << 3.14159 * radius * radius << endl;
        }
    } 
    else if (choice == 2) {
        double length, width;
        cout << "Enter length: "; cin >> length;
        cout << "Enter width: "; cin >> width;
        if (length < 0 || width < 0) {
            cout << "Only enter positive values for length and width." << endl;
        } else {
            cout << "The area is " << length * width << endl;
        }
    } 
    else if (choice == 3) {
        double base, height;
        cout << "Enter base: "; cin >> base;
        cout << "Enter height: "; cin >> height;
        if (base < 0 || height < 0) {
            cout << "Only enter positive values for base and height." << endl;
        } else {
            cout << "The area is " << base * height * 0.5 << endl;
        }
    } 
    else if (choice == 4) {
        cout << "Program ending..." << endl;
    } 
}

void question_5() {
    int speed, hours;

    cout << "What is the speed of the vehicle in mph? ";
    cin >> speed;
    while (speed < 0) {
        cout << "Speed cannot be negative. Enter speed: ";
        cin >> speed;
    }

    cout << "How many hours has it traveled? ";
    cin >> hours;
    while (hours < 1) {
        cout << "Time must be atleast 1. Enter hour(s): ";
        cin >> hours;
    }

        cout << "Hour   Distance Traveled" << endl;
        cout << "--------------------------------" << endl;
        
        // Loop from 1 up to the number of hours
        for (int i = 1; i <= hours; i++) {
            int distance = speed * i;
            cout << i << "      " << distance << endl;
        }
}

#endif // M5HW_H