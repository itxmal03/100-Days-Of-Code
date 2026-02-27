#include <iostream>
#include <climits>
using namespace std;

void printSubArrays(int array[], int size);
void maxSubArrSum(int array[], int size);

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    printSubArrays(arr, 5);
    cout << endl;
    maxSubArrSum(arr, 5);
    return 0;
}

void printSubArrays(int array[], int size)
{
    for (int start = 0; start < size; start++)
    {
        for (int end = start; end < size; end++)
        {
            for (int i = start; i <= end; i++)
            {
                cout << array[i];
            }
            cout << " ";
        }
        cout << endl;
    }
}

void maxSubArrSum(int array[], int size)
{
    int maxSum = INT_MIN;
    for (int start = 0; start < size; start++)
    {
        int currSum = 0;
        for (int end = start; end < size; end++)
        {
            currSum += array[end];
            maxSum = max(currSum, maxSum);
        }
    }
    cout << "max subarray sum is: " << maxSum << endl;
}