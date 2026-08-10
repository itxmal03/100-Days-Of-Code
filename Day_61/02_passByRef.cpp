#include <iostream>
using namespace std;

// Pass by ref  , 2 ways , 1.by pointer * , 2.by alias &
void changeA(int *a) // pass by pointer
{
    *a = 20;
}

void changeB(int &b) // pass by alias
{
    b = 100;
}

int main()
{
    int a = 10;
    int b = 50;
    changeA(&a);
    changeB(b);

    cout << "a in main " << a << endl;
    cout << "b in main " << b << endl;

    return 0;
}