// CSC 134
// M7T2
// Janiya Barrett
// 4/29/26


#include <iostream>
using namespace std;

int main() {

    string name = "Bob";
    string * pName = &name; // pointer, which points to the address of name

    cout << "name  = " << name << endl;
    cout << "pName  = " << pName << endl;
    cout << "*pName = " << *pName << endl;

    return 0;
}