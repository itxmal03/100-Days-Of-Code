#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    int *ptr = &a;
    int **parPtr = &ptr;

    // cout << "value of original variable a :: " << a << endl;
    // cout << "&a :: " << &a << endl;
    // cout << "value of ptr :: " << ptr << endl;
    // // dereferencing
    // cout << "value of *ptr :: " << *ptr << endl;
    // cout << "address of ptr :: " << &ptr << endl;

    // cout << "value of patPtr :: " << parPtr << endl;
    // cout << "value of *parPtr  :: " << *parPtr << endl;
    // cout << "value of **parPtr " << **parPtr << endl;
    // cout << "address of parPtr :: " << &parPtr << endl;

    /// null pointers

    int *nullPtr = NULL;
    cout << nullPtr << endl; // prints 0

    float *nullPtr2 = NULL;
    cout << nullPtr2 << endl; // prints 0

    string *nullPtr3 = NULL;
    cout << nullPtr3 << endl; // prints 0

    // cout << *nullPtr << endl;  this is going to give segmentation fault error because it can't be deref.. as it is not pointing to any memory location

    return 0;
}