#include <iostream>
using namespace std;

int linearSearch(int array[], int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] == target)  //found
            return i;
    }
    return -1;  //not found
}

int main()
{
    int arr[5] = {1, 2, 3, 5, 6};
    int size = 5;
    int target = 39;
    int index = linearSearch(arr, size, target);
    cout << index << endl;
    return 0;
}