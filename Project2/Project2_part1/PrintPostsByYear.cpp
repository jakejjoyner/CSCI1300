// CSCI 1300 Fall 2022
// Author: Jake Joyner
// Recitation: 202 – Christopher Ojukwu
// Project 2 - Problem # 3

#include <iostream>
#include "Post.h"
#include <iomanip>
#include <cassert>
#include <fstream>

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
int num_lines = num_posts_stored;
string line = "";//initialize and declare line variable to store lines from the text file
string arr[posts_arr_size];//initialize array to store results from split function

if (file_input.is_open()){//if the file is opened succesfully
    if (num_posts_stored == posts_arr_size){ //if the number of posts stored equals the array size
     return -2;//return -2
    }
    while (!file_input.eof()){//while there is still data to be proccesed in the file
        getline(file_input, line);//store the data from each line of the file in the line variable
        split(line, ',',arr,4);///split the function at every instance of a separator
            if(split(line, ',', arr, 4)==4 && line.length() != 0){//if the split function returns a value of three (there are 3 parameters in the line)
        //and the line is not empty
            string body = arr[0];
            string post_author = arr[1];
            int num_likes = stoi(arr[2]);
            string date = arr[3];
            posts[num_lines] = Post(body, post_author, num_likes, date);
            num_lines++;

            if(num_lines == posts_arr_size){
                break;
            }
        }

    }

return num_lines;//return the index counter (number of posts with three parameters)
  file_input.close();
}
else{
    return -1;
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
        
    

int main(){
    Post posts[100];
    readPosts("TestOneFile.txt", posts, 0, 100);
    PrintPostsByYear(posts, "17", 100);
    //Expected output: No posts stored for year 17
    PrintPostsByYear(posts, "10", 100);
    //Expected output: No posts stored for year 10
    PrintPostsByYear(posts, "22", 100);
    /*Expected output: "Here is a list of posts for year 22
    It's National Live Creative Day! What better way to celebrate than showcasing our creative talented and passionate Buffs!
    We had so much fun yesterday at the Be Involved Fair!
    Yesterday was such a beautiful start to the new school year
    Ready for the weekend
    Welcome to the Buffs fam to all our new students
    It's been so toasty in Boulder recently! Are you missing the snow tipped Flatirons?
    John Bally professor emeritus of astrophysical and planetary sciences at CU Boulder comes to @fiskeplanet to take a look at first glimpses of the universe.
    In honor of tomorrow being #NationalTrailsDay we want to know where your favorite hike is around campus Buffs.
    It’s 70° and sunny in April… we hope to catch you outside Buffs
    What better way to celebrate #NationalPuppyDay than with some pics of an excellently dressed @rudytheocfrenchie" */
    PrintPostsByYear(posts, "20", 100);
    /*Expected output: Here is a list of posts for year 20
    Sko buffs!!
    Imagine not having views like this on the way to class!
    We’ve arrived at another Monday on the most beautiful campus
    We love our girl Ralphie! The student section brought the energy for her first run of the season! We can't wait for more!
    Overheard at CU: What are your goals for this year?
    Come get involved in robotics @ cu!
    Overheard at CU: Tell us about your first day of school ‘fit
    Freshmen meet the Buffs! Welcome to Boulder Class of 2026
    Summer fun may be here but these recent sky temps are making us miss spring and fall
    It’s being debated around BuffsChat whether or not we have the best stadium views…
    Chip may not have a lightsaber but we think he’s out of this world!*/
}