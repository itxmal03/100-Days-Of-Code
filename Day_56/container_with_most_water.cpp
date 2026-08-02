#include <iostream>
using namespace std;

int method1(int *arr, int n)
{
    int mostWater = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int w = j - i;
            int h = min(arr[j], arr[i]);
            int currentWater = w * h;

            mostWater = max(currentWater, mostWater);
        }
    }
    return mostWater;
}

int main()
{
    int array[5] = {1, 3, 6, 8, 5};

    cout << "Most water is : " << method1(array, 5) << endl;

    return 0;
}