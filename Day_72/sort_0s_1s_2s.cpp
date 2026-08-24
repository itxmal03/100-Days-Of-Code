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
    _sort(arr, n);
    printArr(arr, n);

    return 0;
}