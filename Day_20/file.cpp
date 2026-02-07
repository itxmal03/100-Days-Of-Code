#include <iostream>
using namespace std;

void decimalToBinary(int n);
void binaryToDecimal(int n);
void decimalToOctal(int n);
void octalToDecimal(int n);

int main()
{
    // decimalToBinary(5);
    // binaryToDecimal(101);
    // decimalToOctal(10);
    octalToDecimal(12);
    return 0;
}

void decimalToBinary(int n)
{
    int originalNumber = n;
    int binary = 0;
    int power = 1;
    while (n > 0)
    {
        int rem = n % 2;
        n = n / 2;
        binary += (rem * power);
        power *= 10;
    }
    cout << "binary form of: " << originalNumber << " is " << binary << endl;
}

void binaryToDecimal(int n)
{
    int originalNum = n;
    int decimal = 0;
    int power = 1;
    while (n > 0)
    {
        int rem = n % 10;
        n /= 10;
        decimal += (rem * power);
        power *= 2;
    }
    cout << "Decimal form of: " << originalNum << " is " << decimal << endl;
}

void decimalToOctal(int n)
{

    int originalNumber = n;
    int octal = 0;
    int power = 1;
    while (n > 0)
    {
        int rem = n % 8;
        n = n / 8;
        octal += (rem * power);
        power *= 10;
    }
    cout << "Octal form of: " << originalNumber << " is " << octal << endl;
}

void octalToDecimal(int n)
{
    int originalNum = n;
    int decimal = 0;
    int power = 1;
    while (n > 0)
    {
        int rem = n % 10;
        n /= 10;
        decimal += (rem * power);
        power *= 8;
    }
    cout << "Decimal form of: " << originalNum << " is " << decimal << endl;
}