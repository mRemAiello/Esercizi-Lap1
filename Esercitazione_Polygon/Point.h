#include <iostream>

#pragma once

using namespace std;

class Point {
    int x,y;
    
    public:
        Point();
        Point(int _x,int _y);
        int getX() { return x; }
        int getY() { return y; }
        void setX(int _x) { x = _x; }
        void setY(int _y) { y = _y; }
        int distance(Point &a);
        Point operator+(Point &a);
        Point operator-(Point &a);
        friend ostream &operator<<(ostream &out, Point & c);
};
