#include <iostream>
using namespace std;

int main()
{
    int array[14] = {1, 2, 4, 5, 6, 7, 19, 25, 30, 40, 41, 42, 43, 44};
    int counter;
    for (int i = 0; i < 14; i++)
    {
        int n = array[i];
        counter = 0;
        for (int j = 0; j < i; j++)
        {
            if (n - array[j] < 10)
            {
                counter++;
            }
        }
        if (counter < 3)
        {
            cout << "Request at " << n << "s is allowed!" << endl;
        }
        else
        {
            cout << "Request at " << n << "s is blocked!" << endl;
        }
    }

    return 0;
}