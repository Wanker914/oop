#include <iostream>
#include <algorithm>
#include <chrono>
#include <windows.h>
#include "MARSH.h"
#include "MARSHTest.h"

int main() {

    setlocale(LC_ALL,"Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    auto start = std::chrono::steady_clock::now();

    testMarsh();

    const int ARRAY_SIZE = 8;
    MARSH marshArray[ARRAY_SIZE];

    // Ввод данных с клавиатуры
    for (int i = 0; i < ARRAY_SIZE; i++) {
        std::wcout << L"Введите данные для " << (i + 1) << L"-го маршрута:\n";
        std::wcin >> marshArray[i];
    }

    // Сортировка маршрутов по номерам
    for (int i = 0; i < ARRAY_SIZE - 1; i++) {
        for (int j = 0; j < ARRAY_SIZE - i - 1; j++) {
            if (marshArray[j].getNumber() > marshArray[j + 1].getNumber()) {
                std::swap(marshArray[j], marshArray[j + 1]);
            }
        }
    }

    // Вывод информации о маршрутах
    std::wcout << L"\nИнформация о маршрутах:\n";
    std::wcout << L"-------------------------\n";

    std::wstring searchLocation;
    std::wcout << L"Введите название пункта маршрута для поиска: ";
    std::wcin >> searchLocation;

    bool found = false;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (marshArray[i].getStart() == searchLocation || marshArray[i].getEnd() == searchLocation) {
            std::wcout << marshArray[i] << std::endl;
            found = true;
        }
    }

    if (!found) {
        std::wcout << L"Маршруты, начинающиеся или заканчивающиеся в указанном пункте, не найдены." << std::endl;
    }

    auto end = std::chrono::steady_clock::now();
    std::wcout << L"Затраченное время: ";
    std::wcout << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << L" миллисекунд" << std::endl;

    return 0;
}
