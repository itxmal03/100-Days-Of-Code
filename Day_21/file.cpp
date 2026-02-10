#include <iostream>
using namespace std;

void binaryAddtion(int n);
int decToBinary(int n);
void twosComplement(int n);

int main()
{
    // binaryAddtion(7);
    twosComplement(7);
    return 0;
}

void twosComplement(int n)
{
    string s1 = to_string(n);
    if (s1[0] == '-')
    {
        s1[0] = '0';
        int changed = stoi(s1);
        int binary = decToBinary(changed);
        cout << "binary of: " << n << " is: " << binary << endl;
        string s2 = to_string(binary);
    }
    else
    {
        int binary = decToBinary(n);
        cout << "binary of: " << n << " is: " << binary << endl;
        string s2 = to_string(binary);
    }

    int binary = decToBinary(n);
    string s2 = to_string(binary);
    // flip numbers , 1's complement
    for (int i = s2.length() - 1; i >= 0; i--)
    {
        if (s2[i] == '0')
        {
            s2[i] = '1';
        }
        else
        {
            s2[i] = '0';
            if (i == 0)
            {
                s2 = '1' + s2;
                break;
            }
        }
    }

    // add 1 , 2's complement
    int x = stoi(s2);
    cout << " flipped number is : " << s2 << endl;
    binaryAddtion(x);
}

int decToBinary(int n)
{
    int orginalNum = n;
    int binary = 0;
    int power = 1;
    while (n > 0)
    {
        int rem = n % 2;
        n = n / 2;
        binary += (rem * power);
        power *= 10;
    }
    return binary;
}

// add one to binary number
void binaryAddtion(int n)
{
    string s = to_string(n);
    if (s[(s.length() - 1)] == '0')
    {
        s[(s.length() - 1)] = '1';
    }
    else
    {
        // for odd numbers
        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (s[i] == '0')
            {
                s[i] = '1';
                break;
            }
            else
            {
                s[i] = '0';
                if (i == 0)
                {
                    s = '1' + s;
                    break;
                }
            }
        }
    }

    cout << "after adding 1 into: " << n << " result is: " << s << endl;
}