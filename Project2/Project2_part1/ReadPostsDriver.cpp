// CSCI 1300 Fall 2022
// Author: Jake Joyner
// Recitation: 202 – Christopher Ojukwu
// Project 2 - Problem # 2

#include <iostream>
#include "Post.h"
#include <iomanip>
#include <fstream>
#include <cassert>

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

int readPosts(string file_name, Post posts[], int num_posts_stored, int posts_arr_size){

/*
initialize file input variable to store text file
open file input as an ifstream file
set counter to the number of posts that are already in the array
initialize and declare line variable to store lines from the text file
initialize array to store results from split function
*/
ifstream file_input;
file_input.open(file_name);
int num_lines = num_posts_stored;
string line = "";
string arr[posts_arr_size];

/*
if the file is opened succesfully
if the number of posts stored equals the array size
return -2
*/
if (file_input.is_open()){
    if (num_posts_stored == posts_arr_size){
     return -2;
    }
/*
while there is still data to be proccesed in the file
store the data from each line of the file in the line variable
split the function at every instance of a separator
if the split function returns a value of 4 (there are 4 parameters in the line) and the line is not empty
set the body equal to the array at index 0
set the author equal to the array at index 1
set the date equal to the array at index 3
set the posts array at the index after the index where the posts are already stored
to the body, author, num likes, and date using the parametized constructor
increment the counter

if the number of lines is equal to the size of the posts array
break
    */
    while (!file_input.eof()){
        getline(file_input, line);
        split(line, ',',arr,4);
            if(split(line, ',', arr, 4)==4 && line.length() != 0){
            string body = arr[0];
            string post_author = arr[1]; 
            int num_likes = stoi(arr[2]);
            string date = arr[3];
            posts[num_lines] = Post(body, post_author, num_likes, date);
            num_lines++;

            if(num_lines == posts_arr_size){
                break;
            }
        }

    }

/*
return the index counter (number of posts stored with 4 parameters)
close the file

if the file is not opened succesfully, return -1
return a value of -1
*/
return num_lines;
file_input.close();
}
else{
    return -1; 
    }


if (file_input.fail()){

    return -1;
}

}

int main()
{ // test cases
Post posts[100]; 
// Post my_post_1 = Post("new post","Xuefei", 10, "10/02/22");   
// posts[0] = my_post_1;

readPosts("TestOneFile.txt", posts, 0, 100);
// Code to print the values 
assert(posts[0].getPostAuthor() == "michelleryan");
assert(posts[1].getPostAuthor() == "cuboulder");
assert(posts[49].getPostAuthor() == "benjohnston");
cout << posts[49].getPostBody() << endl;
//Expected Output: "What better way to celebrate #NationalPuppyDay than with some pics of an excellently dressed @rudytheocfrenchie"

posts[0] = Post("new post","user1", 10, "10/02/22");
posts[1] = Post("Hello!","user2", 9, "10/04/22");
posts[2] = Post("Hey!","user3", 9, "10/04/22");
assert(posts[0].getPostDate() == "10/02/22");
}