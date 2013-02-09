#include <stdio.h>
#include <stdlib.h>
#include "Polygon.h"
#include "Triangle.h"

int main(int argc, char *argv[])
{
    Point a(0,0);
    Point b(0,1);
    Point c(1,1);
    Point d(1,0);
    
    Polygon triangolo;
    triangolo.addPoint(a);
    triangolo.addPoint(b);
    triangolo.addPoint(c);
    triangolo.addPoint(d);
    
    Triangle tri(a.distance(b),b.distance(c),c.distance(d));
    
    cout << triangolo << endl << tri << endl;
    
    system("PAUSE");
    
    return EXIT_SUCCESS;
}
