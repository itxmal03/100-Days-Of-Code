#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// ============================================================
//  STL ALGORITHMS QUICK REFERENCE (Date: 2026-09-08)
//  Header: <algorithm>
//  Focus: Sorting, Binary Search, Reversing, Min/Max.
//  Systems Note: std::sort is usually Introsort = QuickSort + HeapSort + InsertionSort.
// ============================================================

// ---- 1. CUSTOM COMPARATOR (for pairs, sort by second then first) ----
// Returns true if p1 should come BEFORE p2.
// This defines a "strict weak ordering".
bool customComparator(const pair<int, int> &p1, const pair<int, int> &p2)
{
    // Primary: Sort by second element (ascending)
    if (p1.second != p2.second)
    {
        return p1.second < p2.second; // True: p1 comes first if its second is smaller.
    }
    // Secondary: If seconds are equal, sort by first element (ascending)
    return p1.first < p2.first;
}

// Helper to print a vector of pairs
void printPairs(const vector<pair<int, int>> &v, const string &label)
{
    cout << label << ": ";
    for (const auto &p : v)
    {
        cout << "(" << p.first << "," << p.second << ") ";
    }
    cout << endl;
}

// Helper to print a vector of ints
void printInts(const vector<int> &v, const string &label)
{
    cout << label << ": ";
    for (int val : v)
        cout << val << " ";
    cout << endl;
}

