// CSCI 1300 Fall 2022
// Author: Jake Joyner
// Recitation: 202 – Christopher Ojukwu
// Homework 3 - Problem #4

#include <iostream>
using namespace std;

int main()
{
    //initialize variables
    double wifi_1;
    double wifi_2;
    double wifi_3;

//ask user for input
cout << "Enter wifi speeds over the last 3 classes:" << endl;
cin >> wifi_1;
//input validation
if (wifi_1<=0){
    cout << "Please enter a valid input." << endl;
    return 0;
}
cin >> wifi_2;
if (wifi_2<=0){
    cout << "Please enter a valid input." << endl;
    return 0;
}
cin >> wifi_3;
if (wifi_3<=0){
    cout << "Please enter a valid input." << endl;
    return 0;
}
//wifi getting faster
if (wifi_3>wifi_2 && wifi_2>wifi_1)
{ cout << "The wifi is getting faster!" << endl;
}
//wifi geting slower
else if (wifi_1>wifi_2 && wifi_2>wifi_3) {
    cout << "The wifi is getting slower!" << endl;
}
//wifi changing unpredictably
else {
    cout << "The wifi speed is changing unpredictably." << endl;

}
}