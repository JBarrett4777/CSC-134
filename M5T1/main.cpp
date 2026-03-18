#include <iostream>

using namespace std;

// M5T1, Simple Functions
// Janiya Barrett
// 3/18/26

//Declare our functions
void say_hello();               // no arguments, no return
int get_answer();               // no arguments, returns int
int double_a_num(int number);   // int arguments , returns int

// Write Main()
int main()
{
    say_hello();
    cout << "The answer is: " << get_answer() << endl;
    int num = 8;
    cout << "Number is:  " << num << endl;
    int answer = double_a_num(num);
    cout << "Double that number is:  " << answer << endl;
    return 0;
}


// Define our functions (full code goes here)

void say_hello(){
    cout << "Hello World!" << endl;
}

int get_answer() {
    return 42;
}

int double_a_num(int number){
    int answer = number * 2;
    return answer;
}
