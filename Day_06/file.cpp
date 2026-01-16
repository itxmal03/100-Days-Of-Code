#include <iostream>
using namespace std;

// move zeros to end
int main()
{
    int array[7] = {1, 0, 2, 0, 4, 0, 9};

    // for (int i = 0; i < 7; i++)
    // {
    //     int x = i;
    //     while (x < 6)
    //     {
    //         if (array[x] == 0)
    //         {
    //             swap(array[x], array[x + 1]);
    //         }
    //         x++;
    //     }
    // }

    // Method 2

    int n = 0;
    for (int c = 0; c < 7; c++)
    {
        if (array[c] != 0)
        {
            swap(array[c], array[n]);
            n++;
        }
    }
    

    for (int z = 0; z < 7; z++)
    {
        cout << array[z] << " ";
    }

    return 0;
}