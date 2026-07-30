#include <iostream>
using namespace std;

// calculate power of a number

double method1(int x, int n)
{
    double ans = 1;
    for (int i = 0; i < n; i++)
    {
        ans *= x;
    }
    return ans;
}

int main()
{

    int number = 5;
    int power = 3;

    cout << method1(number, power) << endl;
    return 0;
}