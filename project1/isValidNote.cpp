#include <iostream>
#include <cassert>
using namespace std;

bool isValidNote(string input){
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

int main(){
    assert(isValidTune(A2B3C9) == true);
}