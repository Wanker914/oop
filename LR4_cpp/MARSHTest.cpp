#include "MARSH.h"
#include <cassert>
#include <iostream>
#include <windows.h>

using namespace std;

void teststart() {

    const int ARRAY_SIZE = 1;
    MARSH marshArray[ARRAY_SIZE];

    marshArray[0].setStart(L"Krasnodar");
    marshArray[0].setEnd(L"Moscow");
    marshArray[0].setNumber(123);

    wstring result = marshArray[0].getStart();

    assert(result == L"Krasnodar");
}

void testend() {

    const int ARRAY_SIZE = 1;
    MARSH marshArray[ARRAY_SIZE];

    marshArray[0].setStart(L"Krasnodar");
    marshArray[0].setEnd(L"Moscow");
    marshArray[0].setNumber(123);

    wstring result = marshArray[0].getEnd();

    assert(result == L"Moscow");
}

void testnumber() {

    const int ARRAY_SIZE = 1;
    MARSH marshArray[ARRAY_SIZE];

    marshArray[0].setStart(L"Krasnodar");
    marshArray[0].setEnd(L"Moscows");
    marshArray[0].setNumber(123);

    int result = marshArray[0].getNumber();

    assert(result == 123);
}

void testMarsh() {
    teststart();
    testend();
    testnumber();
}
