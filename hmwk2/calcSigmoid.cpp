// calcSigmoid.cpp
// CSCI 1300 Fall 2022
// Author: Jake Joyner
// Recitation: 202 – Christopher Ebuka Ojukwu
// Homework 2 - Problem # 6
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double x, s;
    cout << "Enter a value for x:" << endl;
    cin >> x;
    s = 1/(1+ exp(-x));
    cout << "The sigmoid for x=" << x << " is " << s << endl;
    return 0;
}