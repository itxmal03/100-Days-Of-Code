#include <iostream>
using namespace std;

// arraypointer always point to the first element of array
int main()
{
    int arr[2] = {1, 2};
    cout << arr << endl;       // it will print its address
    cout << &(arr[0]) << endl; // it willwork same as above
    cout << *arr << endl;      // it will print the first value that is 1

    // in cpp the name of array is a constant pointer , it means it can't be changed or modified again in program
    int a = 10;
    // arr = &a; it is giving error that lvalue must be modifiable
    return 0;
}