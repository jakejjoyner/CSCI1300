#include <iostream>
using namespace std;

int main() {

string name;

cout << "Please enter a string" << endl;
getline(cin, name);
// cin>>name;

int name_length = name.length();
int counter = 0;
char letter;

// if(letter <= 122 && letter >= 97){
while (counter < name_length)
{
        letter = name[counter] - 32;
        cout << letter;
        counter++;
}
// }
}