#include <iostream>
#include <vector>
#include <algorithm>

class MasiveString {
private:
    std::vector<std::wstring> strings;
    std::vector<int> lengths;

public:
    void addString(const std::wstring& str, int length);

    std::wstring getString(int index);

    MasiveString mergeArrays(const MasiveString& array2);

    void printElement(int index);

    void printArray();
};
