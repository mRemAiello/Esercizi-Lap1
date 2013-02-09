#include <iostream>
#include "Point.h"

using namespace std;
#pragma once

class Polygon {
    protected:
        Point * data;
        int num_lati;
    
    public:
        Polygon();
        ~Polygon();
        Point& getPoint(int i) {
            return data[i];
        }
        void addPoint(Point & p);
        virtual int perimeter();
        virtual float area();
        friend ostream &operator<<(ostream &out, Polygon & c);
};
