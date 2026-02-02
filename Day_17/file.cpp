#include <iostream>
using namespace std;

void checkSorted(int arr[], int size);
void checkIncreasing(int arr[], int size);
void checkTargetSum(int arr[], int size, int target);

int main()
{
    int array[5] = {2, 3, 4, 4, 6};
    int size = sizeof(array) / sizeof(array[0]);
    // checkSorted(array, size);
    // checkIncreasing(array, size);
    checkTargetSum(array, size, 10);
    return 0;
}

// check whether array is sorted in ascending order
void checkSorted(int arr[], int size)
{
    bool isSorted = true;
    for (int i = 0; i < (size - 1); i++)
    {
        // if (arr[i] > arr[i + 1]) both work same
        if (!(arr[i] <= arr[i + 1]))
        {
            isSorted = false;
            break;
        }
    }
    if (isSorted)
    {
        cout << "yes array is sorted in ascending order!" << endl;
    }
    else
    {
        cout << "No array is not sorted in ascending order!" << endl;
    }
}

// check whether array is strictly increasing or not
void checkIncreasing(int arr[], int size)
{
    bool isIncreasing = true;
    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i + 1] <= arr[i])
        {
            isIncreasing = false;
            break;
        }
    }

    if (isIncreasing)
        cout << "yes array is strictly increasing" << endl;
    else
        cout << "no array is not strictly increasing" << endl;
}

// check whether a pair exists whose sum is equal to target
void checkTargetSum(int arr[], int size, int target)
{
    bool exists = false;
    int pair[2] = {0};
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i != j && ((arr[i] + arr[j]) == target))
            {
                pair[0] = arr[i];
                pair[1] = arr[j];
                exists = true;
                break;
            }
        }
        if (exists)
        {
            break;
        }
    }

    if (exists)
    {
        cout << "yes a pair exists whose sum is = to: " << target << endl;
        cout << "and pair is : \n";
        for (int i : pair)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "no pair exists!" << endl;
    }
}