#include <iostream>
#include <cassert>
using namespace std;

bool isValidNote(string input){ //problem one function
    if(input.length() <= 1 || input.length()%2 != 0)
    {
        return 0;
    }
    else {
        if(input.at(0) >= 65 && input.at(0) <= 71){
            if(input.at(1) >= 48 && input.at(1) <= 57){
                return true;
            }
        }
        else{
            return false;
        }
    }
}

bool isValidTune(string input)
{
    if (input.length() < 2){ //not a tune if less than two chars

        return false; //returns false
    }

    for (int i = 0; i < input.length(); i+=2) // checks every two chars
    {
        if (!isValidNote(input.substr(i, 2))){ //checks if every two chars is a valid note

            return false; //return false if it doesn't pass all the checks
        }
    }
    return true; //if passes all checks then returns true
}
int main()
{
    assert(isValidTune("A2B4C7") == true); 
    assert(isValidTune("M5D2E1") == false);
    assert(isValidTune("B4D2H15") == false);
    assert(isValidTune("csci1300") == false);
}