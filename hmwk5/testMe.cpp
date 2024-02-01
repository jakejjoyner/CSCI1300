// CSCI 1300 Fall 2022
// Author: Jake Joyner
// Recitation: 202 – Christopher Ojukwu
// Homework 5 - Problem # 6

#include <iostream>
#include <cassert>
using namespace std;

int zeroesToFives(int arr[], int arr_size)
{
	int count = 0;
	//loops through input array
	for(int i = 0; i < arr_size; i++) 
	{ 
		if(arr[i] == 0) //if an element is zero, set it to five
		{ 
    			arr[i] = 5; 
                count++;
		}
	}
	return count;
}

int main(){//test cases
    int testOneArray[3] = {0,3,5};
    zeroesToFives(testOneArray,3);
    assert(testOneArray[2] == 5);
    assert(testOneArray[1] == 3);
    assert(testOneArray[0] == 5);
    int testTwoArray[3] = {0,0,0};
     zeroesToFives(testTwoArray,3);
    assert(testTwoArray[2] == 5);
   assert(testTwoArray[1] == 5);
    assert(testTwoArray[0] == 5);
    int testThreeArray[3] = {5,0,5};
    zeroesToFives(testThreeArray,3);
    assert(testThreeArray[2] == 5);
    assert(testThreeArray[1] == 5);
   assert(testThreeArray[0] == 5);
    int testFourArray[3] = {5,5,5};
    zeroesToFives(testThreeArray,3);
    assert(testFourArray[2] == 5);
    assert(testFourArray[1] == 5);
    assert(testFourArray[0] == 5);
}