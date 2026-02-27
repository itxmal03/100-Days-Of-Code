#include <iostream>
#include <algorithm>
using namespace std;

void maxRepeatingNum(int *arr, int size)
{
    int mainCounter = 0;
    int element;
    for (int i = 0; i < size; i++)
    {
        int counter = 1;
        for (int j = 0; j < size; j++)
        {
            if ((arr[i] == arr[j]) && (i != j))
            {
                counter++;
            }
        }
        if (counter > mainCounter)
        {
            mainCounter = counter;
            element = arr[i];
        }
    }

    cout << "Element is: " << element << " and number of repitition is: " << mainCounter << endl;
}

// condition for majority element is that its repitition must be >size/2;
void majorityElementBruteForce(int *arr, int size)
{
    int mainCounter = 0;
    int element;
    for (int i = 0; i < size; i++)
    {
        int counter = 1;
        for (int j = 0; j < size; j++)
        {
            if ((arr[i] == arr[j]) && (i != j))
            {
                counter++;
            }
        }
        if (counter > mainCounter)
        {
            mainCounter = counter;
            element = arr[i];
        }
    }

    if (mainCounter > size / 2)
        cout << "Element is: " << element << " and number of repitition is: " << mainCounter << endl;
    else
        cout << "No majority element exists!" << endl;
}

void majorityElementBruteForce2(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        int freq = 0;
        for (int j = 0; j < size; j++)
        {
            if (arr[i] == arr[j])
            {
                freq++;
            }
        }
        if (freq > size / 2)
        {
            cout << "majority element is : " << arr[i] << endl;
            return;
        }
    }
}

void majorityElementOptimizedBruteForce(int *arr, int size)
{
    // first sort array
    for (int k = 1; k < size; k++)
    {
        int x = k;
        while (x > 0 && arr[x] < arr[x - 1])
        {
            int temp = arr[x];
            arr[x] = arr[x - 1];
            arr[x - 1] = temp;
            x--;
        }
    }

    int freq = 1;
    for (int i = 1; i < size; i++)
    {
        if (arr[i] == arr[i - 1])
        {
            freq++;
        }
        else
        {
            freq = 1;
        }
        if (freq > size / 2)
        {
            cout << "majority element is : " << arr[i] << endl;
            return;
        }
    }
}

void majorityElementOptimizedBruteForce2(int *arr, int size)
{
    // first sort array
    for (int k = 1; k < size; k++)
    {
        int x = k;
        while (x > 0 && arr[x] < arr[x - 1])
        {
            int temp = arr[x];
            arr[x] = arr[x - 1];
            arr[x - 1] = temp;
            x--;
        }
    }

    int majorityElementIndex = size / 2;
    cout << "majority element is : " << arr[majorityElementIndex] << endl;
}

int main()
{
    int array[11] = {2, 2, 3, 2, 1, 2, 3, 3, 3, 3, 4};
    // maxRepeatingNum(array, 11);
    // majorityElementBruteForce(array, 11);
    int array2[5] = {2, 2, 3, 3, 3};
    // majorityElementBruteForce2(array2, 5);
    // majorityElementOptimizedBruteForce(array2, 5);
    majorityElementBruteForce2(array2, 5);

    return 0;
}
