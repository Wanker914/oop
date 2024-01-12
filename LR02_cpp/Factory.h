#include <iostream>
#include "Triange.h"
#include "Quadrate.h"

#ifndef LR02_CPP_FACTORY_H
#define LR02_CPP_FACTORY_H
class Factory {
public:
    // Создание треугольника
    static Triangle createTriangle(double base, double height);

    // Создание квадрата
    static Quadrate createQuadrate(double side);

    // Удаление фигуры
    static void deleteShape(Shape* shape);
};

class Move {
public:
    // Перемещение объекта по координатам
    static void moveShape(Shape* shape, double x, double y);
};

class Compare {
public:
    static void compareAreas(const Shape& shape1, const Shape& shape2);
};
#endif //LR02_CPP_FACTORY_H
