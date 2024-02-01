#include <iostream>
using namespace std;

int main(){
const int SIZE = 3;
int arr[SIZE];

for(int i = 0; i < SIZE; i++){
    arr[i] = i * 2;
    cout << arr[i] << endl;
}
}