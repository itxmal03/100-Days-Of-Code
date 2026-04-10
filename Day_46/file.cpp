#include <iostream>
using namespace std;

class A
{
public:
    void show(int x)
    {
        cout << "hello " << x << endl;
    }
};

class B : public A
{
public:
    void show()
    {
        cout << "hello " << endl;
    }
};

int main()
{

    B obj;
    obj.show(5);
    return 0;
}