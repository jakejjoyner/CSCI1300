// CSCI 1300 Fall 2022
// Author: Jake Joyner
// Recitation: 202 – Christopher Ojukwu
// Project 2 - Problem # 1

#include <iostream>
#include <iomanip>
#include "Post.h"
#include <cassert>

using namespace std;

int main()
{
    Post my_post_1 = Post(); // default constructor
    cout << "Post author " << my_post_1.getPostAuthor() << endl;
    assert(my_post_1.getPostAuthor() == "");
    cout << "Post body " << my_post_1.getPostBody() << endl;
    assert(my_post_1.getPostBody() == "");
    cout << "Post date " << my_post_1.getPostDate() << endl;
    assert(my_post_1.getPostDate() == "");
    cout << "Post likes " << my_post_1.getPostLikes() << endl;
    assert(my_post_1.getPostLikes() == 0);

    Post my_post_2 = Post("new post","Jake", 10, "10/19/22"); // parameterized constructor
    cout << "Post author " << my_post_2.getPostAuthor() << endl;
    assert(my_post_2.getPostAuthor() == "Jake");
    cout << "Post body " << my_post_2.getPostBody() << endl;
    assert(my_post_2.getPostBody() == "new post");
    cout << "Post date " << my_post_2.getPostDate() << endl;
    assert(my_post_2.getPostDate() == "10/19/22");
    cout << "Post likes " << my_post_2.getPostLikes() << endl;
    assert(my_post_2.getPostLikes() == 10);
    my_post_2.setPostBody("updated post");
    cout << "New Post body " << my_post_2.getPostBody() << endl;
    my_post_2.setPostAuthor("updated author");
    cout << "New Author " << my_post_2.getPostAuthor() << endl;
    my_post_2.setPostLikes(100);
    cout << "New Amount of Likes " << my_post_2.getPostLikes() << endl;
    my_post_2.setPostDate("new date");
    cout << "New Date " << my_post_2.getPostDate() << endl;

    return 0;
}