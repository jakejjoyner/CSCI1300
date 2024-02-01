#include <iostream>
#include <iomanip>
#include "counter.h"

using namespace std;

int main(){
    Counter tally;
    tally.reset();
    tally.count();
    tally.count();
    tally.count();
    int result = tally.get_value();
    cout << "Value of tally: " << result << endl;
}