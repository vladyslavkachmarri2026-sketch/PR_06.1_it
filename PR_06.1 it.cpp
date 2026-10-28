#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

// Критерій варіанту 12: елемент парний АБО його індекс не кратний 8
bool Criterion(const int value, const int index)
{
    return value % 2 == 0 || index % 8 != 0;
}

// Заповнення масиву випадковими числами з діапазону [Low; High]
void Create(int* a, const int size, const int Low, const int High)
{
    for (int i = 0; i < size; i++)
        a[i] = Low + rand() % (High - Low + 1);
}

// Виведення масиву в рядок
void Print(const int* a, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(4) << a[i];
    cout << endl;
}

// Кількість елементів, що задовольняють критерій
int CountCriterion(const int* a, const int size)
{
    int k = 0;
    for (int i = 0; i < size; i++)
        if (Criterion(a[i], i))
            k++;
    return k;
}

// Сума елементів, що задовольняють критерій
int SumCriterion(const int* a, const int size)
{
    int s = 0;
    for (int i = 0; i < size; i++)
        if (Criterion(a[i], i))
            s += a[i];
    return s;
}

// Заміна нулями елементів, що задовольняють критерій
void ZeroCriterion(int* a, const int size)
{
    for (int i = 0; i < size; i++)
        if (Criterion(a[i], i))
            a[i] = 0;
}

int main()
{
    srand((unsigned)time(NULL));
    const int n = 25;
    const int Low = 5, High = 90;
    int a[n];

    Create(a, n, Low, High);
    cout << "Initial array:" << endl;
    Print(a, n);

    cout << "Amount: " << CountCriterion(a, n) << endl;
    cout << "Sum: " << SumCriterion(a, n) << endl;

    ZeroCriterion(a, n);
    cout << "Modified array:" << endl;
    Print(a, n);
    return 0;
}