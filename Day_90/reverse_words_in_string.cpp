#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string reverseWords(string s)
{
    int n = s.length();
    reverse(s.begin(), s.end()); // Step 1: Reverse the entire string

    string ans = "";

    for (int i = 0; i < n; i++)
    {
        string word = "";

        // Extract a word (until space or end)
        while (i < n && s[i] != ' ')
        {
            word += s[i];
            i++;
        }

        // Step 2: Reverse each word back to original order
        reverse(word.begin(), word.end()); // FIX 1: use iterators

        // Step 3: Append word with a space separator
        if (word.length() > 0)
        {
            ans += " " + word;
        }
    }

    // FIX 2: Return 'ans' (not 's'), and trim the leading space
    return ans.substr(1);
}

int main()
{
    cout << reverseWords("the sky is blue") << endl;   // "blue is sky the"
    cout << reverseWords("  hello world  ") << endl;   // "world hello"
    cout << reverseWords("a good   example") << endl;  // "example good a"
    return 0;
}