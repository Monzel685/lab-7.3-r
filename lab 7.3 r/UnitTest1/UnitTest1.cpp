#include "pch.h"
#include "CppUnitTest.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestCountLocalMinima)
        {
            const int size = 3;
            int* a[size];

            int row0[] = { 1, 2, 3 };
            int row1[] = { 4, 0, 6 };
            int row2[] = { 7, 8, 9 };
            a[0] = row0;
            a[1] = row1;
            a[2] = row2;

            int expectedCount = 1; // только средний элемент (0) является локальным минимумом
            int actualCount = countLocalMinima(a, size);

            Assert::AreEqual(expectedCount, actualCount);
        }

        TEST_METHOD(TestSumAboveMainDiagonal)
        {
            const int size = 3;
            int* a[size];

            int row0[] = { 1, 2, 3 };
            int row1[] = { 4, 5, 6 };
            int row2[] = { 7, 8, 9 };
            a[0] = row0;
            a[1] = row1;
            a[2] = row2;

            int expectedSum = 11; // abs(2) + abs(3) + abs(6) = 2 + 3 + 6 = 11
            int actualSum = sumAboveMainDiagonal(a, size);

            // Добавлено утверждение для проверки результата
            Assert::AreEqual(expectedSum, actualSum);
        }
    };
}
