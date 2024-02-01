// CSCI 1300 Fall 2022
// Author: Jake Joyner
// Recitation: 202 – Christopher Ojukwu
// Homework 4 - Problem # 7

#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
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

bool isValidTune(string input)
{
    if (input.length() < 2){ //not a tune if less than two chars

        return false; //returns false
    }

    for (int i = 0; i < input.length(); i+=2) // checks every two chars
    {
        if (!isValidNote(input.substr(i, 2))){ //checks if every two chars is a valid note

            return false; //return false if it doesn't pass all the checks
        }
    }
    return true; //if passes all checks then returns true
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
return similarity;
}

double bestSimilarity(string inputTune, string targetTune){
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

double printTuneRankings(string input1, string input2, string input3, string targetInput){
    for(int i = 0; i <= 3; i++){
        if(bestSimilarity(input3, targetInput) > bestSimilarity(input2, targetInput) &&
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

int main()
{

int choice; //initialize choice variable

cout << "--- Menu ---" << endl; //display menu
cout << "1. Calculate similarity between two tunes." << endl;
cout << "2. Calculate best similarity between two tunes of potentially different lengths." << endl;
cout << "3. Print three input tunes in order from most to least similar to the target tune." << endl;
cout << "4. Exit." << endl;
cout << "Please enter your choice (1 - 4):" << endl;
cin >> choice;

if (choice > 4 || choice < 1){ //input validation
    cout << "Invalid Input." << endl;//display menu and ask for user input again
    cout << "--- Menu ---" << endl;
    cout << "1. Calculate similarity between two tunes." << endl;
    cout << "2. Calculate best similarity between two tunes of potentially different lengths." << endl;
    cout << "3. Print three input tunes in order from most to least similar to the target tune." << endl;
    cout << "4. Exit." << endl;
    cout << "Please enter your choice (1 - 4):" << endl;
    cin >> choice;//user input
}


while(choice == 1){ //choice 1
    string tune1;
    cout << "Please enter the first tune:" << endl; //prompt user for input of first tune
    cin >> tune1; //user input
    if(isValidTune(tune1) == false){ //input validation
        cout << "Invalid Input. Please enter a tune in valid SPN:" << endl;//prompt user for input
          cin >> tune1; //user input
    }
    else if(isValidTune(tune1) == true){ //input validation
        cout << "Please enter the second tune:" << endl; //prompt user for input of second tune
        string tune2; //initialize variable
        cin >> tune2; //user input
        if(isValidTune(tune2) == false){ //input validation
            cout << "Invalid Input. Please enter a tune in valid SPN:" << endl;//prompt user for input
            cin >> tune2; //user input
        }
        else if(isValidTune(tune2) == true){ //input validation
            cout << "The similarity score is " << fixed << setprecision(2) << tuneSimilarity(tune1, tune2) << endl; //output tunesimilarity
        }
    }
cout << "--- Menu ---" << endl; //display menu
cout << "1. Calculate similarity between two tunes." << endl;
cout << "2. Calculate best similarity between two tunes of potentially different lengths." << endl;
cout << "3. Print three input tunes in order from most to least similar to the target tune." << endl;
cout << "4. Exit." << endl;
cout << "Please enter your choice (1 - 4):" << endl;
cin >> choice;//user input

if (choice > 4 || choice < 1){ //input validation
    cout << "Invalid Input." << endl;//display menu and ask for user input again
    cout << "--- Menu ---" << endl;
    cout << "1. Calculate similarity between two tunes." << endl;
    cout << "2. Calculate best similarity between two tunes of potentially different lengths." << endl;
    cout << "3. Print three input tunes in order from most to least similar to the target tune." << endl;
    cout << "4. Exit." << endl;
    cout << "Please enter your choice (1 - 4):" << endl;
    cin >> choice;//user input
}
}

while(choice == 2){ //choice 2
    string tune1; //initialize variable
    cout << "Please enter the input tune:" << endl; //prompt user for input
    cin >> tune1; //user input
    if(isValidTune(tune1) == false){ //input validation
        cout << "Invalid Input. Please enter a tune in valid SPN:" << endl;//prompt user for input
          cin >> tune1;
    }
    else if(isValidTune(tune1) == true){ //input validation
        cout << "Please enter the target tune:" << endl; //prompt user for input
        string tune2; //initialize variable
        cin >> tune2; //user input
        if(isValidTune(tune2) == false){ //input validation
            cout << "Invalid input. Please enter a tune in valid SPN:" << endl; //prompt user for input
            cin >> tune2; //user input
            if(isValidTune(tune2) == true){ //input validation
            cout << "The best similarity score is: " << fixed << setprecision(2) << bestSimilarity(tune1, tune2) << endl; //display bestSimilarity
        }
        }
        else if(isValidTune(tune2) == true){ //input validation
            cout << "The best similarity score is: " << fixed << setprecision(2) << bestSimilarity(tune1, tune2) << endl; //display bestSimilarity
        }
    }
cout << "--- Menu ---" << endl;//display menu
cout << "1. Calculate similarity between two tunes." << endl;
cout << "2. Calculate best similarity between two tunes of potentially different lengths." << endl;
cout << "3. Print three input tunes in order from most to least similar to the target tune." << endl;
cout << "4. Exit." << endl;
cout << "Please enter your choice (1 - 4):" << endl;
cin >> choice;

if (choice > 4 || choice < 1){ //input validation
    cout << "Invalid Input." << endl;//display menu and ask for input again
    cout << "--- Menu ---" << endl;
    cout << "1. Calculate similarity between two tunes." << endl;
    cout << "2. Calculate best similarity between two tunes of potentially different lengths." << endl;
    cout << "3. Print three input tunes in order from most to least similar to the target tune." << endl;
    cout << "4. Exit." << endl;
    cout << "Please enter your choice (1 - 4):" << endl;
    cin >> choice;
}
}

while(choice == 3){ //choice 3
    string tune1;//initialize variable
    cout << "Please enter the first tune:" << endl; //prompt user for input
    cin >> tune1; //user input
    if(isValidTune(tune1) == false){// input validation
        cout << "Invalid Input. Please enter a tune in valid SPN:" << endl;//prompt user for input
          cin >> tune1;//user input
    }
    else if(isValidTune(tune1) == true){// input validation
        cout << "Please enter the second tune:" << endl;//prompt user for input
        string tune2;//initalize variable
        cin >> tune2;//user input
        if(isValidTune(tune2) == false){// input validation
            cout << "Invalid Input. Please enter a tune in valid SPN:" << endl;//prompt user for input
            cin >> tune2;//user input
        }
        else if(isValidTune(tune2) == true){// input validation
            string tune3;//initialize variable
            cout << "Please enter the third tune: " << endl;//prompt user for input
            cin >> tune3;//user input
            if(isValidTune(tune3) == false){// input validation
                cout << "Invalid Input. Please enter a tune in valid SPN:" << endl;//prompt user for input again
                cin >> tune3;//user input
            }
            else if(isValidTune(tune3) == true){// input validation
                string targetTune;//initialize variable
                cout << "Please enter the target tune: " << endl;//prompt user for input
                if (isValidTune(targetTune) == false){// input validation
                    cout << "Invalid Input. Please enter a tune in valid SPN: " << endl;//prompt user for input again
                    cin >> targetTune;//user input
                }
                else if(isValidTune(targetTune) == true){// input validation
                    printTuneRankings(tune1, tune2, tune3, targetTune); //print tunerankings
                }
            }
        }
    }
cout << "--- Menu ---" << endl;//displat menu
cout << "1. Calculate similarity between two tunes." << endl;
cout << "2. Calculate best similarity between two tunes of potentially different lengths." << endl;
cout << "3. Print three input tunes in order from most to least similar to the target tune." << endl;
cout << "4. Exit." << endl;
cout << "Please enter your choice (1 - 4):" << endl;
cin >> choice;

if (choice > 4 || choice < 1){//input validation
    cout << "Invalid Input." << endl;//ask for user input again
    cout << "--- Menu ---" << endl;
    cout << "1. Calculate similarity between two tunes." << endl;
    cout << "2. Calculate best similarity between two tunes of potentially different lengths." << endl;
    cout << "3. Print three input tunes in order from most to least similar to the target tune." << endl;
    cout << "4. Exit." << endl;
    cout << "Please enter your choice (1 - 4):" << endl;
    cin >> choice;//user input
}
else if (choice == 4){//choice 4
    cout << "Goodbye!" << endl;//print Goodbye!
}
}
if (choice == 4){//choice 4
    cout << "Goodbye!" << endl;//print Goodbye!
    return 0;
}}