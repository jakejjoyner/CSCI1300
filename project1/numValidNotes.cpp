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
       if (isValidNote(notes.substr(i,2)) == true){
        count++;
       }
    }
    return count;
}