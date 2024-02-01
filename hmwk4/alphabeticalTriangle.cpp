// CSCI 1300 Fall 2022
// Author: Jake Joyner
// Recitation: 202 – Christopher Ojukwu
// Homework 4 - Problem #5

#include <iostream>
using namespace std;

int main()
{
    char alphabet = 'a';//initialize and declare variables
    int n;
    cout << "Enter the height: " << endl;//ask for input
    cin >> n;//user input
    if(n<=0){
        cout << "Invalid input." << endl;//input validation
    }
    for (int i=1; i <= n; i++){//iterate through user input
        for(int j=1; j<=i; j++){
           cout << alphabet++;//iterate through letters
           if(alphabet>122){
               alphabet -= 26;//restart alphabet
           }
        }
        for(int j=2; j<=i; j++){//increment by 2
           cout << alphabet++;
           if(alphabet>122){
               alphabet -= 26;//restart alphabet
           }
           
        }
        cout << endl;//go to next line

    }
         
    }
 