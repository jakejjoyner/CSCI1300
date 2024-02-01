#include <iostream>
#include <iomanip>

using namespace std;

class point2D{
    private:
        double x;
        double y;
        string label;
    public:
        point2D();
        point2D(double x1, double y1, string label1);
        double getX();
        double getY();
        
};