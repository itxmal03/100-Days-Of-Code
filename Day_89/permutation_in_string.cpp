#include <iostream>
#include <string>
using namespace std;

// ============================================================
//  HELPER: Compare two frequency arrays of size 26
//  ----------------------------------------------------------
//  Returns true if both arrays are identical (same char counts).
// ============================================================
bool isFreqSame(int freq1[], int freq2[])
{
    for (int i = 0; i < 26; i++)
    {
        if (freq1[i] != freq2[i])
            return false;
    }
    return true;
}

// ============================================================
//  APPROACH 1: BRUTE FORCE (Your fixed logic)
//  ----------------------------------------------------------
//  Time:  O(n * m)  where n = s2.length(), m = s1.length()
//  Space: O(1)      (two fixed arrays of 26 ints)
//  Idea:  For each starting index in s2, build the frequency
//         array of the window of size m, and compare it with
//         the frequency array of s1.
// ============================================================
bool checkInclusionBrute(string s1, string s2)
{
    // Edge case: if s1 is longer than s2, no permutation can fit.
    if (s1.length() > s2.length())
        return false;

    // Step 1: Build frequency array for s1.
    int freq[26] = {0};
    for (int i = 0; i < s1.length(); i++)
    {
        // s1[i] - 'a' maps 'a'->0, 'b'->1, ..., 'z'->25.
        freq[s1[i] - 'a']++;
    }

    int windowSize = s1.length();

    // Step 2: Slide a window of size m across s2.
    //         The last valid window starts at s2.length() - windowSize.
    for (int i = 0; i <= (int)s2.length() - windowSize; i++)
    {
        int windFreq[26] = {0}; // Fresh frequency array for this window.

        // Build frequency array for s2[i ... i+windowSize-1]
        for (int j = i; j < i + windowSize; j++)
        {
            windFreq[s2[j] - 'a']++;
        }

        // Compare this window's frequencies with s1's frequencies.
        if (isFreqSame(freq, windFreq))
            return true;
    }

    return false;
}

// ============================================================
//  APPROACH 2: SLIDING WINDOW (Optimized)
//  ----------------------------------------------------------
//  Time:  O(n)  where n = s2.length()
//  Space: O(1)
//  Idea:  Instead of rebuilding the window each time, slide it:
//         add the new character coming in, remove the old
//         character going out. Then compare frequencies.
// ============================================================
bool checkInclusionSliding(string s1, string s2)
{
    if (s1.length() > s2.length())
        return false;

    int freq1[26] = {0}; // Frequency of s1.
    int freq2[26] = {0}; // Frequency of the current window in s2.

    // Build freq1 and the initial window's freq2.
    for (int i = 0; i < (int)s1.length(); i++)
    {
        freq1[s1[i] - 'a']++;
        freq2[s2[i] - 'a']++;
    }

    // Compare the first window.
    if (isFreqSame(freq1, freq2))
        return true;

    int windowSize = s1.length();

    // Slide the window one step at a time.
    for (int i = windowSize; i < (int)s2.length(); i++)
    {
        // Add the new character entering the window (at index i).
        freq2[s2[i] - 'a']++;

        // Remove the character that just left the window.
        // It was at index (i - windowSize).
        freq2[s2[i - windowSize] - 'a']--;

        // Check if the updated window matches s1's frequencies.
        if (isFreqSame(freq1, freq2))
            return true;
    }

    return false;
}

// ============================================================
//  MAIN: Test both approaches on the same inputs
// ============================================================
int main()
{
    // Test cases from LeetCode 567:
    // 1) "ab" in "eidbaooo" -> true  (window "ba")
    // 2) "ab" in "eidboaoo" -> false
    // 3) "adc" in "dcda"    -> true  (window "dcd"? Actually "adc" perm "dca"/"cad"/"adc" -> "dcda" has "dcd" no, "cda" yes? Let's check: "dcda" windows: "dcd", "cda". "cda" is a permutation of "adc"? "adc" sorted = "acd", "cda" sorted = "acd" -> yes true.)
    // 4) "a" in "ab"       -> true
    // 5) "abc" in "ab"     -> false (s1 longer than s2)

    cout << "=== Approach 1: Brute Force ===" << endl;
    cout << "checkInclusionBrute(\"ab\", \"eidbaooo\") = "
         << checkInclusionBrute("ab", "eidbaooo") << endl; // 1

    cout << "checkInclusionBrute(\"ab\", \"eidboaoo\") = "
         << checkInclusionBrute("ab", "eidboaoo") << endl; // 0

    cout << "checkInclusionBrute(\"adc\", \"dcda\") = "
         << checkInclusionBrute("adc", "dcda") << endl; // 1

    cout << "checkInclusionBrute(\"abc\", \"ab\") = "
         << checkInclusionBrute("abc", "ab") << endl; // 0

    cout << "\n=== Approach 2: Sliding Window ===" << endl;
    cout << "checkInclusionSliding(\"ab\", \"eidbaooo\") = "
         << checkInclusionSliding("ab", "eidbaooo") << endl; // 1

    cout << "checkInclusionSliding(\"ab\", \"eidboaoo\") = "
         << checkInclusionSliding("ab", "eidboaoo") << endl; // 0

    cout << "checkInclusionSliding(\"adc\", \"dcda\") = "
         << checkInclusionSliding("adc", "dcda") << endl; // 1

    cout << "checkInclusionSliding(\"abc\", \"ab\") = "
         << checkInclusionSliding("abc", "ab") << endl; // 0

    return 0;
}