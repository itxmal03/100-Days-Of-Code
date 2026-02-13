#include <iostream>
using namespace std;

void intersection(int arr1[], int arr2[])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (arr1[i] == arr2[j])
            {
                arr1[i] = 0;
            }
        }
    }

    // move 0 to end

    for (int i = 4; i > 1; i--)
    {
        int x = i;
        while (x > 0 && arr1[x] > arr1[x - 1])
        {
            swap(arr1[x], arr1[x - 1]);
            x--;
        }
    }

    for (int x = 0; x < 4; x++)
    {
        cout << arr1[x] << " ";
    }
    cout << endl;
}

int main()
{
    int array1[4] = {2, 4, 5, 6};
    int array2[3] = {1, 2, 4};
    intersection(array1, array2);
    return 0;
}