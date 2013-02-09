#include <cstdlib>
#include <iostream>
#include "Path.h"

using namespace std;

int main(int argc, char *argv[])
{
    Point a(0,0);
    Point b(1,5);
    Point c(2,3);
    Point d(4,3);
    
    Path p;
    
    p += a;
    p += b;
    p += c;
    p += d;
    
    cout << p << endl;
    
    system("PAUSE");
    
    return EXIT_SUCCESS;
}
