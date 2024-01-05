#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

bool containsDoubleDigitNumber(const std::string& line)
{
    for (int i = 0; i < line.length() - 1; i++)
    {
        if (isdigit(line[i]) && isdigit(line[i + 1]))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    std::ifstream file("input.txt");
    if (!file)
    {
        SetConsoleOutputCP(CP_UTF8);
        std::cerr << "Не удалось открыть файл." << std::endl;
        return 1;
    }
    std::string line;
    while (std::getline(file, line))
    {
        if (!containsDoubleDigitNumber(line))
        {
            std::cout << line << std::endl;
        }
    }

    file.close();

    return 0;
}