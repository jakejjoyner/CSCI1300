// CSCI 1300 Fall 2022
// Author: Jake Joyner
// Recitation: 202 – Christopher Ojukwu
// Homework 6 - Problem # 4b

#include <iostream>
#include <cassert>
#include <cstring>
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
   while(end_of_string<input_stringLength){//while loop to iterate through array and split it at instances of the separator
    if(input_string[end_of_string] == separator){
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

int readRestaurantData(string filename, string restaurants[], int ratings[][3], int arrSize){
    ifstream file_input;
    file_input.open(filename);
    string line = "";
    string arr[10];

if (file_input.is_open()){

    int i = 0;

    while (!file_input.eof()){
        getline(file_input, line);
        split(line, '~',arr,10);

    if (split(line, '~',arr,10) == 4 && i < arrSize && line.length() != 0){
        restaurants[i] = arr[0];
        ratings[i][0] = stoi(arr[1]);
        ratings[i][1] = stoi(arr[2]);
        ratings[i][2] = stoi(arr[3]);
        i++;
        }
    else{
        
    }
    }

    return i;

    }

if (file_input.fail()){

    return -1;
} 
}

void calcOverallScore(string restaurants[], int ratings[][3], int num_restaurants){
    string line = ""; //initialize and declare variable to store lines of the file input
    string arr[10];//create array to store output of split functino
    int i = 0;//initialize and declare i to use in while loop
    string filename;//initialize filename variable to take in user's file input

    readRestaurantData(filename, restaurants, ratings, num_restaurants);//read restauraunt data in order to store ratings, and restaurants
    //in separate arrays

    double score[10];//create an array to store the scores of restaurants
    while(i < num_restaurants){//while i is less than the number of restaurants
    score[i] = (6.3 * ratings[i][0]) + (4.3 * ratings[i][1]) + (3.4 * (5 - ratings[i][2])); //set the score at i equal to the algorithm for 
    //restaurant scores
    cout << restaurants[i] << " overall score: " << setprecision(1) << fixed << score[i] << endl; //print the overall score and set precision
    //to 1
    i++; //increment index
     }
    }

int main()
{ // test cases
    string RestaurantTestArray[3];
    int ratingsTestArray[3][3];
   readRestaurantData("TestOneFile.txt", RestaurantTestArray, ratingsTestArray, 3);
    calcOverallScore(RestaurantTestArray, ratingsTestArray, 3);
    /*
    Expected Output:
    Wendys overall score: 60.9
    Chick-fil-a overall score: 78.2
    Snarfburger overall score: 87.0 
    */
   string RestaurantTestArray2[3];
    int ratingsTestArray2[3][3];
   readRestaurantData("TestFourFile.txt", RestaurantTestArray2, ratingsTestArray2, 3);
   calcOverallScore(RestaurantTestArray2, ratingsTestArray2, 3);
   /*
    (empty lines) Expected Output:
    Wendys overall score: 60.9
    Chick-fil-a overall score: 78.2
    Snarfburger overall score: 87.0 
    */
   string RestaurantTestArray3[3];
    int ratingsTestArray3[3][3];
   readRestaurantData("BadData", RestaurantTestArray3, ratingsTestArray3, 3);
   calcOverallScore(RestaurantTestArray3, ratingsTestArray3, 3);
   /*
    Expected Output:
     overall score: 223.4
    overall score: 117.8
    overall score: 70310792.8
    */
   string RestaurantTestArray4[3];
    int ratingsTestArray4[3][3];
   readRestaurantData("EmptyFileTest", RestaurantTestArray4, ratingsTestArray4, 3);
   calcOverallScore(RestaurantTestArray4, ratingsTestArray4, 3);
   /*
    Expected Output:
     overall score: 7909754525.5
    overall score: -13027023236.3
    overall score: 17.0
    */
}