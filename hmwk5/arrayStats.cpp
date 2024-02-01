// CSCI 1300 Fall 2022
// Author: Jake Joyner
// Recitation: 202 – Christopher Ojukwu
// Homework 5 - Problem # 2

#include <iostream>
#include <iomanip>
#include <cassert>
using namespace std;

double min(double arr[], int arr_size){
double min = 10000;//initialize min
    for(int i = 0; i < arr_size; i++){//iterate through all values to find the minimum
        if(arr[i] < min){
            min = arr[i];
        }
    }
    return min;//return the minimum
    }

double sum(double arr[], int arr_size){//iterate through all values to add them and find the sum
double sum = 0;
    for(int i = 0; i < arr_size; i++){
        sum += arr[i];
        }
    return sum;//return the sum
    }


double average(double arr[], int arr_size){//iterate through the values to find the average
double sum = 0;
    for(int i = 0; i < arr_size; i++){
        sum += arr[i];
        }
    return sum / arr_size;//return sum divided by array size which is the average
    }

int main(){//test cases
    int testOneArray[3] = {1,2,3};
    min(testOneArray[2], 3);
    assert(testOneArray[2] == 3);
    double testTwoArray[3] = {1,2,3};
    sum(testTwoArray,3);
    assert(testTwoArray[2] == 3);
    average(testTwoArray, 3);
    assert(testTwoArray[2] == 3);
    int testThreeArray[3] = {2,2,3};
    min(testThreeArray[2], 3);
    assert(testThreeArray[1] == 2);

}
