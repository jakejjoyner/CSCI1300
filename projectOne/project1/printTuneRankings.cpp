// CSCI 1300 Fall 2022
// Author: Jake Joyner
// Recitation: 202 – Christopher Ojukwu
// Homework 4 - Problem # 6

#include <iostream>
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

double bestSimilarity(string inputTune, string targetTune){ //problem 5 function
    double bestScore = -10;
    if(targetTune.length() > inputTune.length()){
        return 0;
    }
    for(int i = 0; i <= inputTune.length() - targetTune.length(); i++){
        if (tuneSimilarity(inputTune.substr(i,targetTune.length()), targetTune) > bestScore){
           bestScore = (tuneSimilarity(inputTune.substr(i,targetTune.length()), targetTune));
        }
    }
    return bestScore;
}

string printTuneRankings(string input1, string input2, string input3, string targetInput){
    for(int i = 0; i <= 3; i++){ //iterate through all three rankings
        if(bestSimilarity(input3, targetInput) > bestSimilarity(input2, targetInput) && //go through all possible combinations of tunes
         bestSimilarity(input2, targetInput) > bestSimilarity(input1, targetInput)){
            cout << "1) Tune 3, 2) Tune 2, 3) Tune 1";
            return 0;
        }
         if(bestSimilarity(input1, targetInput) > bestSimilarity(input3, targetInput) 
         && bestSimilarity(input3, targetInput) > bestSimilarity(input2, targetInput)){
            cout << "1) Tune 1, 2) Tune 3, 3) Tune 2";
            return 0;
         }
         if(bestSimilarity(input3, targetInput) > bestSimilarity(input1, targetInput) 
         && bestSimilarity(input1, targetInput) > bestSimilarity(input2, targetInput)){
            cout << "1) Tune 3, 2) Tune 1, 3) Tune 2";
            return 0;
         }
         if(bestSimilarity(input1, targetInput) > bestSimilarity(input2, targetInput) 
         && bestSimilarity(input2, targetInput) > bestSimilarity(input3, targetInput)){
            cout << "1) Tune 1, 2) Tune 2, 3) Tune 3";
            return 0;
         }
         if(bestSimilarity(input2, targetInput) > bestSimilarity(input1, targetInput) 
         && bestSimilarity(input1, targetInput) > bestSimilarity(input3, targetInput)){
            cout << "1) Tune 2, 2) Tune 1, 3) Tune 3";
            return 0;
         }
         if(bestSimilarity(input1, targetInput) == bestSimilarity(input2, targetInput) 
         && bestSimilarity(input2, targetInput) > bestSimilarity(input3, targetInput)){
            cout << "1) Tune 1, 2) Tune 2, 3) Tune 3";
            return 0;
         }
         if(bestSimilarity(input1, targetInput) == bestSimilarity(input2, targetInput) 
         && bestSimilarity(input3, targetInput) > bestSimilarity(input1, targetInput)){
            cout << "1) Tune 3, 2) Tune 1, 3) Tune 2";
            return 0;
         }
         if(bestSimilarity(input1, targetInput) == bestSimilarity(input3, targetInput) 
         && bestSimilarity(input3, targetInput) > bestSimilarity(input2, targetInput)){
            cout << "1) Tune 1, 2) Tune 3, 3) Tune 2";
            return 0;
         }
         if(bestSimilarity(input1, targetInput) == bestSimilarity(input3, targetInput) 
         && bestSimilarity(input3, targetInput) == bestSimilarity(input2, targetInput)){
            cout << "1) Tune 1, 2) Tune 2, 3) Tune 3";
            return 0;
         }
         if(bestSimilarity(input1, targetInput) == bestSimilarity(input3, targetInput) 
         && bestSimilarity(input2, targetInput) > bestSimilarity(input3, targetInput)){
            cout << "1) Tune 2, 2) Tune 1, 3) Tune 3";
            return 0;
         }
         if(bestSimilarity(input2, targetInput) == bestSimilarity(input3, targetInput) 
         && bestSimilarity(input1, targetInput) > bestSimilarity(input3, targetInput)){
            cout << "1) Tune 1, 2) Tune 2, 3) Tune 3";
            return 0;
         }
         
    }
}

main(){
    assert(printTuneRankings("D3D4", "E3D4", "D3F4", "A7") == "1) Tune 1, 2) Tune 2, 3) Tune 3");
    assert(printTuneRankings("B8", "C8", "A7", "C8") == "1) Tune 2, 2) Tune 1, 3) Tune 3");
    assert(printTuneRankings("C2E7", "D4B3", "A4D1", "A4B7") == "1) Tune 2, 2) Tune 3, 3) Tune 1");

}