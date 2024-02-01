// CSCI 1300 Fall 2022
// Author: Jake Joyner
// Recitation: 202 – Christopher Ojukwu
// Homework 6 - Problem # 2

#include <iostream>
#include <cassert>
#include <iomanip>
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

void printMountainStats(string filename)
{
    string line = ""; //initialize and declare variable to store lines
    int line_idx = 0; //initialize and declare variable to store line index
    char separator = '|';//initialize and declare separator variable for split function
    ifstream file_input;//initialize input file
    file_input.open(filename);//open the function's input and assign it to the 'file_input' ifstream variable
    int highestMountainInt = 0;//initialize temporary variable to store and update highest mountain
    int lowestMountainInt = 50000;//initialize temporary variable to store and update lowest mountain
    string arr[200];//initialize array to be used in split function
    string HighestMountainName;//initialize string variable to store and update name of lowest mountain
    string LowestMountainName;//initialize string variable to store and update name of highest mountain

    if (file_input.fail())// true when file is not opened succesfully
    {
        cout << "Could not open file." << endl;
        return;
    }
    // read every line from the file
    if (file_input.is_open())
    { // true when file is opened succesfully
        while (!file_input.eof())// continue looping as there as there is data in the file to be proccesed
        {                              
             getline(file_input, line); // get next line from file input object and store in 'line' variable    
             split(line, separator, arr, 200);//split function
             int Mountain[200];//initialize integer array to store mountain data as integers

            if(line.length()!=0){//if the line is not empty
            line_idx++;//increment the counter
            }

            if(!arr[0].empty()){//if the line is not empty
            Mountain[0] = stoi(arr[1]);//convert the string array from the split function, where the index is equal to the mountain's height,
            //into an integer array
            }

            if(Mountain[0] > highestMountainInt){//if the mountain's height is greater than the temorary variable
            highestMountainInt = Mountain[0];//set the mountain's height equal to the temporary variable
            HighestMountainName = arr[0];//and set the name of the heighest mountain to the string array at the index before the heighest mountain's
            //height
            }

            if(Mountain[0] < lowestMountainInt){//if the mountain's height is less than the temorary variable
            lowestMountainInt = Mountain[0];//set the mountain's height equal to the temporary variable
            LowestMountainName = arr[0];//and set the name of the lowest mountain to the string array at the index before the lowest mountain's
            //height
            }
        }
        cout << "Number of lines read: " << line_idx << "." << endl;//output number of lines read
        cout << "Tallest Mountain: " << HighestMountainName << " at " << highestMountainInt << " feet." << endl;//output tallest mountain/height of tallest mountain
        cout << "Shortest Mountain: " << LowestMountainName << " at " << lowestMountainInt << " feet." << endl;//output lowest mountain/height of lowest mountain
             }       
    else
    {
        cout << "Could not open file." << endl;//if file data is corrupted or can't open, tell the user that the file cannot be opened
    }
}

int main()
{ // test cases
    string testOneString = "ABC,DEF,GHI,JKL";
    string arr[4];
    split(testOneString, ',', arr, 4);
    assert(arr[0] == "ABC");
    assert(arr[1] == "DEF");
    assert(arr[2] == "GHI");
    assert(arr[3] == "JKL");
    
    printMountainStats("TestTwoFile.txt");
    /* Expected Output:
    Number of lines read: 3.
    Tallest Mountain: Pikes Peak at 14114 feet.
    Shortest Mountain: Vermilion Peak at 13894 feet.
    */
    printMountainStats("NoDataTest");
    //Expected Output: Could not open file.
    printMountainStats("TestThreeFile.txt");
    /* (file with empty lines) Expected Output:
    Number of lines read: 3.
    Tallest Mountain: Pikes Peak at 14114 feet.
    Shortest Mountain: Vermilion Peak at 13894 feet.
    */
     printMountainStats("EmptyFileTest.txt");
     //Expected Output: Could not open file.
}