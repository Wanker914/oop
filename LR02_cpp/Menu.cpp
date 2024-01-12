#include "Menu.h"

// Показать меню
void Menu::showMenu() {
    int choice;

    do {
        std::cout << "Меню:" << std::endl;
        std::cout << "1. Создать треугольник" << std::endl;
        std::cout << "2. Создать квадрат" << std::endl;
        std::cout << "3. Переместить треугольник" << std::endl;
        std::cout << "4. Переместить квадрат" << std::endl;
        std::cout << "5. Сравнить площади фигур" << std::endl;
        std::cout << "6. Удалить треугольник" << std::endl;
        std::cout << "7. Удалить квадрат" << std::endl;
        std::cout << "8. Выйти" << std::endl;
        std::cout << "Выберите действие: ";
        std::cin >> choice;
        std::cout << std::endl;

        switch (choice) {
            case 1:
                createTriangle();
                break;
            case 2:
                createQuadrate();
                break;
            case 3:
                moveShapeTriangle();
                break;
            case 4:
                moveShapeQuadrate();
                break;
            case 5:
                compareAreas();
                break;
            case 6:
                deleteShapeTriangle();
                break;
            case 7:
                deleteShapeQuadrate();
                break;
            case 8:
                std::cout << "Выход из программы." << std::endl;
                break;
            default:
                std::cout << "Неверный ввод. Попробуйте снова." << std::endl;
                break;
        }

        std::cout << std::endl;
    } while (choice != 5);
}

void Menu::createTriangle() {
    double base, height;
    std::cout << "Введите основание треугольника: ";
    std::cin >> base;
    std::cout << "Введите высоту треугольника: ";
    std::cin >> height;

    shape1 = new Triangle(base, height);
    std::cout << "Треугольник создан." << std::endl;
}

// Создать квадрат
void Menu::createQuadrate() {
    double side;
    std::cout << "Введите сторону квадрата: ";
    std::cin >> side;

    shape2 = new Quadrate(side);
    std::cout << "Квадрат создан." << std::endl;
}

// Переместить треугольник
void Menu::moveShapeTriangle() {
    if (shape1 == nullptr) {
        std::cout << "Треугольник не создан." << std::endl;
        return;
    }

    double x, y;
    std::cout << "Введите координаты для перемещения треугольника: ";
    std::cin >> x >> y;

    Move::moveShape(shape1, x, y);
}

// Переместить фигуру
void Menu::moveShapeQuadrate() {
    if (shape2 == nullptr) {
        std::cout << "Квадрат не создан." << std::endl;
        return;
    }

    double x, y;
    std::cout << "Введите координаты для перемещения квадрата: ";
    std::cin >> x >> y;

    Move::moveShape(shape2, x, y);
}

// Сравнить площади фигур
void Menu::compareAreas() {
    if (shape1 == nullptr || shape2 == nullptr) {
        std::cout << "Фигуры не созданы." << std::endl;
        return;
    }

    Compare::compareAreas(*shape1, *shape2);
}

void Menu::deleteShapeTriangle(){
    if (shape1 == nullptr) {
        std::cout << "Треугольник не создан." << std::endl;
        return;
    }

    Factory::deleteShape(shape1);
}

void Menu::deleteShapeQuadrate(){
    if (shape2 == nullptr) {
        std::cout << "Квадрат не создан." << std::endl;
        return;
    }

    Factory::deleteShape(shape2);
}

Menu::~Menu() {
    delete shape1;
    delete shape2;
}