#include <iostream>
using namespace std;

// dynamic arrays using pointers
int main()
{

    int size;
    cout << "enter size: ";
    cin >> size;
    int *array = new int[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter number on index [" << i << "] : ";
        cin >> array[i];
    }

    for (int i = 0; i < size; i++)
    {
        // cout << array[i] << " ";
        //  cout << array[i] <<" ";
        cout << *(array + i) << " ";
    }

    delete[] array;
    array = NULL;

    return 0;
}