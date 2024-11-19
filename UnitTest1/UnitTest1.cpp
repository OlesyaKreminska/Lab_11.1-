#include "pch.h"
#include "CppUnitTest.h"
#include <fstream>
#include <string>
#include "../Lab_11.1C++/Lab_11.1C++.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestForFindPattern
{
    TEST_CLASS(UnitTestForFindPattern)
    {
    public:

        TEST_METHOD(TestNoPattern)
        {
            const char* testFile = "test2.txt";
            std::ofstream fout(testFile);
            fout << "This is a test line.\n";
            fout << "Another line without the pattern.\n";
            fout.close();

            std::stringstream buffer;
            std::streambuf* oldCoutBuffer = std::cout.rdbuf(buffer.rdbuf());
            FindPattern(testFile);
            std::cout.rdbuf(oldCoutBuffer);

            std::string output = buffer.str();
            Assert::IsTrue(output.find("No such pattern found") != std::string::npos,
                L"No pattern should be found in the file.");
        
        }

    };
}