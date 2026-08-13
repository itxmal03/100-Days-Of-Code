#include <iostream>
#include <vector>
using namespace std;

int peakIndexInMountainArray(vector<int> &arr)
{
    int start = 1, end = arr.size() - 2;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
        {
            return mid;
        }
        else if (arr[mid] > arr[mid - 1])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}

int byLinearSearch(vector<int> &arr)
{
    int n = arr.size() - 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i - 1] < arr[i] && arr[i] > arr[i + 1])
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    vector<int> arr2 = {0, 2, 1, 0};
    vector<int> arr = {1, 2, 3, 4, 5, 3, 2};
    cout << byLinearSearch(arr) << endl;
    cout << byLinearSearch(arr2) << endl;
    cout << peakIndexInMountainArray(arr) << endl;
    cout << peakIndexInMountainArray(arr2) << endl;

    return 0;
}