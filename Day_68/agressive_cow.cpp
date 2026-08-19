#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// aggressive cows problem

bool isPossible(vector<int> &vec, int n, int c, int maxAllowedDistance)
{
    int cows = 1, lastPosition = vec[0];

    for (int i = 1; i < n; i++)
    {
        if ((vec[i] - lastPosition) >= maxAllowedDistance)
        {
            cows++;
            lastPosition = vec[i];
        }
        if (cows == c)
        {
            return true;
        }
    }
    return false;
}

int getDistane(vector<int> vec, int n, int c)
{
    sort(vec.begin(), vec.end());
    int start = 1, end = vec[n - 1] - vec[0], ans = -1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (isPossible(vec, n, c, mid))
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return ans;
}
int main()
{
    int n = 5, c = 3;
    vector<int> vec = {1, 2, 8, 4, 9};
    cout << getDistane(vec, n, c) << endl;

    return 0;
}