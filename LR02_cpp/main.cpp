#include "windows.h"
#include "Menu.h"
#include "Factory.h"

int main() {

    SetConsoleOutputCP(CP_UTF8);

    Menu menu;
    menu.showMenu();

    return 0;
}