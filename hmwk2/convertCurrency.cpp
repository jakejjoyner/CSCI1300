// convertCurrency.cpp
// CSCI 1300 Fall 2022
// Author: Jake Joyner
// Recitation: 202 – Christopher Ebuka Ojukwu
// Homework 2 - Problem # 5
#include <iostream>
using namespace std;

int main()
{
    int bolts;
    int gems;
    int goldcoins;
    cout << "Enter the number of Bolts:" << endl;
    cin >> bolts;
    goldcoins = bolts/23;
    gems = goldcoins/13;
    bolts = bolts%23;
    goldcoins = goldcoins%13;
    cout << gems << " Gem(s) " << goldcoins <<
    " GoldCoin(s) " << bolts << " Bolt(s)";
    return 0;
}