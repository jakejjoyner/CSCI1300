// CSCI 1300 Fall 2022
// Author: Jake Joyner
// Recitation: 202 – Christopher Ojukwu
// Homework 4 - Problem # 1

#include <iostream>
#include <cassert>
using namespace std;

bool isValidNote(string input){ 
    if(input.length() <= 1 || input.length() > 2) //not a tune if input is less than or equal to one or greater than 2
    {
        return 0;
    }
    else {
        if(input.at(0) >= 65 && input.at(0) <= 71){ //checks if first char in string is between A and G
            if(input.at(1) >= 48 && input.at(1) <= 57){ //checks if second char in string is between 0 and 9
                return true;
            }
            else {return false;} //if neither return 0
        }
        else{
            return false;//if neither return 0
        }
    }
}

int main()
{
    assert(isValidNote("G2") == true);
    assert(isValidNote("A10") == false);
    assert(isValidNote("X9") == false);
    assert(isValidNote("Y10") == false);
    assert(isValidNote("A2") == true);
}