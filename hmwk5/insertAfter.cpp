// CSCI 1300 Fall 2022
// Author: Jake Joyner
// Recitation: 202 – Christopher Ojukwu
// Homework 5 - Problem # 3a

#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

bool insertAfter(string input_strings[], int num_elements, int arr_size, int index, string string_to_insert){
  if(num_elements == arr_size || index > arr_size-2){//input validation
        return false;
    }
        for(int i = num_elements-1; i >= index+1; i--){//iterate through values to move them over to the right one
        input_strings[i+1] = input_strings[i];
          }
         input_strings[index+1] = string_to_insert;//insert the string 1 after the index
        return true;
}

int main(){//test cases
    string testOneArray[5] = {"pikachu", "meowth", "snorlax"};
    insertAfter(testOneArray, 3, 5, 1, "meowth");
    assert(testOneArray[0] == "pikachu");
    assert(testOneArray[1] == "meowth");
    assert(testOneArray[2] == "meowth");
    assert(testOneArray[3] == "snorlax");
    assert(testOneArray[4] == "");
}