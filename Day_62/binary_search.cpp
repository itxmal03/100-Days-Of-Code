#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> vec, int target)
{
    if (vec.empty())
        return -1;
    int start = 0, end = vec.size() - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2; // Fix 2
        
        if (target < vec[mid])
        {
            end = mid - 1;
        }
        else if (target > vec[mid])
        {
            start = mid + 1;
        }
        else
        {
            return mid;
        }
    }

    return -1;
}

int main()
{
    vector<int> vec = {-1, 0, 1, 2, 3, 4, 5, 6, 7};
    int target = 3;
    cout << binarySearch(vec, target) << endl;

    return 0;
}
