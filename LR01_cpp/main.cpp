#include <chrono>
#include <windows.h>
#include "TestMasive.h"
#include "Masive.h"

int main() {

    testmassive();

    auto start = std::chrono::steady_clock::now();

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    MasiveString masive1;
    int sizemasive1;
    std::wcout << L"Введите число элементов сколько должно быть в первом массиве: ";
    std::wcin >> sizemasive1;
    for (int i = 0; i < sizemasive1; i++) {
        std::wstring inputstr1;
        std::wcout << L"Введите " << (i + 1) << L" элемент в первый массив:\n";
        std::wcin >> inputstr1;
        masive1.addString(inputstr1, inputstr1.size() );
    }


    MasiveString masive2;
    int sizemasive2;
    std::wcout << L"Введите число элементов сколько должно быть во втором массиве: ";
    std::wcin >> sizemasive2;
    for (int i = 0; i < sizemasive2; i++) {
        std::wstring inputstr2;
        std::wcout << L"Введите " << (i + 1) << L" элемент в первый массив:\n";
        std::wcin >> inputstr2;
        masive2.addString(inputstr2, inputstr2.size() );
    }

    MasiveString mergedArray = masive1.mergeArrays(masive2);

    std::wcout << L"Объединенный массив: " << std::endl;
    mergedArray.printArray();

    int elementnumber;
    std::wcout << L"Выберите индекс из объединенного массива: ";
    std::wcin >> elementnumber;

    std::wcout << L"Элемент с индексом " << elementnumber << L" из объединенного массива: " << mergedArray.getString(elementnumber) << std::endl;

    auto end = std::chrono::steady_clock::now();
    std::wcout << L"Затраченное время: ";
    std::wcout << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << L" миллисекунд" << std::endl;

    return 0;
}
