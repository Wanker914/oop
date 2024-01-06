#include "Masive.h"

void MasiveString::addString(const std::wstring& str, int length) {
    strings.push_back(str);
    lengths.push_back(length);
}

std::wstring MasiveString::getString(int index) {
    return strings[index];
}

MasiveString MasiveString::mergeArrays(const MasiveString& array2) {
    MasiveString mergedArray;
    mergedArray.strings = strings;
    mergedArray.lengths = lengths;

    for (int i = 0; i < array2.strings.size(); i++) {
        std::wstring str = array2.strings[i];
        int length = array2.lengths[i];

        if (std::find(strings.begin(), strings.end(), str) == strings.end()) {
            mergedArray.strings.push_back(str);
            mergedArray.lengths.push_back(length);
        }
    }

    return mergedArray;
}

void MasiveString::printElement(int index) {
    std::wcout << strings[index] << std::endl;
}

void MasiveString::printArray() {
    for (int i = 0; i < strings.size(); i++) {
        std::wcout << strings[i] << std::endl;
    }
}
