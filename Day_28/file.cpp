#include <iostream>
#include <vector>
using namespace std;

vector<int> pairSumBruteForce(int *arr, int size, int target)
{
    vector<int> ans = {-1, -1};
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] + arr[j] == target)
            {
                ans[0] = i;
                ans[1] = j;
                return ans;
            }
        }
    }
    return ans;
}

vector<int> pairSumBruteForce2(int *arr, int size, int target)
{
    vector<int> ans = {-1, -1};
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (arr[i] + arr[j] == target && i != j)
            {
                ans[0] = i;
                ans[1] = j;
                return ans;
            }
        }
    }
    return ans;
}

// for sorted array
vector<int> pairSumOptimal(int *arr, int size, int target)
{
    vector<int> ans = {-1, -1};
    int i = 0, j = size - 1;
    while (i < j)
    {
        if (arr[i] + arr[j] > target)
        {
            j--;
        }
        else if (arr[i] + arr[j] < target)
        {
            i++;
        }
        else
        {
            ans[0] = i;
            ans[1] = j;
            return ans;
        }
    }

    return ans;
}

int main()
{
    int array[6] = {3, 5, 2, 1, 9, 0};
    vector<int> a = pairSumBruteForce2(array, 6, 10);
    cout << a[0] << " , " << a[1] << endl;

    int sortedArray[5] = {1, 3, 5, 7, 9};
    vector<int> b = pairSumOptimal(sortedArray, 5, 14);
    cout << b[0] << " , " << b[1] << endl;
    return 0;
}