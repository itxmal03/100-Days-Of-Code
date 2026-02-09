#include <iostream>
using namespace std;

void twosComplement(int n);

int main()
{
    twosComplement(-101);
    return 0;
}

void twosComplement(int n)
{
    string s = to_string(n);
    // one's complement
    if (s[0] == '-')
    {
        s[0] = '0';
    }
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '0')
        {
            s[i] = '1';
        }
        else
        {
            s[i] = '0';
        }
    }
    cout << s << endl;
    cout << "oringinal number: " << n << " fliped number: " << s << endl;

    // two's complement
    
    
}