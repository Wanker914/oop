#include "Factory.h"

#ifndef LR02_CPP_MENU_H
#define LR02_CPP_MENU_H
class Menu {
private:
    Shape* shape1;
    Shape* shape2;
public:
    Menu() : shape1(nullptr), shape2(nullptr) {}

    // Показать меню
    void showMenu();

    // Создать треугольник
    void createTriangle();

    // Создать квадрат
    void createQuadrate();

    // Переместить треугольник
    void moveShapeTriangle();

    // Переместить треугольник
    void moveShapeQuadrate();

    // Сравнить площади фигур
    void compareAreas();

    void deleteShapeTriangle();

    void deleteShapeQuadrate();

    ~Menu();
};
#endif //LR02_CPP_MENU_H
