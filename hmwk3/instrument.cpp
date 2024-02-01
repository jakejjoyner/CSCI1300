// CSCI 1300 Fall 2022
// Author: Jake Joyner
// Recitation: 202 – Christopher Ojukwu
// Homework 3 - Problem #6

#include <iostream>
using namespace std;

int main(){
//initialize and declare variables
int input=0;
int nested_input=0;
//ask user for input
cout << "Select a category: " << "(1)Brass " << "(2)Woodwind " << "(3)Percussion" << endl;
cin >> input;
    switch (input){
        //brass instruments
        case 1:
            cout << "Select an instrument: " << "(1)Trumpet " << "(2)Trombone" << endl;
            cin >> nested_input;
                switch (nested_input){
                     case 1:
                        cout << "Your instrument will be " << "$350." << endl;
                    return 0;
                    case 2:
                        cout << "Your instrument will be " << "$400." <<endl;
                    return 0;
                    //input validation
                    default: 
                    cout << "Please enter a valid input." << endl;
            }
        return 0;
        //Woodwinds
        case 2:
            cout << "Select an instrument: " << "(1)Flute " << "(2)Saxophone" <<endl;
            cin >> nested_input;
                switch (nested_input){
                    case 1:
                        cout << "Your instrument will be " << "$325." << endl;
                    return 0;
                    case 2:
                        cout << "Your instrument will be " << "$425." << endl;
                    return 0;
                    //input validation
                    default:
                        cout << "Please enter a valid input." << endl;
                }
            return 0;
        //Percussion
        case 3:
            cout << "Select an instrument: " << "(1)Snare Drum " << "(2)Cymbals" << endl;
            cin >> nested_input;
                switch(nested_input){
                    case 1:
                        cout << "Your instrument will be " << "$275." << endl;
                    return 0;
                    case 2:
                        cout << "Your instrument will be " << "$200." << endl;
                    return 0;
                    //input validation
                    default:
                        cout << "Please enter a valid input." << endl;
                }
            return 0;
        //input validation
        default:
            cout << "Please enter a valid input." << endl;
        return 0;
    }
}