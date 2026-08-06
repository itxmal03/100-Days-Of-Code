#include <iostream>
using namespace std;

int *method1(int *arr, int n)
{
    int *ans = new int[n];
    int prod = 1;
    for (int i = 0; i < n; i++)
    {
        prod *= arr[i];
    }

    for (int j = 0; j < n; j++)
    {
        ans[j] = prod / arr[j];
    }

    return ans;
}

int main()
{
    int array[5] = {1, 2, 3, 4, 5};

    int *ansArray = method1(array, 5);

    for (int i = 0; i < 5; i++)
    {
        cout << ansArray[i] << " ";
    }

    delete ansArray;

    return 0;
}