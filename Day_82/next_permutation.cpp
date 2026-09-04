#include <iostream>
#include <algorithm> // for reverse, swap
using namespace std;

void nextPermutation(int arr[], int n)
{
    int pivot = -1;

    // 1. Find the pivot (rightmost element smaller than next)
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] < arr[i + 1])
        {
            pivot = i;
            break;
        }
    }

    // 2. If no pivot exists, reverse the entire array (last permutation)
    if (pivot == -1)
    {
        reverse(arr, arr + n); 
        return;                
    }

    // 3. Find the rightmost element greater than pivot and swap
    for (int i = n - 1; i > pivot; i--)
    {
        if (arr[i] > arr[pivot])
        {
            swap(arr[i], arr[pivot]);
            break;
        }
    }

    // 4. Reverse the suffix (elements after pivot)
    int x = pivot + 1, y = n - 1;
    while (x < y)
    { // FIX 3: Use < not >
        swap(arr[x], arr[y]);
        x++;
        y--;
    }
}

int main()
{
    int arr[] = {1, 2, 3};
    int n = 3;
    nextPermutation(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " "; // Output: 1 3 2
    }
    cout << endl;
    return 0;
}