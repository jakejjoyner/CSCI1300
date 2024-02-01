#include <iostream>
#include "counter.h"

using namespace std;

void Counter::count(){
    value = value + 1;
}
void Counter::reset(){
    value = 0;
}
int Counter::get_value() const{
    return value;
}