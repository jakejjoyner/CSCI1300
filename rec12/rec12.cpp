#include <iostream>

using namespace std;

void reverse(string str){
    if(str.size() == 0){
        return;
    }
    reverse(str.substr(1));
    cout << str[0];
}

int factorial(int n) {
    if (n == 0) {
        return 0;
    }

    return n + factorial(n - 1);
}

void recursive_func(int count)
{
   recursive_func(count + 2);
   cout << count << endl;
}


// 5! = 5 * 4 * 3 * 2 * 1
// 3! = 3 * 2 * 1
// 2! = 2 * 1
// 1! = 1 * 1

int main(){
    // reverse("hello");

    //cout << factorial(3);

    recursive_func(1);
    return 0;

    // 3
        // return 3 + factorial(2)
            // 2
            // return 2 + factorial(1)
                // 1
                // return 1 + factorial(0)
                    // 0
                    // return 0
                // return 1 + 0
            // return 2 + 1
        // return 3 + 3
    // return 6
}

// hello
    // ello
        // llo
            // lo 
                // o
                    // ""
                // print o
            // print l
        // print l
    // print e
// print h
