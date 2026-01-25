#include <iostream>
using namespace std;

void unique3Char(string str);

int main()
{
    string str = "AatabAli";
    // unique3Char(str);
    return 0;
}

// first 3 unique characters in string
void unique3Char(string str)
{
    string uniqueChars = "";
    for (int i = 0; i < str.length(); i++)
    {
        bool isUnique = true;
        for (int j = 0; j < uniqueChars.length(); j++)
        {
            if (str[i] == uniqueChars[j])
            {
                isUnique = false;
            }
        }
        if (isUnique)
        {
            uniqueChars += str[i];
        }
        if (uniqueChars.length() == 3)
        {
            break;
        }
    }
    cout << "unique 3 character: " << uniqueChars << endl;
}
