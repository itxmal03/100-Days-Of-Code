#include <iostream>
#include <cmath>
using namespace std;

void checkDiff(int array[], int size);
void checkAlternating(int array[], int size);
void countPeakandValleys(int array[], int size);

int main()
{
    int array[4] = {1, 8, 6, 7};
    int size = sizeof(array) / sizeof(array[0]);
    // checkDiff(array, size);
    // checkAlternating(array, size);
    countPeakandValleys(array, size);
    return 0;
}

void checkDiff(int array[], int size)
{
    bool isYes = true;
    for (int i = 0; i < size - 1; i++)
    {
        if (fabs(array[i] - array[i + 1]) != 1)
        {
            isYes = false;
            break;
        }
    }
    if (isYes)
        cout << "Yes! absoulte difference of adjacent elements is 1" << endl;
    else
        cout << "No! absoulte difference of adjacent elements is not 1" << endl;
}

void checkAlternating(int array[], int size)
{
    bool isAlternating = true;
    for (int i = 1; i < size - 1; i++)
    {
        if (!((array[i] < array[i - 1] && array[i] < array[i + 1]) || (array[i] > array[i - 1] && array[i] > array[i + 1])))
        {
            isAlternating = false;
            break;
        }
    }
    if (isAlternating)
        cout << "yes array is alternating" << endl;
    else
        cout << "Array is not alternating" << endl;
}

void countPeakandValleys(int array[], int size)
{
    int peaks = 0, valleys = 0;
    for (int i = 1; i < size - 1; i++)
    {
        if ((array[i] < array[i - 1] && array[i] < array[i + 1]))
        {
            valleys++;
        }
        if ((array[i] > array[i - 1] && array[i] > array[i + 1]))
        {

            peaks++;
        }
    }
    cout << "total peaks are: " << peaks << " and total valleys are: " << valleys << endl;
}