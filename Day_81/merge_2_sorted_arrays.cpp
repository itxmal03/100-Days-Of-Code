#include <iostream>
#include <array> // this is required for arr 3
using namespace std;

void method1(int arr1[], int arr2[], int n1, int n2)
{
    int temp_array[6];
    int idx = 0;
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            if (arr1[i] <= arr2[j])
            {
                temp_array[idx++] = arr1[i];
                break;
            }
            else
            {
                temp_array[idx++] = arr2[j];
            }
        }
    }
}
int main()
{
    int arr1[6] = {1, 2, 3, 0, 0, 0};
    int arr2[3] = {2, 5, 6};

    // finding the size of array
    int s1 = sizeof(arr1); // in bytes 24bytes = 6*4(int size)
    cout << s1 << endl;
    // finding the number of elements
    int n1 = sizeof(arr1) / sizeof(arr1[0]); // 24/4 = 6 elements
    cout << n1 << endl;

    // 1. std::array<int, 6> is like Kotlin's IntArray(6) or Array<Int>
    array<int, 5> arr3 = {1, 2, 3, 4};
    cout << arr3.size() << endl;
    return 0;
}