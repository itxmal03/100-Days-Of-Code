#include <iostream>
using namespace std;

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int current = arr[i];
        int prev = i - 1;
        while (prev >= 0 && arr[prev] > current)
        {
            arr[prev + 1] = arr[prev];
            prev--;
        }
        arr[prev + 1] = current;
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
    int arr[5] = {4, 3, 5, 2, 1};
    printArr(arr, 5);
    insertionSort(arr, 5);
    printArr(arr, 5);

    return 0;
}