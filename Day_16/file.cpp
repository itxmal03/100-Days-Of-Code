#include <iostream>
using namespace std;

void celebirty(int array[][3], int size);
void findCelebirty(int n, int array[][3]);

/*
     0  1  2
  0  1  1  1
  1  1  1  1
  2  0  0  1
*/

int main()
{
    int array[3][3] = {{1, 1, 1},
                       {1, 1, 1},
                       {0, 0, 1}};
    int size = sizeof(array) / sizeof(array[0]);
    // celebirty(array, size);
    findCelebirty(size, array);
    return 0;
}

// Method 1
void celebirty(int array[][3], int size)
{
    bool celebirty;
    int candidate = -1;
    for (int i = 0; i < size; i++)
    {
        celebirty = true;
        for (int j = 0; j < size; j++)
        {
            if (array[i][j] == 1 && i != j)
            {
                celebirty = false;
                break;
            }
        }
        if (celebirty)
        {
            candidate = i;
        }
    }

    for (int x = 0; x < size; x++)
    {
        if (x != candidate && array[x][candidate] != 1)
        {
            celebirty = false;
        }
    }

    if (!celebirty)
    {
        cout << "No celebirty exists!" << endl;
    }
    else
    {

        cout << "Celeberty is: " << candidate << endl;
    }
}









// Method 2
void findCelebirty(int n, int array[][3])
{
    int candidate = 0;
    for (int i = 1; i < n; i++)
    {
        if (!(array[i][candidate] == 1))
        {
            candidate = i;
        }
    }

    for (int j = 0; j < n; j++)
    {
        if (j == candidate)
        {
            continue;
        }

        if (!(array[j][candidate] == 1) || (array[candidate][j] == 1))
        {
            candidate = -1;
            break;
        }
    }
    if (candidate == -1)
        cout << "No celebirty exists!" << endl;
    else
        cout << "Celebirty is: " << candidate << endl;
}
