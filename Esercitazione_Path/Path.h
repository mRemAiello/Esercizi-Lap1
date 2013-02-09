#include <vector>
#include <iostream>
#include "Point.h"

using namespace std;

class Path {
    private:
        vector<Point> vect;
    public:
        Path();
        vector<Point> getVector() { return vect; }
        int length();
        Path &operator+=(Point &a);
        Point &operator[](int i);
        friend ostream &operator<<(ostream &out, Path &c);
};
