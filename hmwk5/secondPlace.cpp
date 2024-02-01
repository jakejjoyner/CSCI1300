// CSCI 1300 Fall 2022
// Author: Jake Joyner
// Recitation: 202 – Christopher Ojukwu
// Homework 5 - Problem # 3b

#include <iostream>
#include <cstdlib>
#include <cassert>

using namespace std;

bool insertAfter(string input_strings[], int num_elements, int arr_size, int index, string string_to_insert){//insertAfter function
  if(num_elements == arr_size || index > arr_size-2){
        return false;
    }
        for(int i = num_elements-1; i >= index+1; i--){
        input_strings[i+1] = input_strings[i];
          }
         input_strings[index+1] = string_to_insert;
        return true;
}

    int secondPlace(string input_strings[], string string_to_insert, string string_to_find, int num_elements, int arr_size, int count){
if(num_elements==arr_size || num_elements > arr_size-count){//input validation
    return num_elements;
}

    for(int i = num_elements-1+count; i>=0;i--){//iterate through values to find the target string
        if(input_strings[i] == string_to_find){
            insertAfter(input_strings, num_elements-1+count,arr_size,i,string_to_insert);//use insert after function to insert the string
        }
    }
    return num_elements+count;//return the new number of elements
    }
int main(){//test cases
    string testOneArray[5] = {"pikachu", "meowth", "snorlax"};
    secondPlace(testOneArray, "charizard", "meowth", 3, 5, 1);
    assert(testOneArray[0] == "pikachu");
    assert(testOneArray[1] == "meowth");
    assert(testOneArray[2] == "charizard");
    assert(testOneArray[3] == "snorlax");
    assert(testOneArray[4] == "");
}