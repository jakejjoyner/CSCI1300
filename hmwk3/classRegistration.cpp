// CSCI 1300 Fall 2022
// Author: Jake Joyner
// Recitation: 202 – Christopher Ojukwu
// Homework 3 - Problem #5

#include <iostream>
using namespace std;

int main(){
    //initialize variables
    int input;
    int nested_input;
    int nested_input_2;
    //ask user for input
    cout << "Select a department: " << "(1)Computer Science " << "(2)Math " << "(3)Science" << endl;
    cin >> input;
    switch(input){
    //comsci department
    case 1:
         if (input==1){
          cout << "Select a class: " << "(1)Starting Computing " << "(2)Data Structures " << "(3)Algorithms " << endl;
            cin >> nested_input;
                if(nested_input==1){
                    cout << "Select a section: " << "(1)Section 100 " << "(2)Section 200" << endl;
                    cin >> nested_input_2;
                    if (nested_input_2==1){
                        cout << "You've been enrolled in Section 100 of Starting Computing!" << endl;
                    }
                    else if (nested_input_2==2){
                        cout << "You've been enrolled in Section 200 of Starting Computing!" << endl;
                    }
                    else {
                        //input validation
                        cout << "Please enter a valid input." << endl;
                    }
                    }
                if (nested_input==2){
                    cout << "Select a section: " << "(1)Section 101 " << "(2)Section 201" << endl;
                    cin >> nested_input_2;
                    if (nested_input_2==1){
                        cout << "You've been enrolled in Section 101 of Data Structures!" << endl;
                    }
                    else if (nested_input_2==2){
                        cout << "You've been enrolled in Section 201 of Data Structures!" << endl;
                    } else {
                        //input validation
                        cout << "Please enter a valid input." << endl;
                    }
                    }
                else if(nested_input==3){
                    cout << "Select a section: " << "(1)Section 102 " << "(2)Section 202" << endl;
                    cin >> nested_input_2;
                    if (nested_input_2==1){
                        cout << "You've been enrolled in Section 102 of Algorithms!" << endl;
                    }
                    else if (nested_input_2==2){
                        cout << "You've been enrolled in Section 202 of Algorithms!" << endl;
                    }else {
                        //input validation
                        cout << "Please enter a valid input." << endl;
                    }

                    }
                    //input validation
                else if (nested_input > 3 || nested_input < 1){
                    cout << "Please enter a valid input." << endl;
                }
                }
            return 0;
            //math department
            case 2:
                 if (input==2){
                 cout << "Select a class: " << "(1)Calculus 1 " << "(2)Calculus 2 " << "(3)Linear Algebra " << endl;
                 cin >> nested_input;
                if(nested_input==1){
                    cout << "Select a section: " << "(1)Section 400 " << "(2)Section 500" << endl;
                    cin >> nested_input_2;
                    if (nested_input_2==1){
                        cout << "You've been enrolled in Section 400 of Calculus 1!" << endl;
                    }
                    else if (nested_input_2==2){
                        cout << "You've been enrolled in Section 500 of Calculus 1!" << endl;
                    }else {
                        //input validation
                        cout << "Please enter a valid input." << endl;
                    }
                    }
                if (nested_input==2){
                    cout << "Select a section: " << "(1)Section 401 " << "(2)Section 501" << endl;
                    cin >> nested_input_2;
                    if (nested_input_2==1){
                        cout << "You've been enrolled in Section 401 of Calculus 2!" << endl;
                    }
                    else if (nested_input_2==2){
                        cout << "You've been enrolled in Section 501 of Calculus 2!" << endl;
                    }}
                    //input validation
                    else if(1>nested_input>3){
                    cout << "Please enter a valid input." << endl;
                    }
                else if(nested_input==3){
                    cout << "Select a section: " << "(1)Section 402 " << "(2)Section 502" << endl;
                    cin >> nested_input_2;
                    if (nested_input_2==1){
                        cout << "You've been enrolled in Section 402 of Linear Algebra!" << endl;
                    }
                    else if (nested_input_2==2){
                        cout << "You've been enrolled in Section 502 of Linear Algebra!" << endl;
                    }
                    else 
                    //input validation
                    {
                        cout << "Please enter a valid input." << endl;
                    }}
                    //input validation
                    else if(1>nested_input>3){
                    cout << "Please enter a valid input." << endl;
                }}
                
                return 0;
            //science department
            case 3:
                if (input==3){
                 cout << "Select a class: " << "(1)General Chemistry 1 " << "(2)Physics 1 " << endl;
                 cin >> nested_input;
                if(nested_input==1){
                    cout << "Select a section: " << "(1)Section 700 " << "(2)Section 800" << endl;
                    cin >> nested_input_2;
                    if (nested_input_2==1){
                        cout << "You've been enrolled in Section 700 of General Chemistry 1!" << endl;
                    }
                    else if (nested_input_2==2){
                        cout << "You've been enrolled in Section 800 of General Chemistry 1!" << endl;
                    }
                    //input validation
                    else {
                        cout << "Please enter a valid input." << endl;
                    }}
                if (nested_input==2){
                    cout << "Select a section: " << "(1)Section 701 " << "(2)Section 801" << endl;
                    cin >> nested_input_2;
                    if (nested_input_2==1){
                        cout << "You've been enrolled in Section 701 of Physics 1!" << endl;
                    }
                    else if (nested_input_2==2){
                        cout << "You've been enrolled in Section 801 of Physics 1!" << endl;
                    }
                    //input validation
                    else {
                        cout << "Please enter a valid input." << endl;
                    }}
                    //input validation
                    else if (nested_input > 2 || nested_input < 1){
                    cout << "Please enter a valid input." << endl;
                }}
return 0;
                
                return 0;
            //input validation
            default: cout << "Please enter a valid input." << endl;
                return 0;
}
    }
