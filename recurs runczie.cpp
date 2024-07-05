#include <iostream>
#include <time.h>
#include <iomanip>
#include <limits.h>

using namespace std;

int searchMin(int* massiv, int massivSize, int startIndex, int& min);
void initAndPrintMassiv(int* massiv, int massivSize);


int main()
{
    srand((int)time(NULL));
    int const massivSize = 100;
    int massiv[massivSize];
    int min = INT_MAX;
    initAndPrintMassiv(massiv, massivSize);
    searchMin(massiv, massivSize, 0, min);
    cout << "Min = " << min << endl;
    return 0;
}

int searchMin(int* massiv, int massivSize, int startIndex, int& min)
{
    int localMin = 0;
    if (startIndex + 9 == massivSize)
    {
        return 0;
    }
    for (int i = startIndex; i < startIndex + 10; i++)
    {
        localMin += massiv[i];
    }
    if (localMin < min)
    {
        min = localMin;
    }
    return searchMin(massiv, massivSize, startIndex + 1, min);
}


void initAndPrintMassiv(int* massiv, int massivSize)
{
    for (int i = 0; i < massivSize; i++)
    {
        *(massiv + i) = rand() % 101;
        cout << fixed << setw(4) << *(massiv + i) << " ";
        if (i % 10 == 9)
        {
            cout << endl;
        }
    }
}