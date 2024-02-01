// CSCI 1300 Fall 2022
// Author: Jake Joyner
// Recitation: 202 – Christopher Ojukwu
// Homework 4 - Problem #4

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string sequence;//declare variables
    string fragment;
    int position = 0;
    int count = 0;
    int i = 1;
    cout << "Enter the DNA Sequence: " << endl;//ask for user input
    cin >> sequence;//user input
    cout << "Enter the DNA fragment to be searched: " << endl;//ask for user input
    cin >> fragment;//user input

    while(sequence.at(i) != 'A' || 'C' || 'G' || 'T'){//input validation
        cout << "This is not a valid DNA sequence." << endl;

    }

    while(sequence.find(fragment, position) != string::npos){//check for fragment at first occurence
        position = sequence.find(fragment, position) + 1; // check for fragment at second occurrence
        count++;//repeat
    }
    cout << "Number of occurrences: " << count << endl;//output
    return 0;

}