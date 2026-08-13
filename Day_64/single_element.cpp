#include <iostream>
#include <vector>
using namespace std;

// single element

int singleNonDuplicate(vector<int> &arr)
{
    if (arr.empty())
        return -2;
    int start = 0, end = arr.size() - 1;
    int n = arr.size();

    if (n == 1)
        return arr[0];

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (mid == 0 && arr[mid] != arr[1])
        {
            return arr[mid];
        }

        if (mid == n - 1 && arr[n - 1] != arr[n - 2])
        {
            return arr[mid];
        }
        if (arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1])
        {
            return arr[mid];
        }
        else if (mid % 2 == 0)
        {
            // left side of array
            if (arr[mid] == arr[mid - 1])
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        else
        {
            if (arr[mid] == arr[mid - 1])
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
    }
    return -1;
}

int viaLinearSearch(vector<int> &arr)
{
    if (arr.empty())
        return -2;

    int n = arr.size();
    if (n == 1)
        return arr[0];

    if (arr[0] != arr[1])
    {
        return arr[0];
    }

    if (arr[n - 1] != arr[n - 2])
    {
        return arr[n - 1];
    }

    for (int i = 1; i < n; i++)
    {
        if (arr[i] != arr[i - 1] && arr[i] != arr[i + 1])
        {
            return arr[i];
        }
    }

    return -1;
}

int viaBitwiseOp(vector<int> &arr)
{
    if (arr.empty())
        return -1;

    int n = arr.size();
    
    int result = 0;

    for (int i = 0; i < n; i++)
    {
        result ^= arr[i];
    }
    return result;
}

int main()
{

    vector<int> arr = {1, 1, 2, 2, 3, 4, 4};
    cout << singleNonDuplicate(arr) << endl;
    cout << viaLinearSearch(arr) << endl;
    cout << viaBitwiseOp(arr) << endl;

    return 0;
}