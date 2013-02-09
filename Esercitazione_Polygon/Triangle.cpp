#include "Triangle.h"
#include <math.h>

Triangle::Triangle() {
    lato_1 = lato_2 = lato_3 = 0;
}

Triangle::Triangle(int _l1, int _l2, int _l3) {
    if (_l1 + _l2 <= _l3)
        throw "Wrong size of triangle";
    if (_l2 + _l3 <= _l1)
        throw "Wrong size of triangle";
    if (_l2 + _l3 <= _l2)
        throw "Wrong size of triangle";
    lato_1 = _l1;
    lato_2 = _l2;
    lato_3 = _l3;
}

int Triangle::perimeter() {
    return lato_1 + lato_2 + lato_3;
}

float Triangle::area() {
    float p = (float)perimeter()/2;
    return sqrt(p * (p-lato_1) * (p-lato_2) * (p-lato_3));
}

