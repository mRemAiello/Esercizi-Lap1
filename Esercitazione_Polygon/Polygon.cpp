#include <stdio.h>
#include <stdlib.h>
#include "Polygon.h"

Polygon::Polygon() {
    num_lati = 0;
    data = new Point[1];
}

Polygon::~Polygon() {
    delete [] data;
}

void Polygon::addPoint(Point & p) {
    Point * new_data;
    new_data = new Point[num_lati+1];
    for (int i = 0; i < num_lati; i++)
        new_data[i] = data[i];
    new_data[num_lati++] = p;
    data = new_data;
}

ostream &operator<<(ostream &out, Polygon &c)
{   
    out << "Area : " << c.area() << ", Perimetro : " << c.perimeter() << endl;
    return out;
}

float Polygon::area() {
    float first_sum, second_sum;
    first_sum = second_sum = 0;
    for(int i = 0; i<num_lati-1; i++) {
        first_sum += data[i].getX()*data[i+1].getY();
        second_sum += data[i+1].getX()*data[i].getY();
    }
    return abs(first_sum-second_sum)/2;
}

int Polygon::perimeter() {
    int ret = 0;
    for(int i = 0; i<num_lati-1; i++)
        ret += data[i].distance(data[i+1]);
    ret += data[0].distance(data[num_lati-1]);
    return ret;
}
