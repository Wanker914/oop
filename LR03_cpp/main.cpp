#include <string>
#include <chrono>
#include <exception>
#include <windows.h>
#include "Queue.h"
#include "TestQueue.h"

int main() {

    auto start = std::chrono::steady_clock::now();

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    testQueue();

    try {
        Queue<int> intQueue;
        int inputIntQueue;
        std::wcout << L"Введите целые числа (введите 999 чтобы закончить):\n";
        while (true) {
            std::cin >> inputIntQueue;
            if (inputIntQueue == 999) break;
            intQueue.enqueue(inputIntQueue);
        }
        intQueue.print();

        std::wcout << L"Первый элемент из intQueue: " << intQueue.front() << std::endl;
        intQueue.dequeue();
        std::wcout << L"Первый элемент из intQueue после удаления: " << intQueue.front() << std::endl;


        Queue<double> doubleQueue;
        double inputdoubleQueue;
        std::wcout << L"Введите числа с плавающей точкой (введите 9.99 чтобы закончить):\n";
        while (true) {
            std::cin >> inputdoubleQueue;
            if (inputdoubleQueue == 9.99) break;
            doubleQueue.enqueue(inputdoubleQueue);
        }
        doubleQueue.print();

        std::wcout << L"Первый элемент из doubleQueue: " << doubleQueue.front() << std::endl;
        doubleQueue.dequeue();
        std::wcout << L"Первый элемент из doubleQueue после удаления: " << doubleQueue.front() << std::endl;

        Queue<std::wstring> stringQueue;
        std::wstring inputstringQueue;
        std::wcout << L"Введите строку (введите W чтобы закончить):\n";
        while (true) {
            std::wcin >> inputstringQueue;
            if (inputstringQueue == L"W") break;
            stringQueue.enqueue(inputstringQueue);
        }
        stringQueue.print();

        std::wcout << L"Первый элемент из stringQueue: " << stringQueue.front() << std::endl;
        stringQueue.dequeue();
        std::wcout << L"Первый элемент из stringQueue после удаления: " << stringQueue.front() << std::endl;

        // Пример генерации исключений
        Queue<int> emptyQueue;
        emptyQueue.dequeue(); // Генерирует исключение std::out_of_range
    }
    catch (const std::exception& ex) {
        std::wcerr << L"Произошло исключение исключение: " << ex.what() << std::endl;
    }

    auto end = std::chrono::steady_clock::now();
    std::wcout << L"Затраченное время: ";
    std::wcout << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << L" миллисекунд" << std::endl;

    return 0;

}