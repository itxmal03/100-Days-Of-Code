#include <iostream>
using namespace std;

int main()
{
    int z = 50;

    cout << z << endl;
    cout << &z << endl;

    int *ptr = &z;
    cout << ptr << endl;

    *ptr = 100;

    cout << z << endl;

    int &y = z;
    cout << z << endl;
    cout << y << endl;

    y = 99;

    cout << z << endl;
    cout << y << endl;

    return 0;
}