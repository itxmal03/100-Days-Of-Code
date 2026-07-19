#include <iostream>
#include <vector>
using namespace std;

vector<int> pairSum1(vector<int> x, int target)
{
    // sorted array and pair sum will  exist always
    vector<int> ans;
    for (int i = 0; i < x.size(); i++)
    {
        for (int j = i + 1; j < x.size(); j++)
        {
            if (x[i] + x[j] == target)
            {
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }
    return ans;
}

vector<int> pairSumOptimized(vector<int> x, int target)
{
    // sorted array and pair sum will  exist always
    vector<int> ans;
    int i = 0;
    int j = x.size() - 1;
    while (i < j)
    {
        if (x[i] + x[j] < target)
        {
            i++;
        }
        else if (x[i] + x[j] > target)
        {
            j--;
        }
        else
        {
            ans.push_back(i);
            ans.push_back(j);
            return ans;
        }
    }

    return ans;
}

int main()
{
    vector<int> nums = {1, 3, 4, 5};
    int target = 7;
    vector<int> ans = pairSum1(nums, target);
    cout << ans[0] << " " << ans[1] << endl;

    ans = pairSumOptimized(nums, target);
    cout << ans[0] << " " << ans[1] << endl;

    return 0;
}