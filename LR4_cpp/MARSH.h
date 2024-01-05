#include <string>
#include <ostream>
#include <istream>
#include <iostream>

class MARSH {

    private:
        std::wstring start;  // название начального пункта маршрута
        std::wstring end;    // название конечного пункта маршрута
        int number;        // номер маршрута

    public:

        void setStart(std::wstring start) {
            this->start = start;
        }

        void setEnd(std::wstring end) {
            this->end = end;
        }

        void setNumber(int number) {
            this->number = number;
        }

        std::wstring getStart(){
            return start;
        }

        std::wstring getEnd(){
            return end;
        }

        int getNumber(){
            return number;
        }

        friend std::wostream& operator<<(std::wostream& os, const MARSH& marsh) {
            os << L"Маршрут " << marsh.number << L": " << marsh.start << L" - " << marsh.end;
            return os;
        }

        friend std::wistream& operator>>(std::wistream& is, MARSH& marsh) {

            std::wcout << L"Введите начальный пункт маршрута:";
            is >> marsh.start;

            std::wcout << L"Введите конечный пункт маршрута:";
            is >> marsh.end;

            std::wcout << L"Введите номер маршрута:";
            is >> marsh.number;

            return is;
        }
};

