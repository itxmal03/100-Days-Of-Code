#include <iostream>
#include <vector>
using namespace std;


bool isValid(vector<int> arr, int n, int m, int maxPages)
{
    int students = 1, pages = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > maxPages)
        {
            return false;
        }

        if (pages + arr[i] <= maxPages)
        {
            pages += arr[i];
        }
        else
        {
            students++;
            pages = arr[i];
        }
    }
    return students > m ? false : true;
}

int booksAllocation(vector<int> arr, int m)
{
    int n = arr.size();

    if (m > n)
    {
        return -1;
    }

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    int st = 0, end = sum;
    int ans = -1;
    while (st <= end)
    {
        int mid = st + (end - st) / 2;

        if (isValid(arr, n, m, mid)) // left
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            st = mid + 1;
        }
    }
    return ans;
}


int main()
{
    vector<int> arr = {2, 3, 4, 5};
    int students = 2;
    cout << booksAllocation(arr, students) << endl;
    return 0;
}