// CSCI 1300 Fall 2022
// Author: Jake Joyner
// Recitation: 202 – Christopher Ojukwu
// Homework 7 - Problem # 2

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

string dnaRead(vector<string> dna){
    /**
    *initialize a string to store the sequence to ""
    *initialize the start index as the size of the dna vector
    *initialize the end index as the size of the dna vector
    */
    string dna_sequence = "";
    int start_index = dna.size();
    int end_index = dna.size();

    /*
    Algorithm: checks if input is valid (if it only consists of strings 3 letters long)
     1. for int i = 0, while i is less than the size of the dna vector, increment i
        2.if the value of the dna vector at i's length does not equal 3
        return "Invalid sequence."
    */
    for(int i = 0; i < dna.size(); i++){
        if(dna.at(i).length() != 3){
            return "Invalid sequence.";
        }
    }
    /*
    Algorithm: checks if input is valid (if it only contains A,C,G,T)
    1. for int i = 0, while i is less than the size of the dna vector, increment i
       2. for int j = 0, while j is less than 3, increment j
           3. if the value of the dna vector at i has any letter not equal to A,C,G, or T
            return "Invalid sequence."
    */
    for(int i = 0; i < dna.size(); i++){
        for(int j = 0; j < 3; j++){
        if(dna.at(i).substr(j,1) != "A" && dna.at(i).substr(j,1) != "C" && dna.at(i).substr(j,1) != "G" && dna.at(i).substr(j,1) != "T"){
            return "Invalid sequence.";
        }
        }
    }
    /*
    Algorithm: checks for locations of start and end codons
    1. for int i = 0, while i is less than the size of the dna vector, increment i
        2. if the dna vector at i equals "ATG"
           3. set the start index to i
        4. if the dna vector at i equals "TAA"
           5.  set the end index to i, and break
        6. if the dna vector at i equals "TGA"
           7. set the end index to i, and break
        8. if the dna vector at i equals "TAG"
           9. set the end index to i, and break
    */
    for(int i = 0; i < dna.size(); i++){
        if(dna.at(i) == "ATG"){
            start_index = i;
        }
        if(dna.at(i) == "TAA"){
            end_index = i;
            break;
        }
        if(dna.at(i) == "TGA"){
            end_index = i;
            break;
        }
        if(dna.at(i) == "TAG"){
            end_index = i;
            break;
        }
    }
    /*
    Algorithm: constructs the DNA sequence
    1. for int i = start_index + 1, while i is less than the end index, increment i
       2. add the dna sequencevector at i to the dna_sequence string
    
    return the dna_sequence string
    */
    for(int i = start_index + 1; i < end_index; i++){
        dna_sequence += dna.at(i);
    }
    return dna_sequence;
    
}

int main(){
//test case 1
vector<string> dna{"ATG", "TCA", "TAA"};
dnaRead(dna);
assert(dnaRead(dna) == "TCA");
//test case 2
vector<string> dna2{"ATE", "TCA", "TAA"};
assert(dnaRead(dna2) == "Invalid sequence.");
//test case 3
vector<string> dna3{"ATEG", "TCA", "TAA"};
assert(dnaRead(dna3) == "Invalid sequence.");
//test case 4
vector<string> dna4{"TAC", "ATG", "TCA", "TCA","TAG"};
assert(dnaRead(dna4) == "TCATCA");
//test case 5
vector<string> dna5{"TAC", "ATG", "TCA", "TCA","TAT"};
assert(dnaRead(dna5) == "TCATCATAT");
//test case 6
vector<string> dna6{"TAC", "ATC", "TCA", "TCA","TAT"};
assert(dnaRead(dna6) == "");
}