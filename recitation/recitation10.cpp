#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

/*
1.
make a function of type double vector
initialize user_input to 0 as a double
initialize double vector called numbers
for int i = 0, while i is less than 15, increment i
output "Please enter a value for index " <i>
get user input
insert user input at the beggining of the vector plus i

return the vector
*/

vector<double> vector1(){
    double user_input;
    vector<double> numbers;
    for(int i = 0; i < 15; i++){
        cout << "Please enter a value for index " << i << endl;
        cin >> user_input;
        numbers.insert(numbers.begin() + i, user_input);
    }


    return numbers;
}

/*
make a function with double return type that takes in a double vector, vector2
initialize average as a double to 0

for int i = 0, while i is less than 15, increment i
add vector 2 at i to the average

return the average/2
*/

double average(vector<double> vector2){
    double average = 0;
    for(int i = 0; i < 15; i++){
        average += vector2[i];
    }
    return average/2;
}


/*
make a function called remove with parameters double vector vector3 and double average
for int i = 0, while i is less than 15, increment i
if the vector3 at i is less than the average
erase the vector at the beggining of the vector plus i
*/

vector<double> remove(vector<double> vector3, double average){
    for(int i = 0; i < 15; i++){
        if(vector3[i] < average){
            vector3.erase(vector3.begin() + i);
        }
    }
    return vector3;
}

int main(){
//call vector1 function
//vector1();

//pass return value of vector 1 to a new vector vector2
vector<double> vector2 = vector1();

//pass vector2 and the average to the remove function
remove(vector2, average(vector2));
}

