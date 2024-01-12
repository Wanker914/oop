#include "windows.h"
#include "Menu.h"
#include "Factory.h"
#include "testProgram.h"

int main() {

    testProgram();

    SetConsoleOutputCP(CP_UTF8);

    Menu menu;
    menu.showMenu();

    return 0;
}