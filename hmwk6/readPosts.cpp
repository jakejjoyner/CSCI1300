// CSCI 1300 Fall 2022
// Author: Jake Joyner
// Recitation: 202 – Christopher Ojukwu
// Homework 6 - Problem # 3

#include <iostream>
#include <cassert>
#include <cstring>
#include <fstream>
using namespace std;

int split(string input_string, char separator, string arr[], int arr_size){
    int x = 0;//initialize variables
    int start_of_string = 0;
    int end_of_string = 0;
    int length;
if(input_string == ""){
    return 0;//test that function exists
}
int input_stringLength = input_string.length();
   while(end_of_string<input_stringLength){//while loop to iterate through array and split it at instances of the separator
    if(input_string[end_of_string] == separator){
        length = end_of_string - start_of_string;//calculates length of the string that will be split
           if(x==arr_size){//return -1 if number of sep are equal to array size
               return -1;
          }
        arr[x++] = input_string.substr(start_of_string,length);//if the new array at x plus 1 equals the input string at the start
        end_of_string++;//increments the end of string variable by one and
        start_of_string=end_of_string;//set start = end
    }
    else{
        end_of_string++;//if does not encounter sep increment the end variable
     }
    }
    if(x == arr_size){
        return -1; //return -1 if number of sep are equal to array size
    }
    arr[x++] = input_string.substr(start_of_string,length);
    return x; //return number of splits
}

int readPosts(string filename){

ifstream file_input;//initialize file input variable to store text file
file_input.open(filename);//open file input as an ifstream file
string line = "";//initialize and declare line variable to store lines from the text file
string arr[100];//initialize array to store results from split function
int index = 0;//initialize and declare variable to store index (number of points)

if (file_input.is_open()){//if the file is opened succesfully

    while (!file_input.eof()){//while there is still data to be proccesed in the file
        getline(file_input, line);//store the data from each line of the file in the line variable
        split(line, ',',arr,100);///split the function at every instance of a separator
        if(split(line, ',', arr, 100)==3 && line.length() != 0){//if the split function returns a value of three (there are 3 parameters in the line)
        //and the line is not empty
            index++;//increment the index counter
        }
    }

return index;//return the index counter (number of posts with three parameters)

}
else{
    return -1;
    }


if (file_input.fail()){//if the file is not opened succesfully

    return -1;//return a value of -1
}

}

int main()
{ // test cases
    string testOneString = "ABC,DEF,GHI,JKL";
    string arr[4];
    split(testOneString, ',', arr, 4);
    assert(arr[0] == "ABC");
    assert(arr[1] == "DEF");
    assert(arr[2] == "GHI");
    assert(arr[3] == "JKL");
    assert(readPosts("ReadPostsTest.txt") == 3);
    assert(readPosts("BadData") == -1);
    assert(readPosts("ReadPostsEmptyLines.txt") == 3);
    assert(readPosts("FileDoesNotExist.txt") == -1);
}