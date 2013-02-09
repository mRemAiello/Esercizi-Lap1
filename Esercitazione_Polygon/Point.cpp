#include <math.h>
#include "Point.h"

Point::Point() {
    x = y = 0;
}

Point::Point(int _x,int _y) {
    x = _x;
    y = _y;
}

Point Point::operator+(Point & a)
{
    Point result; 
    result.setX(x + a.getX());
    result.setY(y + a.getY());
    return result;
}

Point Point::operator-(Point & a)
{
    Point result; 
    result.setX(x - a.getX());
    result.setY(y - a.getY());
    return result;
}

int Point::distance(Point & a) {
    int _distX, _distY;
    _distX = x - a.getX();
    _distY = y - a.getY();
    return sqrt((_distX*_distX) + (_distY*_distY));
}

ostream &operator<<(ostream &out, Point &c)
{
    out << c.x << " , " << c.y;
    return out;
}
