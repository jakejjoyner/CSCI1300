#include <iostream>
#include <cmath>

using namespace std;
/*
Algorithm:
1. Store a random number as a double
2. To get the radius, divide the random number by the maximum possible random number and multiply that by the side length divided by 2
3. Output "The radius of the circle is " <radius>
4. Output "The probability of landing in the circle is " (pi * radius^2) / (side_length)^2
*/
void probability(double side_length){
    double x;
    x = rand();
    double radius = (x/RAND_MAX) * (side_length/2);
    cout << "The radius of the circle is " << radius << endl;
    cout << "The probability of landing in the circle is " << (3.14 * pow(radius, 2)) / pow(side_length,2) << endl;
}

int main(){
    //test cases
    probability(6);
    probability(6);
    probability(100);
}