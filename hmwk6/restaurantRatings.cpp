// CSCI 1300 Fall 2022
// Author: Jake Joyner
// Recitation: 202 – Christopher Ojukwu
// Homework 6 - Problem # 4a

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

int readRestaurantData(string filename, string restaurants[], int ratings[][3], int arrSize){
    ifstream file_input;//initialize file input as ifstream type
    file_input.open(filename);//open the file
    string line = "";//initialize line variable to store lines from file
    string arr[10];//create array to store parameters from split function

if (file_input.is_open()){//if the file is open

    int i = 0;//initialize i to 0

    while (!file_input.eof()){//while there is still data to be proccessed in the file
        getline(file_input, line);//store the data from each line of the file in the line variable
        split(line, '~',arr,10);//split the function at every instance of the separator '~'

    if (split(line, '~',arr,10) == 4 && i < arrSize && line.length() != 0){//if the split function returns a value of 4, the counter is less
    //than the size of the array (# of restaurants), and the line isn't empty
        restaurants[i] = arr[0];//set the restaurants aray to the split array at the 0th index (where the restaurants' names are stored)
        ratings[i][0] = stoi(arr[1]);//set the ratings array at the i'th row and 0th column to the split array at 1
        ratings[i][1] = stoi(arr[2]);//set the ratings array at the i'th row and 1th column to the split array at 2
        ratings[i][2] = stoi(arr[3]);//set the ratings array at the i'th row and 2th column to the split array at 3
        i++;//increment the index
        }
    }

    return i;//return the number of restaurants with valid data

    }
else{
    return -1;
}

if (file_input.fail()){//if the file can not be opened

    return -1;//return -1
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
    string RestaurantTestArray[3];
    int ratingsTestArray[3][3];
    assert(readRestaurantData("TestOneFile.txt", RestaurantTestArray, ratingsTestArray, 3) == 3);
    assert(readRestaurantData("Nodata", RestaurantTestArray, ratingsTestArray, 3) == -1);
    assert(readRestaurantData("TestFourFile.txt", RestaurantTestArray, ratingsTestArray, 3) == 3);
    assert(readRestaurantData("EmptyFileTest2.txt", RestaurantTestArray, ratingsTestArray, 0) == 0);
}