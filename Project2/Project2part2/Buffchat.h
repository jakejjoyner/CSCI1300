// CSCI 1300 Fall 2022
// Author: Jake Joyner
// Recitation: 202 – Christopher Ojukwu
// Project 2 - buffchat class

#ifndef Buffchat
#include <iostream>
#include <iomanip>
#include "Post.h"
#include "User.h"

using namespace std;

class Buffchat{
    private: //private objects
        const static int posts_size_ = 50;
        const static int users_size_ = 50;
        Post posts_[posts_size_];
        User users[users_size_];
        int num_posts_;
        int num_users_;
    public: //public objects
        Buffchat();
        int getPostSize();
        int getUserSize();
        int getNumPosts();
        int getNumUsers();
        int readPosts(string file_name);
        void printPostsByYear(string year);
        int readLikes(string file_name);
        int getLikes(string post_author, string username);
        void findTagUser(string username_tag);
        bool addPost(string post_body, string post_author, string date);
        void printPopularPosts(int count, string year);
        User findLeastActiveUser();
        int countUniqueLikes(string post_author);
};

#endif