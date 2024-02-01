// CSCI 1300 Fall 2022
// Author: Jake Joyner
// Recitation: 202 – Christopher Ojukwu
// Project 2 - Problem # 5

#include <iostream>
#include <iomanip>
#include "User.h"
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
   while(end_of_string<=input_stringLength){//while loop to iterate through array and split it at instances of the separator
    if(x==arr_size){//return -1 if number of sep are equal to array size
               return -1;
          }
    if(end_of_string == input_stringLength){
        arr[x++] = input_string.substr(start_of_string,end_of_string);
        return x;
    }
    else if (input_string[end_of_string] == separator){
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

int readLikes(string file_name, User users[], int num_users_stored, int users_arr_size, int max_posts = 50){

    /*
    make an ifstream name file input
    open file_name
    initialize the index to num users stored
    */
    ifstream file_input;
    file_input.open(file_name);
    int index = num_users_stored;

    /*
    if number of users stored is equal to the users array size
    return -2
    */
    if(num_users_stored == users_arr_size){
        return -2;
    }

//if the file is open
if(file_input.is_open()){
    /*
    while there is still data to be proccesed in the file and the index is less than the size of the users array
    initialize a string array of size 500
    initialize line to ""
    initialize arrayLength to 0
    initialize j to 1
    read lines from the file_input file
    split the line at every instance of a seperator and stored the results in a new array "arr"
    initialize an integer array of size max_posts

    while the split array at j does not equal ""
    set arrayLength to j and increment j

    while the length of the line is 0
    if there is still data to be proccesed in the file
    move to the next line, and split the line at every instance of a seperator
    else, return the index (number of likes)

    if the length of the line is not 0
    for int i = 0, when i is less than the arrayLength, increment i
    set the likes array at index i equal to the split array at i + 1 (we need to change the string to an integer)

    set number of posts to the array length
    set the user in the users array at index to the split array at 0
    for in i = 0, when i is less than the array length, increment i
    set the number of likes in the users array at index, at i, to likesarray at i
    set the number of posts in the users array at index to num_posts
    increment the index

    return the index

    */
    while(!file_input.eof() && index < users_arr_size){
        string arr[500];
        string line = "";
        int arrayLength = 0;
        int j = 1;
        getline(file_input, line);
        split(line, ',', arr, 500);
        int LikesArray[max_posts];
       while(arr[j] != ""){
            arrayLength = j;
            j++;
        }
        while(line.length() == 0){
            if(!file_input.eof()){
            getline(file_input,line);
            split(line, ',', arr, 500);
            }
            else{
                return index;
            }
        }
        if(line.length() != 0){
        for(int i = 0; i < arrayLength; i++){
          LikesArray[i] = stoi(arr[i+1]);
       }
       int num_posts = arrayLength;
        users[index].setUsername(arr[0]);
        for(int i = 0; i < arrayLength; i++){
          users[index].setLikesAt(i, LikesArray[i]);
      }
        users[index].setNumPosts(num_posts);
        index++;
       }
       else{
           index++;
       }
    }
return index;
        }
else{ //if the file fails to open, return -1
    return -1;
}
    }


int main(){
    User users[10];
    readLikes("ReadLikesTester.txt", users, 0, 10, 50);
    assert(readLikes("ReadLikesTester.txt", users, 0, 10, 50) == 4);
    assert(readLikes("ReadLikesTester.txt", users, 6, 10, 50) == 10);
    assert(readLikes("ReadLikesTester.txt", users, 10, 10, 50) == -2);
    assert(readLikes("bruh.txt", users, 0, 10, 50) == -1);
}