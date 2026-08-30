#include <iostream>
using namespace std;

void _sort(int arr[], int n)
{
    int count0 = 0, count1 = 0, count2 = 0; // {2, 1, 0, 0, 2};
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            count0++;
        }
        else if (arr[i] == 1)
        {
            count1++;
        }
        else
        {
            count2++;
        }
    }

    int idx = 0;
    for (int i = 0; i < count0; i++)
    {
        arr[idx++] = 0;
    }

    for (int i = 0; i < count1; i++)
    {
        arr[idx++] = 1;
    }

    for (int i = 0; i < count2; i++)
    {
        arr[idx++] = 2;
    }
}

void dutchNationalFlagAlgo(int arr[], int n)
{
    int low = 0, mid = 0, high = n - 1;

    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[mid], arr[low]);
            mid++, low++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{

    int arr[5] = {2, 1, 0, 0, 2};
    int n = 5;
    printArr(arr, n);
    // _sort(arr, n);
    dutchNationalFlagAlgo(arr, n);
    printArr(arr, n);

    return 0;
}