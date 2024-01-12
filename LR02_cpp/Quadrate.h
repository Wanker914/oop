#include "Shape.h"

#ifndef LR02_CPP_QUADRATE_H
#define LR02_CPP_QUADRATE_H
class Quadrate : public Shape {
private:
    double side;
public:
    Quadrate(double side) : side(side) {}

    double getArea() const override {
        return side * side;
    }
};
#endif //LR02_CPP_QUADRATE_H
