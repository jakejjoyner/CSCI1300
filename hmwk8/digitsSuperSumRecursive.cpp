// CSCI 1300 Fall 2022
// Author: Jake Joyner
// Recitation: 202 – Christopher Ojukwu
// Homework 8 - Problem # 1

#include <iostream>
#include <cassert>

using namespace std;

/*
Algorithm:
1. Check whether or not the number only has one digit
2. If the number only has one digit, return the number
3. If the number is two digits or more, add all the digits of the number inputted by the user recursively to the sum variable,
then add all of the digits of the sum variable recursively and return that number once it is one digit
*/
int digitsSuperSumRecursive(int N)
{
    int sum = 0;
    if(N < 10)
        return N;
    sum += (N % 10 + digitsSuperSumRecursive(N / 10));
    return (sum % 10 + digitsSuperSumRecursive(sum / 10));
}

int main(){
    //test cases
    cout << digitsSuperSumRecursive(4567) << endl;
    assert(digitsSuperSumRecursive(4567) == 4);
    assert(digitsSuperSumRecursive(7) == 7);
    assert(digitsSuperSumRecursive(3425) == 5);
    assert(digitsSuperSumRecursive(342) == 9);
    assert(digitsSuperSumRecursive(34252545) == 3);
}