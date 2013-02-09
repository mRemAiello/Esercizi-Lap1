#include "Polygon.h"

class Triangle : public Polygon {
    int lato_1, lato_2, lato_3;

    public:
        Triangle();
        Triangle(int _l1, int _l2, int _l3);
        int perimeter();
        float area();
};
