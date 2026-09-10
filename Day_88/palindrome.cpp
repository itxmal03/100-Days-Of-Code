#include <iostream>
#include <cctype> // for isalnum, tolower
using namespace std;

// ============================================================
//  VERSION 1: CUSTOM isAlphanumeric (Manual ASCII checks)
//  ----------------------------------------------------------
//  Returns true if ch is a letter (A-Z, a-z) or a digit (0-9).
//  Systems note: Works on ASCII. No locale/unicode support.
// ============================================================

bool isAlphanumeric(char ch)
{
    if ((ch >= '0' && ch <= '9') ||
        (tolower(ch) >= 'a' && tolower(ch) <= 'z'))
    {
        return true;
    }
    return false;
}


// ============================================================
//  VERSION 2: BUILT-IN std::isalnum (from <cctype>)
//  ----------------------------------------------------------
//  Same logic, but battle-tested. Handles all locales and edge cases.
// ============================================================
bool isAlphanumericBuiltIn(char ch)
{
    return isalnum(static_cast<unsigned char>(ch)) != 0;
}

// ============================================================
//  PALINDROME CHECK using CUSTOM function
// ============================================================
bool isPalindromeCustom(string str)
{
    int start = 0, end = str.length() - 1;

    while (start < end)
    {
        if (!isAlphanumeric(str[start]))
        {
            start++;
            continue;
        }
        if (!isAlphanumeric(str[end]))
        {
            end--;
            continue;
        }
        if (tolower(str[start]) != tolower(str[end]))
        {
            return false;
        }
        start++;
        end--;
    }
    return true;
}


// ============================================================
//  PALINDROME CHECK using BUILT-IN function
// ============================================================
bool isPalindromeBuiltIn(string str)
{
    int start = 0, end = str.length() - 1;

    while (start < end)
    {
        if (!isAlphanumericBuiltIn(str[start]))
        {
            start++;
            continue;
        }
        if (!isAlphanumericBuiltIn(str[end]))
        {
            end--;
            continue;
        }
        if (tolower(str[start]) != tolower(str[end]))
        {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

// ============================================================
//  MAIN - Test both versions side by side
// ============================================================
int main()
{
    // Test the custom function on edge cases
    cout << "=== isAlphanumeric tests ===" << endl;
    cout << "isAlphanumeric('a') = " << isAlphanumeric('a') << endl; // 1
    cout << "isAlphanumeric('Z') = " << isAlphanumeric('Z') << endl; // 1
    cout << "isAlphanumeric('5') = " << isAlphanumeric('5') << endl; // 1
    cout << "isAlphanumeric(' ') = " << isAlphanumeric(' ') << endl; // 0
    cout << "isAlphanumeric(',') = " << isAlphanumeric(',') << endl; // 0
    cout << "isAlphanumeric(':') = " << isAlphanumeric(':') << endl; // 0

    cout << "\n=== Palindrome tests (CUSTOM) ===" << endl;
    cout << "\"A man, a plan, a canal: Panama\" -> "
         << isPalindromeCustom("A man, a plan, a canal: Panama") << endl; // 1
    cout << "\"race a car\" -> "
         << isPalindromeCustom("race a car") << endl; // 0
    cout << "\"madam\" -> "
         << isPalindromeCustom("madam") << endl; // 1
    cout << "\".,;:\" -> "
         << isPalindromeCustom(".,;:") << endl; // 1 (no alphanum -> valid)

    cout << "\n=== Palindrome tests (BUILT-IN) ===" << endl;
    cout << "\"A man, a plan, a canal: Panama\" -> "
         << isPalindromeBuiltIn("A man, a plan, a canal: Panama") << endl; // 1
    cout << "\"race a car\" -> "
         << isPalindromeBuiltIn("race a car") << endl; // 0
    cout << "\"madam\" -> "
         << isPalindromeBuiltIn("madam") << endl; // 1

    return 0;
}