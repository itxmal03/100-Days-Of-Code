#include <iostream>
#include <vector>
using namespace std;

void missingNumber(int arr[], int size);
void addOne(vector<int> &v);

int main()
{
    int array[4] = {1, 2, 3, 5};
    int size = sizeof(array) / sizeof(array[0]);
    vector<int> vec = {9, 9, 9, 0};
    missingNumber(array ,size);
    // cout << "\nVector after before one:\n";
    // for (auto x : vec)
    // {
    //     cout << x << " ";
    // }
    // addOne(vec);
    // cout << "\nVector after adding one:\n";
    // for (auto x : vec)
    // {
    //     cout << x << " ";
    // }
    cout << endl;
    return 0;
}

void missingNumber(int arr[] , int size)
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
    int exactSum = ((size + 1) * (size + 2)) / 2;
    cout << "total sum of consective 5 numbers!: " << exactSum << endl;
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    cout << "Missing number is: " << (exactSum - sum) << endl;
}

void addOne(vector<int> &v)
{
    for (int i = v.size() - 1; i >= 0; i--)
    {
        if (v[i] == 9)
        {
            v[i] = 0;
        }
        else
        {
            v[i]++;
            return;
        }
    }
    v.insert(v.begin(), 1);
}