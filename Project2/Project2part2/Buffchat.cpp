// CSCI 1300 Fall 2022
// Author: Jake Joyner
// Recitation: 202 – Christopher Ojukwu
// Project 2 - buffchat implementation

#include <iostream>
#include <iomanip>
#include "Buffchat.h"
#include <fstream>
#include <stdio.h>

using namespace std;

/*
Default constructor
sets num_posts and num_users to 0
*/
Buffchat::Buffchat(){
    num_posts_ = 0;
    num_users_ = 0;
}

/*
getPostSize returns posts_size_
*/
int Buffchat::getPostSize(){
    return posts_size_;
}

/*
getUserSize returns users_size
*/
int Buffchat::getUserSize(){
    return users_size_;
}

/*
getNumPosts returns num_posts_
*/
int Buffchat::getNumPosts(){
    return num_posts_;
}

/*
getNumUsers returns num_users_
*/
int Buffchat::getNumUsers(){
    return num_users_;
}
//initialize posts and users array of size 50
Post posts[50];
User users[50];

//split function
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

int Buffchat::readPosts(string file_name){
/*
initialize file input variable to store text file
open file input as an ifstream file
set counter to the number of posts that are already in the array
initialize and declare line variable to store lines from the text file
initialize array to store results from split function
*/
ifstream file_input;
file_input.open(file_name);
int num_lines = num_posts_;
string line = "";
string arr[50];

/*
if the file is opened succesfully
if the number of posts stored equals the array size
return -2
*/
if (file_input.is_open()){
    if (num_posts_ == 50){
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

            if(num_lines == 50){
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
num_posts_ = num_lines;
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

void Buffchat::printPostsByYear(string year){
    int num_posts_stored = num_posts_; // set num_posts_stored to num_posts_ data member
    string arr[3]; //initialize a string array of size 3

    /* if the number of posts stored is less than or equal to 0
    output "No posts are stored" and return
    */
    if(num_posts_stored <= 0){
        cout << "No posts are stored" << endl;
        return;
    }

    int i = 0; //initialize i to 0
    int Counter = 0; // initialize counter to 0
    string array[100]; //initialize a string array of size 100

    /* while i is less than the number of posts stored:

    split the date from the posts array at i, in order to find the year
    if the year in the posts array at index i is equal to the year we want to find:
    set a new array at index i equal to the post body from the posts array
    increment i
    increment the counter
    if the year in the posts array at index i is not equal to the year we want to find:
    increment i
    */
    while(i < num_posts_stored){
        split(posts[i].getPostDate(), '/', arr, 3);
        if(arr[2] == year){
            array[i] = posts[i].getPostBody();
            i++;
            Counter++;
        }
        else{
            i++;
        }
        }

    /* if there are no posts found for the year that the user inputted (e.g. counter = 0)
    output "No posts stored for year" <user inputted year>
    return
    */

    if(Counter == 0){
        cout << "No posts stored for year " << year << endl;
        return;
    }

    /* if there are posts found for the year inputted by the user
    output "Here is a list of posts for year" <user inputted year>
    set j equal to 0
    while j is less than i:
    if the length of the array we created (holding the posts for year <year>) at j does not equal 0, output the array at j.
    */
    cout << "Here is a list of posts for year " << year << endl;
    for(int j = 0; j < i; j++){
        if(array[j].length() != 0){
        cout << array[j] << endl;
    }
}
}

int Buffchat::readLikes(string file_name){
    /*
    set num users stored to num users data member
    set users array size to users size data member
    set max posts to 50
    */
    int num_users_stored = num_users_;
    int users_arr_size = users_size_;
    int max_posts = 50;
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
num_users_ = index;
return index;
        }
else{ //if the file fails to open, return -1
    return -1;
}
    }
/*
initialize i to 0
if the number of posts stored is less than or equal to 0 or the number of users stored is less than or equal to 0, return -2
*/
int Buffchat::getLikes(string post_author, string username){
    /*
    set num posts stored to num posts data member
    set num users stored to num users data member
    initialize i to 0
    */
    int num_posts_stored = num_posts_;
    int num_users_stored = num_users_;
    int i = 0;

    /*
    if the number of posts sotred is less than or equal to zero or if the number of users stored is less than or equal to 0, return -2
    */
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

void Buffchat::findTagUser(string username_tag){
    int num_users_stored = num_users_; //set num users stored to num users data member
    /* initialize i to 0
    initialize counter to 0
    initialize a string array of size 100
    */
    int i = 0;
    int counter = 0;
    string array[100];
    /*
    if the number of users stored is less than or equal to 0
    output "no users are stored in the database"
    */
    if(num_users_stored <= 0){
        cout << "No users are stored in the database" << endl;
        return;
    }
    /*
    while i is less than the number of users stored
    store the username from users at index i in a string

    initialize j to 0
    while j is less than the length of the username at index i
    if the username has the specified username tag in it
    store that username in a new string array and increment the counter

    increment i
    */
    while(i < num_users_stored){
        string username_at_i = users[i].getUsername();
        for(int j = 0; j < username_at_i.length(); j++){
        if(username_at_i.substr(j,username_tag.length()) == username_tag){
            array[i] = users[i].getUsername();
            counter++;
        }
        }
        i++;
    }

    /*
    if the counter is equal to 0 (no matching users were found)
    output "No matching user found"
    */
    if(counter == 0){
        cout << "No matching user found" << endl;
        return;
    }
    /*
    if one or more matching users are found
    output "Here are all the usernames that contain" <username_tag>
    initialize i to 0
    while i is less than the number of users stored
    output all the matching usernames stored in our array (while skipping empty lines)

    return when the for loop is finished
    */
    else {
        cout << "Here are all the usernames that contain " << username_tag << endl;
        for(int i = 0; i < num_users_stored; i++){
            if(array[i] != "")
            cout << array[i] << endl;
        }
        return;
    }

}

bool Buffchat::addPost(string post_body, string post_author, string date){
    /*
    for int i = 0, while is is less than the posts size, increment i

    if the post body at index i is empty
    set post author to post author
    set post body to post body
    set post date to date
    set posts likes to 0
    at index i of the users array, set the likes at i to -1
    increment the number of posts
    return true

    else, return false
    */
    for(int i = 0; i < posts_size_; i++){
        if(posts[i].getPostDate() == ""){
            posts[i].setPostAuthor(post_author);
            posts[i].setPostBody(post_body);
            posts[i].setPostDate(date);
            posts[i].setPostLikes(0);
             users[i].setLikesAt(i,-1);
            num_posts_++;
            return 1;
        }
    }
    return 0;
}

void Buffchat::printPopularPosts(int count, string year){
    int num_posts_stored = num_posts_; //set the number of posts stored to the number of posts data member
    string arr[3]; //initialize a string array of size 3

    /* if the number of posts stored is less than or equal to 0
    output "No posts are stored" and return
    */
    if(num_posts_stored <= 0){
        cout << "No posts are stored" << endl;
        return;
    }

    int i = 0; //initialize i to 0
    int Counter = 0; // initialize counter to 0
    int j = 0; //initialize j to 0
    string body_array[posts_size_]; //initialize a string array of size posts_size
    int likes_array[posts_size_]; //initialize an integer array of size posts_size

    /* while i is less than the number of posts stored:

    split the date from the posts array at i, in order to find the year
    if the year in the posts array at index i is equal to the year we want to find:
    set the body array at index j equal to the post body from the posts array
    set the likes array at index j equal to the posts likes from the posts array
    increment i
    increment j
    increment the counter
    if the year in the posts array at index i is not equal to the year we want to find:
    increment i
    */
    while(i < num_posts_){
        split(posts[i].getPostDate(), '/', arr, 3);
        if(arr[2] == year){
            body_array[j] = posts[i].getPostBody();
            likes_array[j] = posts[i].getPostLikes();
            i++;
            Counter++;
            j++;
        }
        else{
            i++;
        }
        }
    
    /*
    if the counter is equal to 0, output "No posts stored for year "  <year>, and return
    */
    if(Counter == 0){
        cout << "No posts stored for year " << year << endl;
        return;
    }
    /*
    if the counter is greater than or equal to the user inputted count,
    output "Top " <count> " posts for year " <year>

    for int j = 0, while j is less than the posts size, increment j
    if the length of the body array at j is not equal to 0,
    and if the likes array at j is greater than the likes array at j + 1
    and if the likes array at j is greater than the likes array at j + 2

    output <likes_array @ j> " likes:" <body_array @ j>

    return
    */
    if(Counter >= count){
        cout << "Top " << count << " posts for year " << year << endl;
        for (int j = 0; j < posts_size_; j++){
        if(body_array[j].length() != 0 && likes_array[j] > likes_array[j+1] && likes_array[j] > likes_array[j+2]){
                cout << likes_array[j] << " likes: " << body_array[j] << endl;
            }
        }
    return;
}
/*
if the user inputted count is greater than the Counter
output "There are fewer than " <count> " posts for year " <year> ". Top " <Counter> " posts for year " <year>

for int i = 0, while i is less than or equal to Counter, increment i
if the length of the body array at i does not equal 0
output <likes_array @ i> " likes: " <body_array @ i>

return
*/
    else if(count > Counter){
        cout << "There are fewer than " << count << " posts for year " << year << ". Top " << Counter << " posts for year " << year << endl;
        for(int i = 0; i < num_posts_; i++){
        if(body_array[i].length() != 0){
        cout << likes_array[i] << " likes: " << body_array[i] << endl;
        }
        }
    }
    return;
}

User Buffchat::findLeastActiveUser(){
    /*
    initialize an integer array of size 50
    initialize usernameCounter to 0
    initialize another integer array of size 50
    initialize view counter length to 0
    initialize j to 0
    */
    int counterArray[50];
    int usernameCounter = 0;
    int view_counter[50];
    int view_counter_length = 0;
    int j = 0;

    /*
    for int i = 0, while i is less than 50, increment i
    set the counter array at i equal to 0
    */

    for(int i = 0; i < 50; i++){
        counterArray[i] = 0;
    }
    /*
    if the number of users is 0
    return an empty user object
    */
    if(num_users_ == 0){
        return User();
    }
    /*
    for int i = 0, while i is less than the number of users, increment i
        for int j = 0, while j is less than the number of posts, increment j
            if the users array at index i has a value of likes at j equal to -1
            add that value to the counter array at index i
    */
    for(int i = 0; i < num_users_; i++){
        for(int j = 0; j < num_posts_; j++){
          if(users[i].getLikesAt(j) == -1){
        counterArray[i] += users[i].getLikesAt(j);
          }
        }
      }
    /*
    for int i = 1, while is is less than the number of users, increment i
    if the counter array at i is less than the counter array at i-1
    set the usernameCounter to i

    if the counter array at i is greater than the counter array at i-1
    set the username counter to i-1
    */
    for(int i = 1; i < num_users_; i++){
        if(counterArray[i] < counterArray[i-1]){
            usernameCounter = i;
        }
        else if (counterArray[i] > counterArray[i-1]){
            usernameCounter = i-1;
        }
    }
    /*
    for in i = 1, while i is less than the number of users, increment i
    if the counter array at i is equal to the counter array at the usernameCounter
        return the users array at index i
    
    else
    return the users array at index usernameCounter
    */
    for(int i = 1; i < num_users_; i++){
        if(counterArray[i] == counterArray[usernameCounter]){
                return users[i];
            }
    }
    return users[usernameCounter];

}

int Buffchat::countUniqueLikes(string post_author){
    int counter = 0; //initialize counter to 0
    int view_counter = 0; //initialize view counter to 0

/*
if the number of posts equals 0 or the number of users equals 0
return -2
*/

if(num_posts_ == 0 || num_users_ == 0){
    return -2;
}

/*
for int i = 0, while i is less than the number of posts, increment i
if the post author at posts index i equal the user inputted post author
for int j = 0, while j is less than the number of users, increment j
if the likes at i from the users array at index j do not equal 0 and -1
increment the counter

if the likes at i from the users array at index j equal -1
increment the view counter
*/

for (int i = 0; i < num_posts_; i++){
    if (posts[i].getPostAuthor() == post_author){
        for(int j = 0; j < num_users_; j++){
            if (users[j].getLikesAt(i) != 0 && users[j].getLikesAt(i) != -1){
                counter++;
            }
            if(users[j].getLikesAt(i) == -1){
                view_counter++;
            }
        }
    }
}

//if the counter is greater than 0, return the counter
if(counter > 0){
    return counter;
}

/*
if the counter is equal to 0
    if the view counter is equal to 0, return 0
    else, return -1
else, return 0
*/
else if(counter == 0){
    if(view_counter == 0){
        return 0;
    }
    else{
        return -1;
    }
}
else{
    return 0;
}
}