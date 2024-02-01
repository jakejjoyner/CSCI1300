// CSCI 1300 Fall 2022
// Author: Jake Joyner
// Recitation: 202 – Christopher Ojukwu
// Homework 4 - Problem # 3

#include <iostream>
#include <cassert>
#include <string>
using namespace std;

bool isValidNote(string input){ //problem one function
    if(input.length() <= 1 || input.length()%2 != 0)
    {
        return 0;
    }
    else {
        if(input.at(0) >= 65 && input.at(0) <= 71){
            if(input.at(1) >= 48 && input.at(1) <= 57){
                return true;
            }
        }
        else{
            return false;
        }
    }
}

int numValidNotes(string notes)
{
    int count = 0;
    if (notes.length() < 2){ //not a tune if less than two chars

        return 0; //returns false
    }

    for (int i = 0; i < notes.length(); i++) // checks every char
    {
       if (isValidNote(notes.substr(i,2)) == true){ //increment the counter if isValidNote finds a note
        count++;
       }
    }
    return count;
}

int main(){
    assert(numValidNotes("F4E2B0") == 3);
    assert(numValidNotes("comsci") == 0);
    assert(numValidNotes("ADB3M7G4FG9G3") == 5);
    assert(numValidNotes("HCKJHD3F6") == 3);
}