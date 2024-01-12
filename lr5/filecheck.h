#include <iostream>
#include <fstream>
#include <string>

class FileCheck {
public:
    FileCheck(const std::string& filename) : filename(filename) {}

    void printLines() {
        std::ifstream file(filename);
        if (!file) {
            std::cerr << "Не удалось открыть файл: " << filename << std::endl;
            return;
        }

        std::string line;
        while (std::getline(file, line)) {
            if (!isTwoNumber(line)) {
                std::cout << line << std::endl;
            }
        }

        file.close();
    }

    bool isTwoNumber(const std::string& line)
    {
        if (line.length() < 2)
            return false;
        for (auto it = line.cbegin(); it+1 < line.cend(); it++)
            if (isdigit(*it) && isdigit(*(it+1))) {
                if ((it > line.cbegin() && isdigit(*(it-1)))
                    || (it < line.cend()-2 && isdigit(*(it+2))))
                    return false;
                return true;
            }
        return false;
    }

    std::string filename;
};