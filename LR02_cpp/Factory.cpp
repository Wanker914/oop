#include "Factory.h"

Triangle Factory::createTriangle(double base, double height) {
    return Triangle(base, height);
}

Quadrate Factory::createQuadrate(double side) {
    return Quadrate(side);
}

void Factory::deleteShape(Shape* shape) {
    delete shape;
}

void Move::moveShape(Shape* shape, double x, double y) {
    // Реализация перемещения
    std::cout << "Фигура была перемещена в точку (" << x << ", " << y << ")" << std::endl;
}

void Compare::compareAreas(const Shape& shape1, const Shape& shape2) {
    double area1 = shape1.getArea();
    double area2 = shape2.getArea();

    // Вывод результата сравнения
    if (area1 == area2) {
        std::cout << "Площади фигур равны." << std::endl;
    } else if (area1 > area2) {
        std::cout << "Площадь первой фигуры больше площади второй фигуры." << std::endl;
    } else {
        std::cout << "Площадь второй фигуры больше площади первой фигуры." << std::endl;
    }
}