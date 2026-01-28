#include <iostream>
using namespace std;

void missingNumber(int arr[4]);

int main()
{
    int array[4] = {1, 2, 4};
    missingNumber(array);
    return 0;
}

void missingNumber(int arr[4])
{
    // Mehtod 1 - Sort array
    // for (int i = 1; i < 4; i++)
    // {
    //     int x = i;
    //     while (x > 0 && arr[x] < arr[x - 1])
    //     {
    //         swap(arr[x], arr[x - 1]);
    //         x--;
    //     }
    // }
    // int missingNum;
    // bool miss = false;
    // for (int n = 0; n < 3; n++)
    // {
    //     if ((arr[n] + 1) != arr[n + 1])
    //     {
    //         miss = true;
    //         missingNum = arr[n] + 1;
    //     }
    // }
    // if (miss)
    //     cout << "Missing number is: " << missingNum << endl;
    // else
    //     cout << "No number is missing!" << endl;

    // Method 2
    int exactSum = ((4 + 1) * (4 + 2)) / 2;
    cout << "total sum of consective first 4 numbers!: " << exactSum << endl;
    int sum = 0;
    for (int i = 0; i < 4; i++)
    {
        sum += arr[i];
    }
    cout << "Missing number is: " << (exactSum - sum) << endl;
}