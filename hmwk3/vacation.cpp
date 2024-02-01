// CSCI 1300 Fall 2022
// Author: Jake Joyner
// Recitation: 202 – Christopher Ojukwu
// Homework 3 - Problem #2

#include <iostream>
using namespace std;

int main()
{
    //initialize variables
    double x;
    char input;

    //ask for user input
    cout << "What is your budget?" << endl;
    cin >> x;
    if (x <=0) {
        //input validation
        cout << "Please enter a valid input." << endl;
    }
    //ask user for input
    cout << "What mode of transportation would you like to take (B, T, or A)?" << endl;
    cin >> input;
    return 0;
    switch(input){
        //bus
        case 'B':
         if (x>=175.25) {
             cout << "Yes, this vacation is within your budget!" <<endl;
          
          }
           else if (x < 175.25){
             cout << "Sorry, this vacation is outside your budget." << endl;
         
          }
          return 0;
          //train
           case 'T':
          if (x>=240.66) {
            cout << "Yes, this vacation is within your budget!" <<endl;
           
         }
          else if (x < 240.66){
           cout << "Sorry, this vacation is outside your budget." << endl;
        
          }
          return 0;
          //airplane
          case 'A':
          if (x>=350.96) {
               cout << "Yes, this vacation is within your budget!" <<endl;
               
          }
          else if (x < 350.96){
               cout << "Sorry, this vacation is outside your budget." << endl;
            
          }
          return 0;

//input validation
          default: cout << "Please enter a valid input." << endl;
            }
         
}