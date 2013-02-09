#include "Path.h"

Path::Path() {
    vector<Point> v;
}

int Path::length() {
    return vect.size();
}

Path& Path::operator+=(Point & a) {
    vect.push_back(a);
    return *this;
}

Point& Path::operator[](int i) {
    return vect[i];
}

ostream &operator<<(ostream &out, Path &c) {
    vector<Point> vect = c.getVector();
    out << "-Path-" << endl;
    for(int i=0; i<vect.size(); i++)
        out << "Point " << i << ": (" << vect[i].getX() << "," << vect[i].getY() << ")" << endl;
    return out;
}

