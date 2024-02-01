// CSCI 1300 Fall 2022
// Author: Jake Joyner
// Recitation: 202 – Christopher Ojukwu
// Project 2 - Problem # 8

#include <iostream>
#include <iomanip>
#include <cassert>
#include <fstream>

#include "User.h"
#include "Post.h"

using namespace std;

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

int readPosts(string file_name, Post posts[], int num_posts_stored, int posts_arr_size){

ifstream file_input;//initialize file input variable to store text file
file_input.open(file_name);//open file input as an ifstream file
int num_lines = num_posts_stored; //set counter to the number of posts that are already in the array
string line = "";//initialize and declare line variable to store lines from the text file
string arr[posts_arr_size];//initialize array to store results from split function

if (file_input.is_open()){//if the file is opened succesfully
    if (num_posts_stored == posts_arr_size){ //if the number of posts stored equals the array size
     return -2;//return -2
    }
    while (!file_input.eof()){//while there is still data to be proccesed in the file
        getline(file_input, line);//store the data from each line of the file in the line variable
        split(line, ',',arr,4);///split the function at every instance of a separator
            if(split(line, ',', arr, 4)==4 && line.length() != 0){//if the split function returns a value of 4 (there are 4 parameters in the line)
        //and the line is not empty
            string body = arr[0]; //set the body equal to the array at index 0
            string post_author = arr[1]; //set the author equal to the array at index 1
            int num_likes = stoi(arr[2]); //set number of likes equal to the array at index 2 (array is a string array so we must convert to an integer first)
            string date = arr[3]; //set the date equal to the array at index 3
            posts[num_lines] = Post(body, post_author, num_likes, date); //set the posts array at the index after the index where the posts are already stored
            //to the body, author, num likes, and date using the parametized constructor
            num_lines++; //increment the counter

            if(num_lines == posts_arr_size){ //if the number of lines is equal to the size of the posts array
                break; //break
            }
        }

    }

return num_lines;//return the index counter (number of posts stored with 4 parameters)
file_input.close(); //close the file
}
else{
    return -1; //if the file is not opened succesfully, return -1
    }


if (file_input.fail()){//if the file is not opened succesfully

    return -1;//return a value of -1
}

}

void PrintPostsByYear(Post posts[], string year, int num_posts_stored){
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

int readLikes(string file_name, User users[], int num_users_stored, int users_arr_size, int max_posts = 50){
    ifstream file_input;
    file_input.open(file_name);
    int index = num_users_stored;
    
    if(num_users_stored == users_arr_size){
        return -2;
    }

if(file_input.is_open()){
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
return index;
        }
else{
    return -1;
}
    }

int getLikes(string post_author, Post posts[], int num_posts_stored, string username, User users[], int num_users_stored){
    int i = 0;
    if(num_posts_stored <= 0 || num_users_stored <= 0){
        return -2;
    }
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

void findTagUser(string username_tag, User users[], int num_users_stored){
    int i = 0;
    int counter = 0;
    string array[100];
    if(num_users_stored <= 0){
        cout << "No users are stored in the database" << endl;
        return;
    }
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
    if(counter == 0){
        cout << "No matching user found" << endl;
        return;
    }
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
    //initialize variables to stored values called to functions
    int num_posts_stored = 0;
    int num_users_stored = 0;
    Post posts[50];
    User users[50];
    for(;;){ //infinite loop to print main menu until exit
        int choice; //initialize choice variable
        /*
        print main menu
        */
        cout << "======Main Menu======" << endl;
        cout << "1. Read Posts " << endl;
        cout << "2. Print Posts By Year" << endl;
        cout << "3. Read Likes" << endl;
        cout << "4. Get Likes " << endl;
        cout << "5. Find users with matching tag" << endl;
        cout << "6. Quit" << endl;
        cin >> choice;
        //if choice is greater than 6 or less than 1, output "invalid input"
        if(choice > 6 || choice < 1){
            cout << "Invalid input." << endl;
        }
        //if choice is 6, output goodbye and break
        else if(choice == 6){
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
            readPosts(file_name, posts, num_posts_stored, 50);
            if(readPosts(file_name, posts, num_posts_stored, 50) == -1){
                cout << "File failed to open. No posts saved to the database." << endl;
            }
            if(readPosts(file_name, posts, num_posts_stored, 50) == -2){
                cout << "Database is already full. No posts were added." << endl;
            }
            if(readPosts(file_name, posts, num_posts_stored, 50) == 50){
                cout << "Database is full. Some posts may have not been added." << endl;
                num_posts_stored += readPosts(file_name, posts, num_posts_stored, 50);
            }
            if(readPosts(file_name, posts, num_posts_stored, 50) < 50 && readPosts(file_name, posts, num_posts_stored, 50) >= 0){
                cout << "Total posts in the database: " << readPosts(file_name, posts, num_posts_stored, 50) << endl;
                num_posts_stored += readPosts(file_name, posts, num_posts_stored, 50);
            }
        }
        /*
        if choice is 2
        output "Enter the year(YY):"
        initialize year
        user input
        call printPostsByYear with year variable and other parameters
        */
        else if(choice == 2){
            cout << "Enter the year(YY):" << endl;
            string year;
            cin >> year;
            PrintPostsByYear(posts, year, num_posts_stored);
        }
        /*
        if choice is 3
        initialize file_name
        output "Enter a user file name:"
        user input
        call readLikes function using file_name and other parameters
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
            readLikes(file_name, users, num_users_stored, 50, 50);
            if(readLikes(file_name, users, num_users_stored, 50, 50) == -1){
                cout << "File failed to open. No users saved to the database." << endl;
            }
            if(readLikes(file_name, users, num_users_stored, 50, 50) == -2){
                cout << "Database is already full. No users were added." << endl;
            }
            if(readLikes(file_name, users, num_users_stored, 50, 50) == 50){
                cout << "Database is full. Some users may have not been added." << endl;
                num_users_stored += readLikes(file_name, users, num_users_stored, 50, 50);
            }
            if(readLikes(file_name, users, num_users_stored, 50, 50) < 50 && readLikes(file_name, users, num_users_stored, 50, 50) >= 0){
                cout << "Total users in the database: " << readLikes(file_name, users, num_users_stored, 50, 50) << endl;
                num_users_stored += readLikes(file_name, users, num_users_stored, 50, 50);
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
            getLikes(post_author, posts, num_posts_stored, username, users, num_users_stored);
            if(getLikes(post_author, posts, num_posts_stored, username, users, num_users_stored) == 0){
                cout << username << " has not liked the post posted by " << post_author << endl;
            }
            if(getLikes(post_author, posts, num_posts_stored, username, users, num_users_stored) == -1){
                cout << username << " has not viewed the post posted by " << post_author << endl;
            }
            if(getLikes(post_author, posts, num_posts_stored, username, users, num_users_stored) == -2){
                cout << "Database is empty." << endl;
            }
            if(getLikes(post_author, posts, num_posts_stored, username, users, num_users_stored) == -3){
                cout << username << " or " << post_author << " does not exist." << endl;
            }
            if(getLikes(post_author, posts, num_posts_stored, username, users, num_users_stored) > 0 && getLikes(post_author, posts, num_posts_stored, username, users, num_users_stored) < 50){
                cout << username << " liked the post posted by " << post_author << " " << 
                getLikes(post_author, posts, num_posts_stored, username, users, num_users_stored) << " times" << endl;
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
            findTagUser(username_tag, users, num_users_stored);
        }
    }
}

