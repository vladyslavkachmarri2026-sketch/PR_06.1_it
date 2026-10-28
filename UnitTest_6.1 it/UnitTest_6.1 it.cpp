#include "pch.h"                 
#include "CppUnitTest.h"        
#include "../PR_06.1 it.cpp"   
                   
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest61it           // простір імен тестів (назва довільна)
{
    TEST_CLASS(UnitTest61it)     // клас, який об'єднує тести
    {
    public:
        // Тест 1: перевіряє підрахунок кількості та суми
        TEST_METHOD(TestCountAndSum)
        {
            // Тестовий масив. Не підходять лише a[0]=3 та a[8]=15
            // (вони непарні, а їхні індекси 0 і 8 кратні 8)
            int a[10] = { 3, 4, 5, 6, 7, 9, 11, 13, 15, 8 };

            // Очікуємо 8 елементів: 10 - 2 = 8
            Assert::AreEqual(8, CountCriterion(a, 10));

            // Очікуємо суму: 4+5+6+7+9+11+13+8 = 63
            Assert::AreEqual(63, SumCriterion(a, 10));
        }

        // Тест 2: перевіряє заміну нулями
        TEST_METHOD(TestZero)
        {
            int a[10] = { 3, 4, 5, 6, 7, 9, 11, 13, 15, 8 };

            ZeroCriterion(a, 10);        // замінюємо підходящі елементи нулями

            Assert::AreEqual(3, a[0]);   // не підійшов, тому залишився
            Assert::AreEqual(15, a[8]);  // не підійшов, тому залишився
            Assert::AreEqual(0, a[1]);   // підійшов, тому став нулем
        }
    };
}