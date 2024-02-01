// CSCI 1300 Fall 2022
// Author: Jake Joyner
// Recitation: 202 – Christopher Ojukwu
// Homework 4 - Problem #2

#include <iostream>
#include <cmath>
using namespace std;

int main (){
    int i; //declrae variables
    int counter;
    cout << "Enter a value between 1 and 1000: " << endl; // ask user for input
    cin >> i; // user input

    while(i<=1 || i>=1000){ //input validation
        cout << "Invalid input." << endl;
        cout << "Enter a value between 1 and 1000: " << endl;
        cin >> i;
    }

    while(i>1){
       // i=1;
       cout<<i<<endl; // print sequence
        if (i%2==0){
            i /= 2; //even numbers
        }else{
            i = i * 3 + 1; //odd numbers
        }
    }
    cout<<i<<endl; //print first number of dequence
    return 0;
}