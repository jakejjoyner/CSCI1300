// CSCI 1300 Fall 2022
// Author: Jake Joyner
// Recitation: 202 – Christopher Ojukwu
// Project 2 - Problem # 4

#include <iostream>
#include "User.h"

using namespace std;
/* default constructor
set username equal to ""
set all indeces of likes array to -1
set number of posts to 0
*/
User::User(){ 
    username_ = "";
    for(int i = 0; i < size_; i++){
        likes_[i] = -1;
    }
    num_posts_ = 0;
}

/*
parametized constructor
if the number of posts is less than the size
set all indeces of the likes array to the other array for num_posts
for num posts fill the rest of the array with -1
if number of posts is equal to the size
for int i = 0, while i is less the number of posts, increment i
set all indeces of likes array to the other array
set username ata member to username
set num posts data member to num posts
*/
User::User(string username, int array[], int num_posts){
    if(num_posts < size_){
        for(int i = 0; i <= num_posts; i++){
            likes_[i] = array[i];
        }
        for(int i = num_posts; i <= size_; i++){
            likes_[i] = -1;
        }
    }
    if(num_posts == size_){
        for(int i = 0; i <= num_posts; i++){
            likes_[i] = array[i];
        }
    }
    username_ = username;
    num_posts_ = num_posts;
}

/*
get username returns username
*/
string User::getUsername(){
    return username_;
}

/*
set username sets the username data member to username
*/
void User::setUsername(string username){
    username_ = username;
}

/*
getLikesAt returns -2 if pos_id is greater than or equal to the array length or if post_id is less than 0
else, returns likes at post_id
*/
int User::getLikesAt(int post_id){
    int getArrayLength = sizeof(likes_) / sizeof(int);
    if(post_id >= getArrayLength || post_id < 0){
        return -2;
    }
    else{
    return likes_[post_id];
    }
}

/*
if post_id is less than the array length and post_id is greater than or equal to 0 and num likes is greater than or equal to -1 and
number of likes is less than or equal to 10
set likes at the post_id equal to number of likes and return 1

return 0
*/
bool User::setLikesAt(int post_id, int num_likes){
    int getArrayLength = sizeof(likes_) / sizeof(int);
    if(post_id < getArrayLength && post_id >= 0 && num_likes >= -1 && num_likes <= 10){
        likes_[post_id] = num_likes;
        return 1;
    }
    else{
        return 0;
    }
}

/*
getNumPosts returns num posts
*/
int User::getNumPosts(){
    return num_posts_;
}

/*
setNumPosts takes in posts
if posts is greater than 0 and posts is less than size
set number of posts to posts
*/
void User::setNumPosts(int posts){
    if(posts > 0 && posts < size_){
        num_posts_ = posts;
    }
}

/*
getSize returns size
*/
int User::getSize(){
    return size_;
}