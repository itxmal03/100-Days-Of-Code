#include <iostream>
using namespace std;

int main()
{
    int dividend = 1;
    int divisor = 2;

    if (dividend < divisor)
    {
        cout << "for int division dividend must be greater or equal to divisor" << endl;
        return 1;
    }

    int reminder = dividend % divisor;
    int diff = dividend - reminder;

    int i = 1;

    int result = 0;

    while (true)
    {
        if (divisor * i == diff)
        {
            result = i;
            break;
        }
        i++;
    }

    cout << result << endl;

    return 0;
}