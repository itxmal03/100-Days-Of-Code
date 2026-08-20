#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n)
{
    int temp = 0;
    for (int i = 0; i < n - 1; i++)
    {
        bool isSwap = false;
        for (int j = 0; j < (n - i - 1); j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                /*
                via 3rd variable
                temp = arr[j];
                arr[j]= arr[j+1];
                arr[j+1]= temp;

                not using 3rd var
                 arr[j] = arr[j]+arr[j+1];
                 arr[j+1] = arr[j]-arr[j+1];
                 arr[j]= arr[j]-arr[j+1];

                 bitwise OR 
                 arr[j] = arr[j] ^ arr[j+1];
                 arr[j+1] = arr[j] ^ arr[j+1]; // (a^b)^a = b
                 arr[j] = arr[j] ^ arr[j+1];   // (a^b)^b = a
                */
                isSwap = true;
            }
        }
        if (!isSwap)
        {
            return;
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
    int arr[5] = {4, 3, 5, 2, 1};
    printArr(arr, 5);
    bubbleSort(arr, 5);
    printArr(arr, 5);

    return 0;
}