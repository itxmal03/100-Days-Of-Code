#include <iostream>
using namespace std;

void bitwiseOperators(int a, int b);

int main()
{
    bitwiseOperators(5, 3);
    return 0;
}

void bitwiseOperators(int a, int b)
{
    // and & bitwise operator 
    cout << "& of " << a << " and " << b << " is: " << (a & b) << endl;

    // or | bitwise operator 
    cout << "| of " << a << " and " << b << " is: " << (a | b) << endl;

    // xor ^ bitwise operator
    cout << "^ of " << a << " and " << b << " is: " << (a ^ b) << endl;

    // left shift operator <<
    cout << "<< of " << a << " with " << b << " is: " << (a << b) << endl;
    // left shift operator works similar as     ans = a*2^b

    // right shift operator >>
    cout << ">> of " << a << " with " << b << " is: " << (a >> b) << endl;
    // right shift operator works similar as     ans = a/2^b
}