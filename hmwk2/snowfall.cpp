// snowfall.cpp
// CSCI 1300 Fall 2022
// Author: Jake Joyner
// Recitation: 202 – Christopher Ebuka Ojukwu
// Homework 2 - Problem # 4
#include <iostream>
using namespace std;

int main()
{
    int x, vdepth, bdepth, cdepth;
    cout << "How many days in the future would you like a prediction for?" << endl;
    cin>>x;
    vdepth = 28 + 12 * x;
    bdepth = 25 + 5 * x;
    cdepth = 40 + 2 * x;
    cout << "Breckenridge will have " << bdepth << " inches, Vail will have " << vdepth << " inches, and Copper Mountain will have " << cdepth << " inches." << endl;
    return 0;
}