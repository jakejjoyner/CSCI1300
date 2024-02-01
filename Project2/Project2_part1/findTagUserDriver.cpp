// CSCI 1300 Fall 2022
// Author: Jake Joyner
// Recitation: 202 – Christopher Ojukwu
// Project 2 - Problem # 7

#include <iostream>
#include <iomanip>
#include "Post.h"
#include "User.h"

using namespace std;

void findTagUser(string username_tag, User users[], int num_users_stored){
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

int main(){
     User user_array[5];
    int likes1[3] = {1, 0, -1};
    int likes2[3] = {4, 5, 0};
    user_array[0] = User("johnak", likes1, 3);
    user_array[1] = User("harry20", likes2, 3);
    user_array[2] = User("jake22", likes2, 3);
    user_array[3] = User("elephant6", likes2, 3);
    user_array[4] = User("fflol22", likes1, 3);
    findTagUser("ak", user_array, 5);
    //Here are all the usernames that contain ak
    //johnak
    //jake22

    User user_array1[5];
    int likes3[3] = {1, 0, -1};
    int likes4[3] = {4, 5, 0};
    user_array1[0] = User("john22", likes3, 3);
    user_array1[1] = User("harry73", likes4, 3);
    user_array1[2] = User("jake32", likes4, 3);
    user_array1[3] = User("elephant6", likes4, 3);
    user_array1[4] = User("fflol4", likes3, 3);
    findTagUser("akk", user_array1, 5);
    //Expected output : No matching user found

    User user_array2[5];
    findTagUser("aa", user_array2, 0);
    //Expected output: No users are stored in the database

    findTagUser("22", user_array, 5);
    //Expeted output: Here are all the usernames that contain 22
    //jake22
    //fflol22
}