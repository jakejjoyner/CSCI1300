// almondMilk.cpp
// CSCI 1300 Fall 2022
// Author: Jake Joyner
// Recitation: 202 – Christopher Ebuka Ojukwu
// Homework 2 - Problem # 3
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double s;
    double h;
    double b;
    double v;
    double vino;
    cout << fixed << setprecision(1);
    cout << "What is the side length of the base of the carton in inches?"
    << endl;
    cin >> s;
    cout << "What is the height of the carton in inches?" << endl;
    cin >> h;
    b = s * s;
    v = b * h;
    vino = v * 0.55;
    cout << "The carton has a volume of " << vino << " ounces." << endl;
    return 0;
    
}