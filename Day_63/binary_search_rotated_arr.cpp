#include <iostream>
#include <vector>
using namespace std;

int binSearchRotatedArr(const vector<int> &arr, int target)
{
    if (arr.empty())
        return -1;

    int start = 0, end = arr.size() - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2; 

        if (target == arr[mid])
            return mid;

        if (arr[start] <= arr[mid])
        { 
            if (target >= arr[start] && target < arr[mid])
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
            if (target > arr[mid] && target <= arr[end])
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

int main()
{
    vector<int> arr = {4, 5, 6, 3, 2, 1};
    cout << binSearchRotatedArr(arr, 5) << endl;

    return 0;
}