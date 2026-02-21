#include <iostream>
#include <climits>
using namespace std;

int kadanesAlgorithm(int array[], int size);

int main()
{
    int array[6] = {1, -2, 4, 5, 6, -9};
    cout << "Max sum is: " << kadanesAlgorithm(array, 6) << endl;

    return 0;
}

int kadanesAlgorithm(int array[], int size)
{
    int maxSum = INT_MIN;
    int currentSum = 0;
    for (int i = 0; i < size; i++)
    {
        currentSum += array[i];
        maxSum = max(maxSum, currentSum);
        if (currentSum < 0)
        {
            currentSum = 0;
        }
    }
    return maxSum;
}
