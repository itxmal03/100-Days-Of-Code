#include <iostream>
#include <climits>
using namespace std;

void sum3Elements(int array[10], int size);
void sum3SlidigElements(int array[10], int size);
void smallestSubArraySum(int array[10], int size);

int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    int size = sizeof(arr) / sizeof(arr[0]);
    // sum3Elements(arr, size);
    // sum3SlidigElements(arr, size);
    smallestSubArraySum(arr, size);

    return 0;
}
 
void sum3Elements(int array[10], int size)
{
    // Method #01
    // int sum = 0, counter = 0, setNo = 1;
    // for (int i = 0; i < size; i++)
    // {
    //     sum = sum + array[i];
    //     counter++;
    //     if (counter == 3)
    //     {
    //         cout << "Sum of " << setNo << " set of 3 numbers is " << sum << endl;
    //         sum = 0;
    //         counter = 0;
    //         setNo++;
    //     }
    // }

    int sum = 0, setNo = 1;
    // Method 2
    for (int i = 0; i + 2 < size; i = i + 3)
    {
        sum = array[i] + array[i + 1] + array[i + 2];
        cout << "Sum of " << setNo << " set of 3 numbers is " << sum << endl;
        setNo++;
    }
}

void sum3SlidigElements(int array[10], int size)
{
    // Method #01
    // int sum = 0, setNo = 1;
    // for (int i = 0; i + 2 < size; i++)
    // {
    //     sum = array[i] + array[i + 1] + array[i + 2];
    //     cout << "Sum of " << setNo << " set of 3 numbers is " << sum << endl;
    //     setNo++;
    // }

    // Method 2
    int sum = 0, setNo = 1, counter = 0;
    for (int i = 0; i < size; i++)
    {
        sum = sum + array[i];
        counter++;
        if (counter == 3)
        {
            cout << "Sum of " << setNo << " set of 3 numbers is " << sum << endl;
            counter = 0;
            sum = 0;
            setNo++;
            i = i - 2;
        }
    }
}

void smallestSubArraySum(int array[10], int size)
{
    int windowSum = 0;       // sum of current window
    int minLength = INT_MAX; // store smallest length found
    int start = 0;           // left side of window

    for (int end = 0; end < size; end++)
    {
        windowSum += array[end]; // expand window

        // shrink window while condition is satisfied
        while (windowSum >= 7)
        {
            int currentLength = end - start + 1;
            minLength = min(minLength, currentLength);

            windowSum -= array[start]; // remove left element
            start++;                   // move window forward
        }
    }

    if (minLength == INT_MAX)
    {
        cout << "No subarray found";
    }
    else
    {
        cout << "Length of smallest subarray: " << minLength;
    }
}