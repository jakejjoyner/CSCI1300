// CSCI 1300 Fall 2022
// Author: Jake Joyner
// Recitation: 202 – Christopher Ojukwu
// Homework 7 - Problem # 3

#include <iostream>
#include <vector>

using namespace std;

int main() {
    //initialize an integer vector
    //initialize the counter to 0
    vector<int> vect;
    int counter = 0;
    /*
    infinite loop until return statement
    */
    for(;;){
        /*
        initialize user input to 0 as an integer
        output "Please enter a number:"
        get user input
        while the user input is greater than 14 or less than 1 (out of bounds)
            output "The number should be an integer between 1 and 14."
            output "Please enter a number:"
            get user input
        insert the user's input at the end of the integer vector
        */
        int user_input = 0;
        cout << "Please enter a number:" << endl;
        cin >> user_input;
        while(user_input > 14 || user_input < 1){
            cout << "The number should be an integer between 1 and 14." << endl;
            cout << "Please enter a number:" << endl;
            cin >> user_input;
        }
        vect.push_back(user_input);
        /*
        if the user inputs 1
            if the size of the vector is equal to 1
                erase the index at the beginning of the vector
                increment the counter by 1
            if the size of the vector is greater than 1
                erase the vector at the beggining, and at the index after the beggining of the vector
                increment the counter by 2
        */
        if(user_input == 1){
            if(vect.size() == 1){
                vect.erase(vect.begin());
                counter++;
            }
            else if(vect.size() > 1){
            vect.erase(vect.begin()+1);
            vect.erase(vect.begin());
            counter += 2;
            }
        }
        /*
        if the user inputs 11, 12, or 13
            if the vector size is equal to 1
                erase the vector at the end index
                increment the counter by 1
            if the vector size is greater than 1
                erase the vector at the end index, and the index before the end index
                increment the counter by 2
        if the user inputs 14
            erase the vector at the end index
            output "Your remaining cards are: "
                for int i = 0, while i is less than the size of the vector, increment i by 1
                    output the vector at by, followed by a space
                end the line
                output "I have " <counter> " cards(s).", end the line
                if the counter is greater than the size of the vector
                    output "I win!", end the line, and return 0
                if the counter is less than the size of the vector
                    output "You win!", end the line, and return 0
                if the counter equals the size of the vector, output "Tie!", end the line, and return 0
        */
        if(user_input == 11 || user_input == 12 || user_input == 13){
            if(vect.size() == 1){
                vect.erase(vect.end() - 1);
                counter++;
            }
            else if(vect.size() > 1){
            vect.erase(vect.end()-2);
            vect.erase(vect.end()-1);
            counter += 2;
            }
        }
        if(user_input == 14){
            vect.erase(vect.end() -1);
            cout << "Your remaining cards are: ";
            for(int i = 0; i < vect.size(); i++){
                cout << vect.at(i) << " ";
            }
            cout << endl;
            cout << "I have " << counter << " card(s)." << endl;
            if(counter > vect.size()){
                cout << "I win!" << endl;
                return 0;
            }
            if(counter < vect.size()){
                cout << "You win!" << endl;
                return 0;
            }
            if(counter == vect.size()){
                cout << "Tie!" << endl;
                return 0;
            }
        }

    }
//return 0
return 0;
}