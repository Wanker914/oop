#include <windows.h>
#include "filecheck.h"
#include "tetsFile.h"

int main() {

    testFile();

    SetConsoleOutputCP(CP_UTF8);

//    std::string filename;
//    std::cout << "Введите имя файла: ";
//    std::cin >> filename;

    FileCheck checkFile("123wasd.txt");
    checkFile.printLines();

    return 0;
}