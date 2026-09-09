#include <iostream>
#include <cstring>   // for strlen, strcmp, strcpy (C-style string functions)
#include <algorithm> // for std::reverse, std::swap
#include <array>     // for std::array (modern C++ alternative)
using namespace std;

// ============================================================
//  C-STRINGS & std::string QUICK REFERENCE (Date: 2026-09-09)
//  ------------------------------------------------------------------
//  1. C-String (char array) : Raw array of chars, terminated by '\0'.
//     - Lives on stack/heap, manual memory management.
//     - sizeof() gives total bytes. strlen() counts chars until '\0'.
//  2. std::string           : C++ class, dynamically manages heap memory.
//     - Mutable, resizable, supports concatenation, comparators.
// ============================================================

// ---- Helper: Palindrome Check (Using std::string) ----
bool isPalindrome(string s)
{
    string temp = s;             // Copy the original
    reverse(s.begin(), s.end()); // Reverse the copy
    return temp == s;            // Compare original vs reversed
}

// ---- Helper: Print C-String safely ----
void printCString(const char *label, const char *arr, int size)
{
    cout << label << ": ";
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == '\0')
            cout << "\\0 (null) ";
        else
            cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    cout << "========== PART 1: C-STRINGS (CHAR ARRAYS) & NULL TERMINATOR ==========" << endl;

    // ---- 1.1 MISSING NULL TERMINATOR (UNDEFINED BEHAVIOR) ----
    char invalid[] = {'a', 'b', 'c'};                                        // ❌ NO '\0' at the end!
    cout << "invalid[] = {'a','b','c'} -> cout prints: " << invalid << endl; // Prints "abc" + garbage until a random \0 is found.
    cout << "strlen(invalid) = " << strlen(invalid) << " (GARBAGE - undefined behavior)" << endl;

    // ---- 1.2 CORRECT NULL TERMINATOR ----
    char valid1[] = {'a', 'b', 'c', '\0'}; // ✅ Explicit null terminator.
    cout << "valid1 (with \\0): " << valid1 << endl;
    cout << "strlen(valid1) = " << strlen(valid1) << endl; // 3

    // ---- 1.3 STRING LITERAL (Implicit null terminator) ----
    char valid2[] = "hello"; // Compiler adds '\0' automatically.
    cout << "valid2 (literal): " << valid2 << endl;
    cout << "strlen(valid2) = " << strlen(valid2) << endl; // 5

    // ---- 1.4 sizeof vs strlen (The Critical Difference) ----
    char arr[] = {'a', 'b', 'x', 'y', '\0'}; // ✅ Properly terminated.
    int totalBytes = sizeof(arr);            // 5 bytes (4 chars + 1 null).
    int charCount = strlen(arr);             // 4 chars (ignores null).
    cout << "arr size = " << totalBytes << " bytes, strlen = " << charCount << " chars" << endl;

    cout << "\n========== PART 2: GETLINE & INPUT ==========" << endl;
    char buffer[10];
    cout << "Enter a string (max 9 chars, or press $ to stop): ";
    // cin.getline(buffer, 10, '$'); // Uncomment to test. Stops at '$' or after 9 chars.
    // cout << "You entered: " << buffer << endl;

    cout << "\n========== PART 3: MANUAL LENGTH & REVERSAL (WITHOUT NULL) ==========" << endl;

    // ---- 3.1 REVERSAL USING KNOWN SIZE (Works even without null) ----
    char strNoNull[] = {'a', 'b', 'x', 'y'};          // No null terminator.
    int n = sizeof(strNoNull) / sizeof(strNoNull[0]); // n = 4.

    cout << "Original strNoNull: ";
    for (int i = 0; i < n; i++)
        cout << strNoNull[i];
    cout << endl;

    // Reverse using two pointers (manual swap)
    int start = 0, end = n - 1;
    while (start < end)
    {
        swap(strNoNull[start++], strNoNull[end--]);
    }

    cout << "Reversed strNoNull (by size): ";
    for (int i = 0; i < n; i++)
        cout << strNoNull[i];
    cout << endl;

    // ---- 3.2 LENGTH CALCULATION VIA LOOP (Requires '\0') ----
    char strWithNull[] = {'a', 'b', 'x', 'y', '\0'};
    int len = 0;
    while (strWithNull[len] != '\0')
        len++;
    cout << "Length of strWithNull (manual loop): " << len << endl;

    cout << "\n========== PART 4: std::string (C++ CLASS) ==========" << endl;

    // ---- 4.1 INITIALIZATION ----
    string s1 = "Hello";       // Assignment.
    string s2("World");        // Constructor.
    string s3 = s1 + " " + s2; // Concatenation.
    cout << "s3 = " << s3 << endl;

    // ---- 4.2 MUTABILITY (string is mutable, char array is not) ----
    // char c[] = "hello";
    // c = "new"; // ❌ ERROR! Array is a const pointer.
    // string s = "hello";
    // s = "new"; // ✅ WORKS! Reassigns the heap memory.

    // ---- 4.3 RELATIONAL OPERATORS ----
    cout << "(s1 == s2) = " << (s1 == s2 ? "true" : "false") << endl; // false
    cout << "(s1 < s2) = " << (s1 < s2 ? "true" : "false") << endl;   // true ('H' < 'W')

    // ---- 4.4 REVERSING STRING (Using std::reverse) ----
    string revStr = "hello";
    reverse(revStr.begin(), revStr.end());
    cout << "Reversed 'hello' = " << revStr << endl;

    cout << "\n========== PART 5: PALINDROME CHECK ==========" << endl;
    string test1 = "madam";
    string test2 = "hello";
    cout << "isPalindrome(\"madam\") = " << (isPalindrome(test1) ? "true" : "false") << endl;
    cout << "isPalindrome(\"hello\") = " << (isPalindrome(test2) ? "true" : "false") << endl;

    cout << "\n========== PART 6: MODERN C++ std::array (ALTERNATIVE) ==========" << endl;
    array<char, 5> arr3 = {'a', 'b', 'c', 'd', '\0'};            // Compile-time fixed size.
    cout << "std::array<char,5> size = " << arr3.size() << endl; // Returns 5.
    cout << "arr3 data: " << arr3.data() << endl;                // .data() gives the underlying char*.

    cout << "\n========== PART 7: SYSTEMS-LEVEL INSIGHTS ==========" << endl;
    cout << "1. Null Terminator ('\\0'): Marks the end of a C-string." << endl;
    cout << "   Without it, functions like cout, strlen, strcpy read past the array -> CRASH!" << endl;
    cout << "2. sizeof vs strlen:" << endl;
    cout << "   - sizeof: Compile-time. Total bytes of the array (includes null)." << endl;
    cout << "   - strlen: Run-time. Iterates until it finds '\\0' (excludes null)." << endl;
    cout << "3. Memory: C-strings are raw bytes on the stack/heap." << endl;
    cout << "   std::string manages a dynamic heap buffer, so it resizes automatically." << endl;
    cout << "4. Mutability: C-array names are const pointers (cannot reassign)." << endl;
    cout << "   std::string assigns by copying internal heap pointer (fast)." << endl;

    return 0;
}