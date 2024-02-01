// CSCI 1300 Fall 2022
// Author: Jake Joyner
// Recitation: 202 – Christopher Ojukwu
// Homework 7 - Problem # 1

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

int sumElements(vector<int> vect, int start_index, int end_index){
    //initialize a variable to store the sums
    int sum = 0;
    //if the start index is greater than the end index, return -1
    if(start_index > end_index){
        return -1;
    }
    //if the start index is less than the index at the start of the vector, return -2
    if(start_index < 0){
        return -2;
    }
    //if the end index is greater than or equal to the index at the end of the vecotr, return -2
    if(end_index >= vect.size()){
        return -2;
    }
    //for int i = start_index, while i is less than of equal to the end index, increment i
    //add the vector at index i to the sum variable
    for(int i = start_index; i <= end_index; i++){
        sum += vect.at(i);
    }
    //return the sum
    return sum;
}

int main(){
vector<int> vect1{10, 20, 30, 40, 50};
int start_index = 1, end_index = 3;
sumElements(vect1, start_index, end_index);
//return sum
assert(sumElements(vect1, start_index, end_index) == 90);
//return -2 because start index too small
assert(sumElements(vect1, -1, end_index) == -2);
//return -2 because end index too large
assert(sumElements(vect1, start_index, 10) == -2);
//return -1 because start index larger than end index
assert(sumElements(vect1, 10, end_index) == -1);
//return sum
assert(sumElements(vect1, 1, 2) == 50);
}