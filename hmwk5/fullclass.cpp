// CSCI 1300 Fall 2022
// Author: Jake Joyner
// Recitation: 202 – Christopher Ojukwu
// Homework 5 - Problem # 5

#include <iostream>
#include <cassert>
#include <cstdlib>
using namespace std;

int fullClass(bool classroom[][4], int rows, int waitlist){
    for(int i = 0; i < rows; i++){ //iterate through rows of the classroom
        for(int j = 0; j < 4; j++){//iterate through Columns of the classroom
        if(classroom[i][j] == 0){//if there is an open seat,
            if(waitlist != 0){//if there are students on the waitlist
            cout << 1;//change the 0 to a 1, in order to indicate a full seat
            waitlist--;//decrement the waitlist by one
            }
            else{
                cout << 0;//if the waitlist is equal to 0, don't change the 0 to a 1
            }
        }
        else {
            cout << 1;//if the seat is full, print 1 (keep to 1 as a 1)
        }
}
cout << endl;//end the line at the end of a row
}
cout << "Remaining Students: " << waitlist << endl;//print the number of remaining students on the waitlist if the class is full
return waitlist;//return the number of remaining students on the waitlist
}

int main(){//test cases
bool testOneArray[4][4] = {{0, 1, 1, 1},
			               {0, 0, 0, 0},
		            	   {1, 1, 0, 0},
		            	   {0, 1, 0, 1}};
assert(fullClass(testOneArray, 4, 9) == 0);
bool testTwoArray[4][4] = {{1, 1, 1, 1},
			               {1, 1, 0, 0},
		            	   {1, 1, 0, 0},
		            	   {0, 1, 0, 1}};
assert(fullClass(testTwoArray, 4, 9) == 3);
bool testThreeArray[3][4] = {{1, 1, 1, 1},
			               {1, 1, 0, 0},
		            	   {1, 1, 0, 0}};
assert(fullClass(testThreeArray, 3, 9) == 5);
bool testFourArray[3][4] = {{1, 1, 1, 1},
			               {1, 1, 1, 1},
		            	   {1, 1, 1, 1}};
assert(fullClass(testFourArray, 3, 9) == 9);
bool testFiveArray[3][4] = {{0, 0, 0, 0},
			               {0, 0, 0, 0},
		            	   {0, 0, 0, 0}};
assert(fullClass(testFiveArray, 3, 9) == 0);
}