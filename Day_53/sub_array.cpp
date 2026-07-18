#include <iostream>
#include <climits>
using namespace std;

void printSubArray()
{
    int n = 5;
    int arr[5] = {1, 2, 3, 4, 5};

    for (int start = 0; start < n; start++)
    {
        for (int end = start; end < n; end++)
        {

            for (int i = start; i <= end; i++)
            {
                cout << arr[i];
            }
            cout << " ";
        }
        cout << endl;
    }
}

int maxSubArrSum()
{
    int n = 5;
    int arr[5] = {1, 2, 3, 4, 5};

    int final_sum = INT_MIN;

    for (int start = 0; start < n; start++)
    {
        for (int end = start; end < n; end++)
        {
            int local_sum = 0;

            for (int i = start; i <= end; i++)
            {
                local_sum += arr[i];
            }
            final_sum = max(local_sum, final_sum);
        }
    }

    return final_sum;
}

int maxSubArrSum2()
{
    int n = 5;
    int arr[5] = {1, 2, 3, 4, 5};

    int final_sum = INT_MIN;

    for (int start = 0; start < n; start++)
    {
        int local_sum = 0;
        for (int end = start; end < n; end++)
        {
            local_sum += arr[end];
            final_sum = max(local_sum, final_sum);
        }
    }

    return final_sum;
}

int kadanesAlgoMaxSum()
{

    int n = 5;
    int arr[5] = {1, 2, 3, 4, 5};

    int max_sum = INT_MIN;
    int currentSum = 0;
    for (int i = 0; i < n; i++)
    {
        currentSum += arr[i];
        max_sum = max(currentSum, max_sum);
        if (currentSum < 0)
        {
            currentSum = 0;
        }
    }

    return max_sum;
}

int main()
{
    printSubArray();
    cout << maxSubArrSum() << endl;
    cout << maxSubArrSum2() << endl;
    cout << kadanesAlgoMaxSum() << endl;

    return 0;
}