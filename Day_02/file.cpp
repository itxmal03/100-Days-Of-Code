#include <iostream>
using namespace std;
// sort array by insertion method
void sortArray(int array[10], int size);

int main()
{
    int array[10] = {2, 4, 1, 3, 6, 8, 7, 5, 0, 9};
    int sizeofArray = sizeof(array) / sizeof(array[0]);

    sortArray(array, sizeofArray);
    for (int arr : array)
    {
        cout << arr << " ";
    }

    return 0;
}

void sortArray(int array[10], int size)
{
    for (int i = 1; i < size; i++)
    {
        int x = i;
        while (x > 0 && array[x] < array[x - 1])
        {
            swap(array[x - 1], array[x]);
            //the logic below will work but in case of int it can overflow when when we add two values
            // array[x] = array[x] + array[x - 1];
            // array[x - 1] = array[x] - array[x - 1];
            // array[x] = array[x] - array[x - 1];
            x--;
        }
    }
}