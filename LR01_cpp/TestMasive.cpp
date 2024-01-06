#include <cassert>
#include "Masive.h"

void testmassive() {

    MasiveString masive1;
    masive1.addString(L"Гранат", 5);
    masive1.addString(L"Хурма", 6);

    MasiveString masive2;
    masive2.addString(L"Хурма", 6);
    masive2.addString(L"Клубника", 6);
    masive2.addString(L"Малина", 10);

    MasiveString mergedArray = masive1.mergeArrays(masive2);

    std::wstring result = mergedArray.getString(1);

    assert(result == L"Хурма");
}
