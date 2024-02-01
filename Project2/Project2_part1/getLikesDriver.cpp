// CSCI 1300 Fall 2022
// Author: Jake Joyner
// Recitation: 202 – Christopher Ojukwu
// Project 2 - Problem # 6

#include <iostream>
#include <iomanip>
#include "User.h"
#include "Post.h"

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

/*
initialize i to 0
if the number of posts stored is less than or equal to 0 or the number of users stored is less than or equal to 0, return -2
*/
int getLikes(string post_author, Post posts[], int num_posts_stored, string username, User users[], int num_users_stored){
    int i = 0;
    if(num_posts_stored <= 0 || num_users_stored <= 0){
        return -2;
    }
/*
while i is less than the number of posts stored
if the post author at index i equals the posts author
for int j equals 0, while j is less than the number of users stored, increment j
if the username at index j equals the username
return the Likesat index j, i
if no matches are found, return -3
*/
    while(i < num_posts_stored){
        if(posts[i].getPostAuthor() == post_author){
            for(int j = 0; j < num_users_stored; j++){
             if(users[j].getUsername() == username){
                 return users[j].getLikesAt(i);
             }
            }
            return -3;
        }
        else{
            i++;
        }
    }
return -3;
}

int main(){
    string username = "bruh";
    string post_author = "jamesbartholomythe3rd";
    Post posts[50];
    User users[50];
    assert(getLikes(post_author, posts, 50, username, users, 50) == -3);
    //Creating 3 posts 
    Post posts1[3]; 
    Post my_post_1 = Post("Hello!","Xuefei", 10, "10/02/22");
    posts1[0] = my_post_1;
    Post my_post_2 = Post("new post","Morgan", 9, "10/04/22");
    posts1[1] = my_post_2;
    Post my_post_3 = Post("Hey!","Jot", 10, "10/05/22");
    posts1[2] = my_post_3;
    assert(getLikes(post_author, posts1, 3, "Username", users, 50) == -3);
}