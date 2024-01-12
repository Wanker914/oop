#include "Shape.h"

#ifndef LR02_CPP_TRIANGE_H
#define LR02_CPP_TRIANGE_H
class Triangle : public Shape {
private:
    double base;
    double height;
public:
    Triangle(double base, double height) : base(base), height(height) {}

    double getArea() const override{
        return 0.5 * base * height;
    };
};
#endif //LR02_CPP_TRIANGE_H
