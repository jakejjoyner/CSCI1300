// CSCI 1300 Fall 2022
// Author: Jake Joyner
// Recitation: 202 – Christopher Ojukwu
// Project 2 - Problem # 4

#ifndef User
#include <iostream>
#include <iomanip>

using namespace std;

class User{
    private: //private class objects
        string username_;
        static const int size_ = 50;
        int likes_[size_];
        int num_posts_;
    public: //public class objects
        User();
        User(string username, int array[], int num_posts);
        string getUsername();
        void setUsername(string username);
        int getLikesAt(int post_id);
        bool setLikesAt(int post_id, int num_likes);
        int getNumPosts();
        void setNumPosts(int posts);
        int getSize();
};

#endif