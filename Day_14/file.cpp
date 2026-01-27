#include <iostream>
#include <string>
using namespace std;

void swapVal(int a, int b);
void oddEven(int n);
void checkDigit(string s);
void waveArray(int array[8]);

int main()
{
    // swapVal(44, 55);
    // oddEven(229);
    // checkDigit("wr3t");
    int arr[8] = {2, 1, 3, 0, 5, 8, 4, 9};
    waveArray(arr);
    return 0;
}

void swapVal(int a, int b)
{
    cout << "value of first number before swap: " << a << endl;
    cout << "value of second number before swap: " << b << endl;
    // using only one line
    a = (a + b) - (b = a);
    cout << "value of first number after swap: " << a << endl;
    cout << "value of second number after swap: " << b << endl;
}

void oddEven(int n)
{
    if (n & 1)
        cout << "number is odd!" << endl;
    else
        cout << "number is even!" << endl;
}

void checkDigit(string s)
{
    for (char c : s)
    {
        if (isdigit(c))
        {
            cout << "it contains digit" << endl;
            return;
        }

        // method 2
        //  bool allDigits = true;
        //  for (char c : s)
        //  {
        //      if (c < '0' || c > '9')
        //      {
        //          allDigits = false;
        //          break;
        //      }
        //  }
        //  if (allDigits)
        //      cout << "String contains only digits\n";
        //  else
        //      cout << "String contains non-digit characters\n";
    }
}

void waveArray(int array[8])
{
    cout << "Original array!" << endl;
    for (int a = 0; a < 8; a++)
    {
        cout << array[a] << " ";
    }

    // Method 1
    //  for (int i = 1; i < 7; i = i + 2)
    //  {
    //      if (array[i] < array[i - 1] && array[i] < array[i + 1])
    //      {
    //          swap(array[i], array[i + 1]);
    //      }
    //  }

    // Method 2
    // sort array
    for (int m = 0; m < 8; m++)
    {
        int x = m;
        while (x > 0 && array[x] < array[x - 1])
        {
            swap(array[x], array[x - 1]);
            x--;
        }
    }

    // swap each pair
    for (int n = 0; n < 7; n=n+2)
    {
        swap(array[n], array[n + 1]);
    }

    cout << "\nArranged array in wave form!" << endl;
    for (int a = 0; a < 8; a++)
    {
        cout << array[a] << " ";
    }
    cout << endl;
}