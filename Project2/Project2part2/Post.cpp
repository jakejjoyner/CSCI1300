// CSCI 1300 Fall 2022
// Author: Jake Joyner
// Recitation: 202 – Christopher Ojukwu
// Project 2 - Problem # 1

#include <iostream>
#include "Post.h"

using namespace std;

Post::Post(){ //default constructor
    body_ = "";
    post_author_ = "";
    date_ = "";
    num_likes_ = 0;
}

Post::Post(string body1, string post_author1, int num_likes1, string date1){ //parametarized constructor
    body_ = body1;
    post_author_ = post_author1;
    num_likes_ = num_likes1;
    date_ = date1;
}

string Post::getPostBody(){ //for object getPostBody
    return body_; //return the body of the post
}

void Post::setPostBody(string post_body){ //for setPostBody
    body_ = post_body; //set the body of the post to the new updated body
}

string Post::getPostAuthor(){// for get post author
    return post_author_;//return post author
}

void Post::setPostAuthor(string author){//for set post author
    post_author_ = author;//set post author to new post author
}

int Post::getPostLikes(){//for get post likes
    return num_likes_;//return the number of likes
}

void Post::setPostLikes(int likes){//for set post likes
    if(likes >= 0){//if the number of likes is a positive integer greater than 0
        num_likes_ = likes;//set the number of likes to the updated number of likes
    }
}

string Post::getPostDate(){//for get post date
    return date_;//return the date
}

void Post::setPostDate(string post_date){//for set post date
    date_ = post_date;//set the post date to the new post date
}