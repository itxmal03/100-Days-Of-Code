#include <iostream>
#include <vector>
using namespace std;

// iterative approach
int binarySearch(vector<int> &vec, int target)
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

// recursive appraoch
int recBinarySearch(vector<int> &vec, int target, int start, int end)
{

    if (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (target < vec[mid])
        {
            return recBinarySearch(vec, target, start, mid - 1);
        }
        else if (target > vec[mid])
        {
            return recBinarySearch(vec, target, mid + 1, end);
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
    cout << recBinarySearch(vec, target, 0, vec.size() - 1) << endl;
    return 0;
}
