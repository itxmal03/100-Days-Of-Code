#include <iostream>
#include <string>
using namespace std;

// ============================================================
//  VERSION 1: YOUR ORIGINAL LOGIC (Fixed for edge cases)
//  ----------------------------------------------------------
//  Approach: Keep finding 'part' from the start and erasing it.
//  Note: find() called twice per iteration (minor inefficiency).
// ============================================================

string removeAllOccurrences_v1(string &str, string part)
{
    // FIX: Handle empty 'part' to prevent infinite loop.
    if (part.empty())
        return str;

    while (str.length() > 0 && str.find(part) < str.length())
    {
        str.erase(str.find(part), part.length());
    }
    return str;
}

// ============================================================
//  VERSION 2: OPTIMIZED LOGIC (Cache find result)
//  ----------------------------------------------------------
//  Approach: Call find() once per iteration, store in 'pos'.
//  Also uses 'const string&' for part to avoid copy.
// ============================================================
string removeAllOccurrences_v2(string &str, const string &part)
{
    if (part.empty())
        return str;

    size_t pos;
    while ((pos = str.find(part)) != string::npos)
    {
        str.erase(pos, part.length());
    }
    return str;
}

// ============================================================
//  MAIN - Test both versions
// ============================================================
int main()
{
    cout << "=== Test 1: 'daabcbaabcbc' remove 'abc' ===" << endl;
    string s1 = "daabcbaabcbc";
    string s1b = s1; // copy for second test
    cout << "V1: " << removeAllOccurrences_v1(s1, "abc") << endl;
    cout << "V2: " << removeAllOccurrences_v2(s1b, "abc") << endl;

    cout << "\n=== Test 2: 'aabababa' remove 'aba' ===" << endl;
    string s2 = "aabababa";
    string s2b = s2;
    cout << "V1: " << removeAllOccurrences_v1(s2, "aba") << endl;
    cout << "V2: " << removeAllOccurrences_v2(s2b, "aba") << endl;

    cout << "\n=== Test 3: 'hello' remove '' (empty part) ===" << endl;
    string s3 = "hello";
    string s3b = s3;
    cout << "V1: " << removeAllOccurrences_v1(s3, "") << " (safe)" << endl;
    cout << "V2: " << removeAllOccurrences_v2(s3b, "") << " (safe)" << endl;

    cout << "\n=== Test 4: 'abc' remove 'abc' (whole string) ===" << endl;
    string s4 = "abc";
    string s4b = s4;
    cout << "V1: \"" << removeAllOccurrences_v1(s4, "abc") << "\" (empty)" << endl;
    cout << "V2: \"" << removeAllOccurrences_v2(s4b, "abc") << "\" (empty)" << endl;

    cout << "\n=== Test 5: 'xyz' remove 'abc' (not found) ===" << endl;
    string s5 = "xyz";
    string s5b = s5;
    cout << "V1: " << removeAllOccurrences_v1(s5, "abc") << " (unchanged)" << endl;
    cout << "V2: " << removeAllOccurrences_v2(s5b, "abc") << " (unchanged)" << endl;

    return 0;
}