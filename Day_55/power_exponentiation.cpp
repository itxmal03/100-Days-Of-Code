#include <iostream>
using namespace std;

// calculate power of a number

double method1(int x, int n)
{
    if (n == 0)
    {
        return 1;
    }

    if (x == 1)
    {
        return 1.0;
    }
    if (x == -1 && n % 2 == 0)
    {
        return 1;
    }

    if (x == -1 && n % 2 != 0)
    {
        return -1;
    }
    if (x == 0)
    {
        return 0;
    }
   

    double ans = 1;

    double base = x;

    long binaryForm = n;

    if (n < 0)
    {
        base = 1.0 / base;
        binaryForm = -binaryForm;
    }

    for (int i = 0; i < binaryForm; i++)
    {
        ans *= base;
    }
    return ans;
}

double method2(int x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    if (x == 1)
    {
        return 1.0;
    }
    if (x == -1 && n % 2 == 0)
    {
        return 1;
    }

    if (x == -1 && n % 2 != 0)
    {
        return -1;
    }
    if (x == 0)
    {
        return 0;
    }

    double ans = 1;
    long binaryForm = n;
    double base = x;

    if (n < 0)
    {
        base = 1.0 / base;
        binaryForm = -binaryForm;
    }

    while (binaryForm > 0)
    {
        if (binaryForm % 2 == 1)
        {
            ans *= base;
        }
        base *= base;
        binaryForm /= 2;
    }

    return ans;
}

int main()
{

    int number = 5;
    int power = 3;

    cout << method1(number, power) << endl;
    cout << method2(number, power) << endl;

    return 0;
}