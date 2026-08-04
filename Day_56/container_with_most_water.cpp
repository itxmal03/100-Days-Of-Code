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

//--- optimized solution
int method2(int *arr, int n)
{
    int mostWater = 0;
    int lp = 0, rp = n - 1;
    while (lp < rp)
    {
        int w = rp - lp;
        int h = min(arr[lp], arr[rp]);
        int currentWater = w * h;
        mostWater = max(currentWater, mostWater);

        arr[lp] < arr[rp] ? lp++ : rp--;
    }
    return mostWater;
}

int main()
{
    int array[6] = {1, 3, 6, 8, 5, 7};

    cout << "Most water is by brute force : " << method1(array, 6) << endl;

    cout << "Most water is by optimized appr : " << method2(array, 6) << endl;

    return 0;
}