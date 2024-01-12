#include "testProgram.h"
#include <cassert>

void testcreatingTriangle(){

    Shape* shape1;

    double base, height;
    base = 3.0;
    height = 5.0;

    shape1 = new Triangle(base, height);

    double S = shape1->getArea();

    assert(S == 7.5);
}

void testcreatingQuadrate(){

    Shape* shape2;

    double side;
    side = 8.0;

    shape2 = new Quadrate(side);

    double S = shape2->getArea();

    assert(S == 64.0);
}

void testProgram(){
    testcreatingTriangle();
    testcreatingQuadrate();
}