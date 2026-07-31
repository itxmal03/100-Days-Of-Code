#include <iostream>
using namespace std;

int func(int *array, int n)
{
    if (n == 0)
        return 0;

    int maxProfit = 0, bestBuy = array[0];

    for (int i = 1; i < n; i++)
    {
        if (array[i] > bestBuy)
        {
            maxProfit = max(maxProfit, array[i] - bestBuy);
        }
        bestBuy = min(bestBuy, array[i]);
    }
    return maxProfit;
}

int main()
{
    int array[6] = {7, 1, 3, 5, 6, 4};

    cout << "Max profit " << func(array, 6) << endl;

    return 0;
}