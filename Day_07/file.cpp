#include <iostream>
#include <climits>
using namespace std;

// sliding window practise
// sum is >= target number

void smallestSubArr(int array[], int size, int target);

void largestSubArr(int array[], int size, int target);

void equalSubArr(int array[], int size, int target);

int main()
{
    int array[5] = {1, 2, 4, 6, 0};
    int size = sizeof(array) / sizeof(array[0]);
    smallestSubArr(array, size, 11);
    cout << endl;
    largestSubArr(array, size, 17);

    return 0;
}

void smallestSubArr(int array[], int size, int target)
{
    int sum = 0;
    int minLength = INT_MAX;
    int startIndex = 0;

    for (int currentIndex = 0; currentIndex < size; currentIndex++)
    {
        sum = sum + array[currentIndex];
        while (sum >= target)
        {
            int currentLength = currentIndex - startIndex + 1;
            minLength = min(minLength, currentLength);
            sum = sum - array[startIndex];
            startIndex++;
        }
    }

    if (minLength == INT_MAX)
    {
        cout << "No subarray found";
    }
    else
    {
        cout << "The min length of subarray whose sum is equal to or greater than: " << target << " is: " << minLength << endl;
    }
}

void largestSubArr(int array[], int size, int target)
{
    int sum = 0;
    int maxLength = 0;
    int startIndex = 0;

    for (int currentIndex = 0; currentIndex < size; currentIndex++)
    {
        sum = sum + array[currentIndex];

        if (sum >= target)
        {
            int currentLength = currentIndex - startIndex + 1;
            maxLength = max(maxLength, currentLength);
        }
    }

    if (maxLength == 0)
    {
        cout << "No subarray found";
    }
    else
    {
        cout << "The max length of subarray whose sum is equal to or greater than: " << target << " is: " << maxLength << endl;
    }
}

void equalSubArr(int array[], int size, int target)
{
    int sum = 0;
    int maxLength = 0;

    for (int i = 0; i < size; i++)
    {
       
    }
}