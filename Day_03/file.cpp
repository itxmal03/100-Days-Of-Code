#include <iostream>
using namespace std;

int main()
{
    int array[10] = {1, 2, 4, 5, 6, 7, 19, 25, 30, 40};
    int counter;
    for (int i = 0; i < 10; i++)
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
        if (counter <= 3)
        {
            cout << "Requet at " << n << " is allowed!" << endl;
        }
        else
        {
            cout << "Requet at " << n << " is blocked!" << endl;
        }
    }

    return 0;
}