#include <iostream>
using namespace std;

int main()
{

    // int x = 990;

    int *y = new int;

    *y = 990;

    cout << y << endl;
    cout << *y << endl;

    int x = 89;

    int *array = new int[x];
    

    return 0;
}