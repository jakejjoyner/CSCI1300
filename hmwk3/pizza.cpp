// CSCI 1300 Fall 2022
// Author: Jake Joyner
// Recitation: 202 – Christopher Ojukwu
// Homework 3 - Problem #3

#include <iostream>
using namespace std;

int main()
{
    //initialize variables
char input;
int toppings;
double pizza;
//ask user for input
cout << "What size pizza would you like to order?" << endl;
//user input
cin >> input;

switch(input){ 
//large pizza
case 'L':
cout <<"How many toppings do you want?"<< endl;
cin >> toppings;
if (toppings < 0)
{
    //input validation
    cout << "Please enter a valid input." << endl;
    return 0;
}
pizza = toppings * 2.25 + 6.99;
cout <<"Your total is $" << pizza << endl;
return 0;

//medium pizza
case 'M':
cout <<"How many toppings do you want?"<< endl;
cin >> toppings;
if (toppings < 0)
{
    //input validation
    cout << "Please enter a valid input." << endl;
    return 0;
}
pizza = toppings * 1.50 + 5.99;
cout <<"Your total is $" << pizza << endl;
return 0;

//small pizza
case 'S':
cout <<"How many toppings do you want?"<< endl;
cin >> toppings;
if (toppings < 0)
{
    //input validation
    cout << "Please enter a valid input." << endl;
    return 0;
}
pizza = toppings*.75 + 4.99;

cout <<"Your total is $" << pizza << endl;
return 0;

//input validation
default: cout << "Please enter a valid input." << endl;
return 0;
}
}