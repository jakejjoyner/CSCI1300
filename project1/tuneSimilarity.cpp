#include <iostream>
#include <cassert>
#include <string>
#include <iomanip>

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

double tuneSimilarity(string string1, string string2){

int matchingPitchesAndNotes = 0;
int matchingNotes = 0;
int neither = 0;
    for (int j = 0; j <= string1.length(); j+=2){
        if(string1[j] == string2[j]){
            matchingNotes++;
        }
        else if(string1[j+1] == string2[j+1] && string1[j] == string2[j]){
            matchingPitchesAndNotes++;
        }
        else {
            neither++;
        }
    }

double similarity = ((matchingNotes / numValidNotes(string1)) + matchingPitchesAndNotes - neither);
}