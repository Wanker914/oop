#include "filecheck.h"
#include "cassert"
#include "sstream"

void teststring(){

    std::ofstream testFile("testfile.txt");
    testFile << "asdsa133dsa\n";
    testFile.close();

    FileCheck checkFile("testfile.txt");
    std::stringstream output;
    std::streambuf* oldCout = std::cout.rdbuf(output.rdbuf());
    std::cout.rdbuf(oldCout);

    std::string expectedOutput = "asdsa133dsa\n";
    std::string actualOutput = output.str();
    assert(actualOutput == expectedOutput);

}

void testFile(){
    teststring();
}