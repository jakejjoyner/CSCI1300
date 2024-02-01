// CSCI 1300 Fall 2022
// Author: Jake Joyner
// Recitation: 202 – Christopher Ojukwu
// Project 2 - Problem # 4

#include <iostream>
#include <iomanip>
#include "User.h"

using namespace std;

int main(){
    int testLikes[] = {-1,1,-1,8,8,3,-1,5,10,2,6,-1,6,7,8,4,1,7,1,8,-1,7,8,7,7,4,4,9,10,5,5,5,-1,8,-1,2,9,8,-1,-1,2,0,7,4,10,5,8,3,0,6};
    User u2 = User("bookworm43", testLikes, 50);
    User u3 = User();
    for(int i = 0; i < 50; i++){
    cout << u3.getLikesAt(i) << endl;
    }
    /* Expected Output:
    -1
    -1
    -1
    -1
    -1
    -1
    -1
    -1
    -1
    -1
    -1
    -1
    -1
    -1
    -1
    -1
    -1
    -1
    -1
    -1
    -1
    -1
    -1
    -1
    -1
    -1
    -1
    -1
    -1
    -1
    -1
    -1
    -1
    -1
    -1
    -1
    -1
    -1
    -1
    -1
    -1
    -1
    -1
    -1
    -1
    -1
    -1
    -1
    -1
    -1
    */
    cout << u2.getUsername() << endl;
    // Expected Output 
    //bookworm43
    cout << u2.getNumPosts() << endl;
    // Expected Output 
    //50
        
    // test values in likes_array at random indices
    cout << u2.getLikesAt(0) << endl;
    cout << u2.getLikesAt(10) << endl;
    cout << u2.getLikesAt(50) << endl;
    // Expected Output 
   // -1
    //6
    //-2 
}