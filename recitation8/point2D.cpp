#include <iostream>
#include "header.h"

using namespace std;

point2D::point2D(){
    x = 0;
    y = 0;
    label = "";
}
point2D::point2D(double x1, double y1, string label1){
    x = x1;
    y = y1;
    label = label1;
}