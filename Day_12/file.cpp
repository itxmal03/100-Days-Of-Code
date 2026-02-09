#include <iostream>
using namespace std;

// xor operator - find unique element in aray if all element repeate 2 times but 1 is unique
void unique(int array[9]);
// unique 3 concective characters
void unique3Char(string str);

int main()
{
    int array[9] = {1, 2, 1, 2, 4};
    // unique(array);
    string str = "AftabAli";
    unique3Char(str);

    return 0;
}

void unique(int array[9])
{
    int y = 0;
    for (int x = 0; x < 9; x++)
    {
        y = y ^ array[x];
    }
    cout << y << endl;
}

void unique3Char(string str)
{
    for (int i = 0; i < 6; i++)
    {
        int x = 1;
        while (str[i] != str[x])
        {
          
        }
    }
}