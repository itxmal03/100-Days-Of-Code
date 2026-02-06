#include <iostream>
using namespace std;

void checkPrime(int n);

int main()
{
    checkPrime(5);
    return 0;
}

void checkPrime(int n)
{
    bool isPrime = true;
    for (int i = 2; i * i <= n; i++)
    {
        if (i % 2 == 0)
        {
            isPrime = false;
            break;
        }
    }

    if (isPrime)
        cout << "yes prime!" << endl;
    else
        cout << "not prime!" << endl;
}