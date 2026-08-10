#include <iostream>
using namespace std;

int main()
{
    int a = 5;
    int *ptr = &a;
    // increment on pointer
    //  cout << ptr << endl;
    ptr++;

    /*it will print the value stored in it , that value is the address
    of another var and the increment in this address will be by 1 integer if
    it is integer type , mean 4 bytes will be added so it will be incremented by 4 */

    // cout << ptr << endl;

    ptr--; // same is the case with decrement
           // cout << ptr << endl;

    // cout << ptr + 2 << endl; // same it will add the number of Bytes of integers here , 2x4B
    //  cout << ptr - 2 << endl; // same here

    // as array is also a pointer so we can use pointer arithmetics here to access the elements of arr
    int arr[3] = {4, 5, 6}; // because the addition will add 4B in addr so it will point to next int in array as they are contiguous
    // cout << arr << endl;        // will give address of array
    // cout << *arr << endl;       // will give 1st element of array
    // cout << *(arr + 1) << endl; // will give 2nd element of array
    // cout << *(arr + 2) << endl; // will give 3rd element of array

    // pointers can not be added but we can subtract them to find the number of memory block in them
    // for example pointerA points to 100 and pointerB points to 108 so  pointerB-pointerA = 8B =2 integers
    int a1 = 50;
    int b2 = 100;
    int *pointerA = &a1;
    int *pointerB = &b2;
    // cout << pointerB - pointerA << endl;
    // cout << pointerA - pointerB << endl;

    // relational operators can be used with pointers also
    // cout << (pointerB == pointerA) << endl; // print 0 if false and 1 if true
    // cout << (pointerB != pointerA) << endl;
    pointerA = pointerB;
    // cout << (pointerB == pointerA) << endl; // prints 1 becuase true
    // cout << (pointerB >= pointerA) << endl; // print 0 if false and 1 if true

    // not allowed operations due to language scope and memory handling issues
    //  cout << (pointerB / pointerA) << endl;
    //  cout << (pointerB * pointerA) << endl;
    //  cout << (pointerB % pointerA) << endl;

    string s = "Hello";
    int *bad_ptr = (int *)&s; // Compiles, but extremely dangerous!

    cout << *bad_ptr << endl; // Prints the first 4 bytes of the string object as an integer (garbage).

    return 0;
}