#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

// int main(){
//     vector<string> vowels = {"a","e","i","o","u"};
//     for(int i = 0; i < vowels.size(); i++){
//         cout << vowels[i] << endl;
//     }
//     return 0;
// }

int main(){
    vector<int> numbers;
    for(int i = 0; i <= 10; i++){
        numbers.push_back(i);
        cout << numbers[i] << endl;
    }
}