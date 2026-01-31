#include <iostream>
using namespace std;

void celebirty(int array[][3], int size);

/*
     0  1  2 
  0  1  0  1
  1  1  1  1
  2  0  0  1
*/

int main() 
{
    int array[3][3] = {{1, 0, 1}, {1, 1, 1}, {0, 0, 1}};
    int size = sizeof(array) / sizeof(array[0]);
    celebirty(array, size);
    return 0;
}

void celebirty(int array[][3], int size)
{
    int celebirty = -1;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (array[i][j] != 0)
            {

                celebirty = i;
                cout << "value of CELEB " << celebirty << endl;
            }
            else
            {

                break;
            }
        }
    }
    if (celebirty != -1)
    {
        cout << "Celeberty is: " << celebirty << endl;
    }
    else
    {
        cout << "No celebirty exists!" << endl;
    }
}












