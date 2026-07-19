#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// majority element will always exisit (>n/2)

vector<int> majorityElement(vector<int> &v)
{
    vector<int> ans;

    for (auto &&val : v)
    {
        int freq = 0;
        for (auto &&el : v)
        {
            if (el == val)
            {
                freq++;
            }
        }
        if (freq > v.size() / 2)
        {
            ans.push_back(val);
            ans.push_back(freq);
            return ans;
        }
    }
    return ans;
}

vector<int> optimized(vector<int> &v)
{
    vector<int> ans;

    // sort
    sort(v.begin(), v.end());

    int freq = 1;
    int element = v[0];

    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] == v[i - 1])
        {
            freq++;
        }
        else
        {
            freq = 1;
            element = v[i];
        }
        if (freq > v.size() / 2)
        {
            ans.push_back(element);
            ans.push_back(freq);
            return ans;
        }
    }

    return ans;
}

int moore_algorithm(vector<int> &v)
{
    int freq = 0, ans = 0;

    for (int i = 0; i < v.size(); i++)
    {
        if (freq == 0)
        {
            ans = v[i];
        }
        if (ans == v[i])
        {
            freq++;
        }
        else
        {
            freq--;
        }
    }

    // edge case if  majoriy element not exist then

    int count = 0;
    for (auto &&i : v)
    {
        if (ans == i)
        {
            count++;
        }
    }

    if (count > v.size() / 2)
    {
        return ans;
    }
    else
        return -1;

}

int main()
{
    vector<int> nums = {1, 1, 5, 5,3};
 //   vector<int> ans = majorityElement(nums);
 //   cout << "Majority element is : " << ans[0] << " and freq is  " << ans[1] << endl;

 //   ans = optimized(nums);
 //   cout << "Majority element is : " << ans[0] << " and freq is  " << ans[1] << endl;

    cout << "maj element is " << moore_algorithm(nums) << endl;
    return 0;
}