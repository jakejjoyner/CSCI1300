// CSCI 1300 Fall 2022
// Author: Jake Joyner
// Recitation: 202 – Christopher Ojukwu
// Homework 4 - Problem # 4

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
            else {return false;}
        }
        else{
            return false;
        }
    }
}

int numValidNotes(string notes) //problem 3 function
{
    int count = 0;
    if (notes.length() < 2){

        return 0;
    }

    for (int i = 0; i < notes.length(); i++)
    {
       if (isValidNote(notes.substr(i,2)) == true){
        count++;
       }
    }
    return count;
}

double tuneSimilarity(string string1, string string2){

double matchingPitchesAndNotes = 0; //initialize variables
double matchingNotes = 0;
double neither = 0;

if(string1.length() > string2.length() || string2.length() > string1.length()){ //if strings are not the same length, return 0
    return 0;
}
    for (int j = 0; j <= string1.length() - 1; j+=2){ //iterate through characters two at a time until the last set of characters
        if(string1[j] == string2[j]){ //if the first input matches the second input at j (note), increment the matching notes counter
            matchingNotes++;
        }
        if(string1[j] == string2[j] && string1[j+1] == string2[j+1]){ //if the first input matches the second input at j+1 (pitch)
                         //and the first input matches the second input at j (note), increment the matching pitches and notes counter
            matchingPitchesAndNotes++;
        }
        else if (string1[j] != string2[j] && string1[j+1] != string2[j+1]) //if the first input at j doesn't match the second input at j
                           //and the first input doesn't match the second input at j+1 (pitch), increment the neither counter
        {neither++;}
    }

double similarity = ((matchingNotes / numValidNotes(string1)) + matchingPitchesAndNotes - neither); //calculate tune similarity using the algorithm

return similarity; //return the tune similarity
}

int main(){
    assert(tuneSimilarity("G4E5D4", "G4F4D5") == 0.666667);
    assert(tuneSimilarity("A0B0C0D0", "D1C1B1A1") == -4);
    assert(tuneSimilarity("D5G2", "F7D1E4G4") == 0);
    assert(tuneSimilarity("E5E5G5A6G5D5", "E5G5A6G5D5D5") == 0.333333);
}