int main()
{
    cout << "========== PART 1: BASIC SORTING ==========" << endl;

    // ---- 1.1 Sorting a raw array ----
    const int n = 5; // ✅ Use const for standard C++ (no VLA).
    int arr[n] = {3, 4, 2, 1, 0};

    // sort(start_pointer, end_pointer) -> end is exclusive (one past the last).
    sort(arr, arr + n);
    cout << "Sorted array: ";
    for (int val : arr)
        cout << val << " ";
    cout << endl;

    // ---- 1.2 Sorting a vector (using iterators) ----
    vector<int> vec = {3, 4, 2, 1, 0};
    sort(vec.begin(), vec.end()); // Full range.
    printInts(vec, "Sorted vector (ascending)");

    cout << "\n========== PART 2: DESCENDING ORDER ==========" << endl;

    // ---- 2.1 Using greater<int>() (functor) ----
    vector<int> descVec = {3, 4, 2, 1, 0};
    sort(descVec.begin(), descVec.end(), greater<int>());
    printInts(descVec, "Sorted vector (descending)");

    // ---- 2.2 Alternative: Lambda (anonymous function) ----
    vector<int> lambdaVec = {3, 4, 2, 1, 0};
    sort(lambdaVec.begin(), lambdaVec.end(), [](int a, int b)
         {
             return a > b; // returns true if a > b (larger comes first).
         });
    printInts(lambdaVec, "Sorted using lambda (desc)");

    cout << "\n========== PART 3: SORTING PAIRS ==========" << endl;

    // ---- 3.1 Default sort (sorts by first element, then second) ----
    vector<pair<int, int>> v = {{9, 2}, {4, 7}, {7, 1}};
    sort(v.begin(), v.end()); // ✅ Compares p.first first, then p.second.
    printPairs(v, "Default sort (by first then second)");

    // ---- 3.2 Custom sort (by second element, then first) ----
    // FIXED: v.size() is 3, NOT n=5.
    sort(v.begin(), v.end(), customComparator);
    printPairs(v, "Custom sort (by second then first)");

    // ---- 3.3 Lambda comparator (inline) ----
    vector<pair<int, int>> v2 = {{9, 2}, {4, 7}, {7, 1}};
    sort(v2.begin(), v2.end(), [](const pair<int, int> &a, const pair<int, int> &b)
         {
             return a.second < b.second; // Sort by second only.
         });
    printPairs(v2, "Lambda: sort by second only");

    cout << "\n========== PART 4: OTHER USEFUL ALGORITHMS ==========" << endl;

    // ---- 4.1 is_sorted (check if sorted) ----
    vector<int> sortedVec = {1, 2, 3, 4, 5};
    cout << "is_sorted(sortedVec): " << (is_sorted(sortedVec.begin(), sortedVec.end()) ? "true" : "false") << endl;

    // ---- 4.2 reverse (reverse the order) ----
    vector<int> revVec = {1, 2, 3, 4, 5};
    reverse(revVec.begin(), revVec.end());
    printInts(revVec, "After reverse");

    // ---- 4.3 min_element / max_element (returns iterators) ----
    vector<int> minMaxVec = {5, 2, 9, 1, 7};
    auto minIt = min_element(minMaxVec.begin(), minMaxVec.end());
    auto maxIt = max_element(minMaxVec.begin(), minMaxVec.end());
    cout << "Min element: " << *minIt << ", Max element: " << *maxIt << endl;

    // ---- 4.4 binary_search (requires sorted range) ----
    vector<int> searchVec = {1, 2, 3, 4, 5};
    bool found = binary_search(searchVec.begin(), searchVec.end(), 3);
    cout << "binary_search(3): " << (found ? "Found" : "Not found") << endl;

    cout << "\n========== PART 5: ADVANCED SORTING VARIANTS ==========" << endl;

    // ---- 5.1 stable_sort (preserves relative order of equal elements) ----
    // Useful when sorting by one criteria, but you want to keep the previous order for ties.
    vector<pair<int, int>> stableTest = {{1, 2}, {2, 1}, {1, 1}};
    stable_sort(stableTest.begin(), stableTest.end(), [](const auto &a, const auto &b)
                {
                    return a.first < b.first; // Sort by first only.
                });
    printPairs(stableTest, "stable_sort (preserves order for equal first)");

    // ---- 5.2 partial_sort (sort only the first k elements) ----
    vector<int> partialVec = {9, 1, 8, 2, 7, 3};
    partial_sort(partialVec.begin(), partialVec.begin() + 3, partialVec.end());
    printInts(partialVec, "partial_sort (first 3 are sorted)");

    // --- next permutation
    string x = "abc";
    next_permutation(x.begin(), x.end());
    cout << x << endl;
    prev_permutation(x.begin(), x.end());
    cout << x << endl;

    // builtin set bits count find // these functions come with gcc compiler and are not compatible with other compilers , not widely used
    int n1 = 15;
    long int n2 = 15;
    long long int n3 = 15;
    cout << __builtin_popcount(n1) << endl;    /// it will print the count of set bits (1) of the number in binary
    cout << __builtin_popcountl(n2) << endl;  // add l if type is long
    cout << __builtin_popcountll(n3) << endl; // add ll if type is long long

    cout << "\n========== PART 6: SYSTEMS-LEVEL INSIGHTS ==========" << endl;
    cout << "1. std::sort is INTROSORT: A hybrid of QuickSort, HeapSort, and InsertionSort." << endl;
    cout << "   - Uses QuickSort for the main recursion." << endl;
    cout << "   - Falls back to HeapSort if recursion depth exceeds log(n) (prevents O(n²) worst case)." << endl;
    cout << "   - Uses InsertionSort for small subarrays (optimized for cache)." << endl;
    cout << "2. Complexity: O(n log n) on average AND worst case." << endl;
    cout << "3. Comparator Requirement: Must define 'strict weak ordering'." << endl;
    cout << "   - If a < b is true, then b < a must be false." << endl;
    cout << "   - If a < b and b < c, then a < c must be true." << endl;
    cout << "4. stable_sort: Uses MergeSort (O(n log n) time, O(n) extra space)." << endl;
    cout << "   Use this when you need to preserve the relative order of equal elements." << endl;
    cout << "5. Pass by const reference in comparators: ALWAYS do this for heavy types." << endl;
    cout << "   (You did it right in the new version! Very efficient.)" << endl;

    return 0;
}