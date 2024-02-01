#include <iostream>
using namespace std;

double fertilize (double stock, double amount){
double use = stock - amount;
return use;}

double restock (double stock, double amount){
double purchase = stock + amount;
return purchase;}

int main(){
    fertilize(10,10);
    double x = fertilize(10,10);
    cout << x << endl;
    restock(10, 20);
    double y = restock(10,20);
    cout << y << endl;
}