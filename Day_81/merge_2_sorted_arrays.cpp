#include <iostream>
#include <algorithm> // for sort, swap
using namespace std;

// APPROACH 1: IN-PLACE MERGE 

// Merges arr2 into arr1. Assumes arr1 has enough space (m+n).
// Time: O(m+n), Space: O(1)
// ============================================================
void mergeInPlace(int arr1[], int m, int arr2[], int n)
{
    int i = m - 1;       // Last valid element in arr1
    int j = n - 1;       // Last element in arr2
    int idx = m + n - 1; // Last position in arr1's total capacity

    while (i >= 0 && j >= 0)
    {
        if (arr1[i] >= arr2[j])
        {
            arr1[idx--] = arr1[i--];
        }
        else
        {
            arr1[idx--] = arr2[j--];
        }
    }

    // If arr2 still has leftovers, copy them (arr1 leftovers are already in place)
    while (j >= 0)
    {
        arr1[idx--] = arr2[j--];
    }
}


// APPROACH 2: TWO-POINTER WITH EXTRA ARRAY (Standard Merge)

// Merges arr1 and arr2 into a new array 'result'.
// Time: O(m+n), Space: O(m+n)
// ============================================================
void mergeWithExtraArray(int arr1[], int m, int arr2[], int n, int result[])
{
    int i = 0, j = 0, idx = 0;

    // Pick the smaller element from the front of both arrays
    while (i < m && j < n)
    {
        if (arr1[i] <= arr2[j])
        {
            result[idx++] = arr1[i++];
        }
        else
        {
            result[idx++] = arr2[j++];
        }
    }

    // Copy leftovers from arr1 (if any)
    while (i < m)
    {
        result[idx++] = arr1[i++];
    }

    // Copy leftovers from arr2 (if any)
    while (j < n)
    {
        result[idx++] = arr2[j++];
    }
}

// APPROACH 3: LAZY BRUTE FORCE (Concatenate + Sort)

// Copies everything into result and sorts it.
// Time: O((m+n) log(m+n)), Space: O(m+n)
// ============================================================
void mergeLazy(int arr1[], int m, int arr2[], int n, int result[])
{
    // Copy arr1
    for (int i = 0; i < m; i++)
        result[i] = arr1[i];

    // Copy arr2
    for (int i = 0; i < n; i++)
        result[m + i] = arr2[i];

    // Sort the entire thing
    sort(result, result + m + n);
}

// ============================================================
// HELPER: Print array
// ============================================================
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// ============================================================
// MAIN - Test all approaches
// ============================================================
int main()
{
    // ---- TEST DATA ----
    int arr1[6] = {1, 3, 5, 0, 0, 0}; // Space for 6 (3 valid + 3 extra)
    int arr2[3] = {2, 4, 6};
    int m = 3, n = 3;

    cout << "Original arr1: ";
    printArray(arr1, m);
    cout << "Original arr2: ";
    printArray(arr2, n);
    cout << endl;

    // ---- APPROACH 1: In-Place Merge ----
    // Make a copy because mergeInPlace destroys the original arr1 layout
    int arr1_copy[6] = {1, 3, 5, 0, 0, 0};
    mergeInPlace(arr1_copy, m, arr2, n);
    cout << "1. In-Place Merge (O(1) space): ";
    printArray(arr1_copy, m + n);

    // ---- APPROACH 2: Extra Array Merge ----
    int result1[6];
    mergeWithExtraArray(arr1, m, arr2, n, result1);
    cout << "2. Two-Pointer (O(n) space):     ";
    printArray(result1, m + n);

    // ---- APPROACH 3: Lazy Sort Merge ----
    int result2[6];
    mergeLazy(arr1, m, arr2, n, result2);
    cout << "3. Lazy Sort (O(n log n) time):   ";
    printArray(result2, m + n);

    return 0;
}