#include <iostream>
using namespace std;

// majority element will exist always and can be find through moore's voting algorithm
int majorityElement(int *arr, int size)
{
    int freq = 0, ans = 0;
    for (int i = 0; i < size; i++)
    {
        if (freq == 0)
        {
            ans = arr[i];
        }
        if (ans == arr[i])
        {
            freq++;
        }
        else
        {
            freq--;
        }
    }
    return ans;
}

// if majority element don't exist return -1
int majorityElement2(int *arr, int size)
{
    int freq = 0, ans = 0;
    for (int i = 0; i < size; i++)
    {
        if (freq == 0)
        {
            ans = arr[i];
        }
        if (ans == arr[i])
        {
            freq++;
        }
        else
        {
            freq--;
        }
    }

    int count = 0;

    for (int x = 0; x < size; x++)
    {
        if (ans == arr[x])
        {
            count++;
        }
    }

    if (count > size / 2)
    {
        return ans;
    }
    else
    {
        return -1;
    }

    return ans;
}

int main()
{
    int array[5] = {1, 4, 3, 4, 4};
    cout << majorityElement(array, 5) << endl;
    int array2[5] = {1, 2, 3, 4, 5};
    cout << majorityElement2(array2, 5) << endl;
    return 0;
}