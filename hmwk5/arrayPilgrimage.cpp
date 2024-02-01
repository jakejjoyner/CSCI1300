// CSCI 1300 Fall 2022
// Author: Jake Joyner
// Recitation: 202 – Christopher Ojukwu
// Homework 5 - Problem # 1

#include <iostream>
#include <iomanip>
#include <cassert>

using namespace std;

int main(){
    double d[] = {5,6,7,8,9,10,11,12,13,14}; //initialize array for distance
    string cities[] = {"Boulder", "NYC", "LA", "Chicago", "Houston"}; //initialize array for cities
    int sequence[100]; //int sequence array
    int divisor = 6; //int integer to divide by
    for (int i=0; i<100; i++){ //for loop to iterate through sequence array every 6 integers
        sequence[i] = divisor;
        divisor+=6;
    }

    char letters[52]; //initialize letters array
    int index=0; //initialize index integer
    for(int i=65; i<=92; i++){ //for loop to iterate through letters
        letters[index++] = char(i);
        letters[index++] = char(i + 32);
    }
    for(int i = 0; i < 10; i++){ //for loop to iterate through distance
        cout << d[i] << endl;
    }
    for(int i=0; i<5; i++){//for loop to to iterate through cities
        cout << cities[i] << endl;
    }

    for(int i=0; i<100; i++){ //for loop to iterate through sequences
        cout << sequence[i] << endl; 
    }
    for(int i=0; i<52; i+=2){//for loop to iterate through uppercase + lowercase letters
        cout << letters[i] << endl; 
        cout << letters[i + 1] << endl;
    }
}