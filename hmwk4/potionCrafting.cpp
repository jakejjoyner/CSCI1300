// CSCI 1300 Fall 2022
// Author: Jake Joyner
// Recitation: 202 – Christopher Ojukwu
// Homework 4 - Problem #3

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int i; //initialize and declare variables
    int honeycomb;
    int dandelions;
    int coal;
    int toadstools;
    int manacounter=0;
    int healthcounter=0;
    cout << "Select a potion crafting priority:" << endl; //ask user for input
    cout << "1. Minor Mana" << endl;
    cout << "2. Minor Healing" << endl;
    cin >> i; //user input

    while(i < 1 || i > 2){ //input validation
        cout << "Invalid input." << endl;
        cout << "Select a potion crafting priority:" << endl;
        cout << "1. Minor Mana" << endl;
        cout << "2. Minor Healing" << endl;
        cin >> i;
    }

    cout << "How many Honeycombs do you have?" << endl; //user input
    cin >> honeycomb;
    while(honeycomb<0){ //input validation
        cout << "Invalid input. How many Honeycombs do you have?" << endl;
        cin >> honeycomb;
    }
    cout << "How many Dandelions do you have?" << endl;//user input
    cin >> dandelions;
    while(dandelions<0){//input validation
        cout << "Invalid input. How many Dandelions do you have?" << endl;
        cin >> dandelions;
    }
    cout << "How many Coal do you have?" << endl;//user input
    cin >> coal;
    while(coal<0){//input validation
        cout << "Invalid input. How many Coal do you have?" << endl;
        cin >> coal;
    }
    cout << "How many Toadstools do you have?" << endl;//user input
    cin >> toadstools;
    while(toadstools<0){//input validation
        cout << "Invalid input. How many Toadstools do you have?" << endl;
        cin >> toadstools;
    }


    while(honeycomb>=5 && dandelions>=3 && coal>=1){//mana potion
        manacounter++;
        honeycomb-=5;
        dandelions-=3;
        coal-=1;//reset
    }

        while(honeycomb>=5 && coal >= 2 && toadstools >= 3){//healing potion
            healthcounter++;
            honeycomb-=5;
            coal-=2;
            toadstools-=3;//reset
        
    }
    if (i==1){
    cout << "You can make " << manacounter << " Mana potion(s)" << " and " << healthcounter << " Healing potion(s)." << endl;
    return 0;}//priority one output
    else if(i==2){
        cout << "You can make " << healthcounter << " Healing potion(s)" << " and " << manacounter << " Mana potion(s)." << endl;
    return 0;//priority two output
    }
}