#include <iostream>
#include <vector>
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

int *method2(int *arr, int n)
{
    int *ans = new int[n];
    for (int k = 0; k < n; k++)
        ans[k] = 1; // FIX 1: Initialize all to 1

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            { // FIX 2: Compare indices, not values
                ans[i] *= arr[j];
            }
        }
    }
    return ans;
}

vector<int> method3(const vector<int> &v)
{
    int n = v.size();
    vector<int> prefix(n, 1), suffix(n, 1), ans(n, 1);

    for (int i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] * v[i - 1];
    }
    for (int i = n - 2; i >= 0; i--)
    {
        suffix[i] = suffix[i + 1] * v[i + 1];
    }
    for (int i = 0; i < n; i++)
    {
        ans[i] = prefix[i] * suffix[i];
    }
    return ans;
}

vector<int> method4(const vector<int> &v)
{
    int n = v.size();
    vector<int> ans(n, 1);

    for (int i = 1; i < n; i++)
    {
        ans[i] = ans[i - 1] * v[i - 1];
    }

    int suffix = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        suffix *= v[i + 1];
        ans[i] *= suffix;
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

    delete[] ansArray;

    return 0;
}