#include <iostream>
using namespace std;

double fertilize (double stock, double amount){
int use = stock - amount;
cout << use << endl;}

double restock (double stock, double amount){
int purchase = stock + amount;
cout << purchase << endl;}

int main(){
    fertilize(10,10)
    restock(10, 20)
}