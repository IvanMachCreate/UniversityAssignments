#include <iostream>
using namespace std;

int main()
{
    int yearX, yearY, temp;
    cin >> yearX >> yearY;
    if (yearX > yearY)
    {
        temp = yearX;
        yearX = yearY;
        yearY = temp;
    }

    int numLeapYears = 0;
    for (; yearX <= yearY; yearX++)
    {
        if (yearX % 400 == 0 || (yearX % 4 == 0 && yearX % 100 != 0))
        {
            ++numLeapYears;
        }
    }

    cout << numLeapYears;
    return 0;
}