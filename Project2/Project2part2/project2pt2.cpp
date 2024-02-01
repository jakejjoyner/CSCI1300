// CSCI 1300 Fall 2022
// Author: Jake Joyner
// Recitation: 202 – Christopher Ojukwu
// Project 2 - driver

#include <iostream>
#include <iomanip>
#include <cassert>
#include <fstream>
#include "Buffchat.h"

using namespace std;

int main(){
    //Buffchat object to the default constructer
    Buffchat b = Buffchat();
    for(;;){ //infinite loop to print main menu until exit
        int choice; //initialize choice variable
        /*
        print main menu
        */
        cout << "======Main Menu=====" << endl;
        cout << "1. Read posts " << endl;
        cout << "2. Print Posts By Year" << endl;
        cout << "3. Read Likes" << endl;
        cout << "4. Get Likes " << endl;
        cout << "5. Find users with matching tag" << endl;
        cout << "6. Add a new post" << endl;
        cout << "7. Print popular posts for a year" << endl;
        cout << "8. Find least active user" << endl;
        cout << "9. Find unique likes for a post author" << endl;
        cout << "10. Quit" << endl;
        cin >> choice; //take user input
        //if choice is greater than 10 or less than 1, output "invalid input"
        if(choice > 10 || choice < 1){
            cout << "Invalid input" << endl;
        }
        //if choice is 6, output goodbye and break
        else if(choice == 10){
            cout << "Good bye!" << endl;
            break;
        }
        /*
        if choice is 1
        output "Enter a post file name"
        initialize file_name
        ask user for input
        call readposts function with filename
        if readposts returns -1, output "File failed to open. No posts saved to the database."
        if readposts returns -2, output "Database is already full. No posts were added."
        if readposts outputs 50, output "Database is full. Some posts may have not been added." and add 50 to the number of posts stored
        if readposts returns some value between 0 and 50, or 0, output "Total posts in the database: " <return value>
        add return value to the number of posts stored
        */
        else if(choice == 1){
            cout << "Enter a post file name:" << endl;
            string file_name;
            cin >> file_name;
            int num_posts = b.readPosts(file_name);
            if(num_posts == -1){
                cout << "File failed to open. No posts saved to the database." << endl;
            }
            if(num_posts == -2){
                cout << "Database is already full. No posts were added." << endl;
            }
            if(num_posts == 50){
                cout << "Database is full. Some posts may have not been added." << endl;
            }
            if(num_posts < 50 && num_posts >= 0){
                cout << "Total posts in the database: " << num_posts << endl;
            }
        }
        /*
        if choice is 2
        output "Enter the year(YY):"
        initialize year
        user input
        call printPostsByYear with year variable
        */
        else if(choice == 2){
            cout << "Enter the year(YY):" << endl;
            string year;
            cin >> year;
            b.printPostsByYear(year);
        }
        /*
        if choice is 3
        initialize file_name
        output "Enter a user file name:"
        user input
        call readLikes function using file_name
        if readLikes returns -1, output "File failed to open. No users saved to the database."
        if readLikes returns -2, output "Database is already full. No users were added."
        if readLikes returns 50, output Database is full. Some users may have not been added." and add 50 to number of users stored
        if readLikes returns some value between 0 and 50, or 0, output "Total users in the database: " <return value>
        add return value to number of users stored
        */
        else if(choice == 3){
            string file_name;
            cout << "Enter a user file name:" << endl;
            cin >> file_name;
            int num_likes = b.readLikes(file_name);
            if(num_likes == -1){
                cout << "File failed to open. No users saved to the database." << endl;
            }
            if(num_likes == -2){
                cout << "Database is already full. No users were added." << endl;
            }
            if(num_likes == 50){
                cout << "Database is full. Some users may have not been added." << endl;
            }
            if(num_likes < 50 && num_likes >= 0){
                cout << "Total users in the database: " << num_likes << endl;
            }
        }
        /*
        if choice is 4
        initialize post_author
        initialize username
        output "Enter a post author:"
        user input
        output "Enter a user name:"
        user input
        call getLikes function
        if getLikes returns 0, output <username> " has not liked the post posted by " <postauthor>
        if getLikes returns -1, output <username> " has not viewed the post posted by " <post_author>
        if getLikes returns -2, output "Database is empty." 
        if getLikes returns -3, output <username> "or" <post_author> "does not exist"
        if getLikes returns a value between 0 and 50, output <username> " liked the post posted by " <post_author> " " <return value> " times"
        */
        else if(choice == 4){
            string post_author;
            string username;
            cout << "Enter a post author:" << endl;
            cin >> post_author;
            cout << "Enter a user name:" << endl;
            cin >> username;
            int get_likes = b.getLikes(post_author, username);
            if(get_likes == 0){
                cout << username << " has not liked the post posted by " << post_author << endl;
            }
            if(get_likes == -1){
                cout << username << " has not viewed the post posted by " << post_author << endl;
            }
            if(get_likes == -2){
                cout << "Database is empty." << endl;
            }
            if(get_likes == -3){
                cout << username << " or " << post_author << " does not exist." << endl;
            }
            if(get_likes > 0 && get_likes < 50){
                cout << username << " liked the post posted by " << post_author << " " << 
                get_likes << " times" << endl;
            }
        }
        /*
        if choice is 5
        initialize username_tag
        output "Enter a tag"
        user input
        call findTagUser using username_tag and other parameters
        */
        else if(choice == 5){
            string username_tag;
            cout << "Enter a tag:" << endl;
            cin >> username_tag;
            b.findTagUser(username_tag);
        }
        /*
        if choice is 6
        initialize strings: post_body, post_author, and date
        output "Enter a post body:"
        user input
        output "Enter a post author:"
        user input
        output "Enter a date(mm/dd/yy):"
        user input
        call addPost function with parameters post body, post author, and date
        if addPost returns 1, output <post_author>"'s post added successfully"
        if addPost returns 0, output "Database is already full. " <post_author>"'s post was not added."
        */
        else if(choice == 6){
            string post_body;
            string post_author;
            string date; 
            cout << "Enter a post body:" << endl;
            cin >> post_body;
            cout << "Enter a post author:" << endl;
            cin >> post_author;
            cout << "Enter a date(mm/dd/yy):" << endl;
            cin >> date;
            int add_post = b.addPost(post_body,post_author,date);

            if(add_post == 1){
                cout << post_author << "'s post added successfully" << endl;
            }
            if(add_post == 0){
                cout << "Database is already full. " << post_author << "'s post was not added" << endl;
            }
        }
        /*
        if choice is 7
        initialize count variable as integer and initialize year variable as string
        output "Enter the number of posts:"
        user input
        output "Enter the year(YY):"
        user input
        call printPopularPosts function
        */
        else if(choice == 7){
            int count;
            string year;
            cout << "Enter the number of posts:" << endl;
            cin >> count;
            cout << "Enter the year(YY):" << endl;
            cin >> year;
            b.printPopularPosts(count, year);
        }
        else if (choice == 8){
            User u = b.findLeastActiveUser();
            if(u.getUsername() == ""){
                cout << "There are no users stored" << endl;
            }
            if(u.getUsername() != ""){
                cout << u.getUsername() << " is the least active user" << endl;
            }
        }
        else if (choice == 9){
            string post_author;
            int uniqueLikes;
            cout << "Enter a post author:" << endl;
            cin >> post_author;
            uniqueLikes = b.countUniqueLikes(post_author);
            if(uniqueLikes > 0){
                cout << "The posts posted by " << post_author << " have been liked by " << uniqueLikes << " unique users." << endl;
            }
            if (uniqueLikes == 0){
                cout << "The posts posted by " << post_author << " have received 0 likes so far." << endl;
            }
            if (uniqueLikes == -1){
                cout << "The posts posted by " << post_author << " have not been viewed by anyone." << endl;
            }
            if (uniqueLikes == -2){
                cout << "Database is empty." << endl;
            }
        }
    }
}