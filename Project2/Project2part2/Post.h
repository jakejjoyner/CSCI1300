// CSCI 1300 Fall 2022
// Author: Jake Joyner
// Recitation: 202 – Christopher Ojukwu
// Project 2 - Problem # 1

#ifndef Post
#include <iostream>
#include <iomanip>

using namespace std;

class Post{
    private: //initialize private class objects
        string body_;
        string post_author_;
        int num_likes_;
        string date_;
    public: //initialize public class objects
        Post();
        Post(string body1, string post_author1, int num_likes1, string date1);
        string getPostBody();
        void setPostBody(string post_body);
        string getPostAuthor(); 
        void setPostAuthor(string author);
        int getPostLikes();
        void setPostLikes(int likes);
        string getPostDate();
        void setPostDate(string postDate);
};

#endif