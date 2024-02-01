// CSCI 1300 Fall 2022
// Author: Jake Joyner
// Recitation: 202 – Christopher Ojukwu
// Homework 4 - Problem # 5

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

double tuneSimilarity(string string1, string string2){ //problem 4 function

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
return similarity;
}

double bestSimilarity(string inputTune, string targetTune){
    double bestScore = -10; //set 'best score' to a number lower than the best score would ever be
    if(targetTune.length() > inputTune.length()){ //if target tune length is greater than input tune length
        return 0; //return 0
    }
    for(int i = 0; i <= inputTune.length() - targetTune.length(); i++){ //iterate through all patterns of inputTune length in targetTune
        if (tuneSimilarity(inputTune.substr(i,targetTune.length()), targetTune) > bestScore){ //if the tune similarity is greater than bestscore
           bestScore = (tuneSimilarity(inputTune.substr(i,targetTune.length()), targetTune)); //set the bestscore equal to the tune similarity
           // and iterate through all patterns of input tune in target tune
        }
    }
    return bestScore; //return the best score
}

int main(){
    assert(bestSimilarity("E4D5B7G2E2", "D6G5G2") == 0.666667);
    assert(bestSimilarity("F1E2C2D1A7B8D3", "F2A7C3") == -0.333333);
    assert(bestSimilarity("A2G7", "E9D2C4F1") == 0);
}