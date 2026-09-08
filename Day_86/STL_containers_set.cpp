#include <iostream>
#include <set>
#include <unordered_set>
#include <string>
using namespace std;

// ============================================================
//  SET CONTAINERS QUICK REFERENCE (Date: 2026-09-08)
//  ------------------------------------------------------------------
//  1. std::set           : Ordered, Unique Keys, O(log n) (Red-Black Tree).
//  2. std::multiset      : Ordered, Duplicate Keys Allowed, O(log n).
//  3. std::unordered_set : Unordered, Unique Keys, O(1) avg (Hash Table).
//  4. std::unordered_multiset: Unordered, Duplicate Keys, O(1) avg.
//  Header: <set> (for set/multiset) and <unordered_set> (for unordered versions)
//  Systems Note: Sets are like maps but with ONLY keys (no values).
// ============================================================

// Helper: Print a set (ordered, unique)
void printSet(const set<int> &s, const string &label)
{
    cout << label << " (sorted, unique): ";
    for (int val : s)
        cout << val << " ";
    cout << " | Size: " << s.size() << endl;
}

// Helper: Print a multiset (ordered, duplicates)
void printMultiset(const multiset<int> &s, const string &label)
{
    cout << label << " (sorted, duplicates): ";
    for (int val : s)
        cout << val << " ";
    cout << " | Size: " << s.size() << endl;
}

// Helper: Print an unordered_set (unsorted, unique)
void printUnorderedSet(const unordered_set<int> &s, const string &label)
{
    cout << label << " (unsorted, unique): ";
    for (int val : s)
        cout << val << " ";
    cout << " | Size: " << s.size() << endl;
}

int main()
{
    cout << "========== PART 1: std::set (Ordered, Unique Keys) ==========" << endl;

    // ---- 1. INITIALIZATION ----
    set<int> s1;                   // Empty
    set<int> s2 = {5, 1, 4, 2, 3}; // Sorted automatically: 1,2,3,4,5
    printSet(s2, "s2 (initializer list)");

    // ---- 2. MODIFIERS (insert / emplace) ----
    set<int> s;
    s.insert(10);
    s.insert(20);
    s.insert(10);  // Duplicate ignored (size remains 2)
    s.emplace(30); // Constructs in-place
    printSet(s, "s after inserts");

    // ---- 3. LOOKUP (find / count) ----
    // find: returns iterator or end()
    auto it = s.find(20);
    if (it != s.end())
        cout << "Found 20" << endl;

    // count: returns 1 (exists) or 0 (doesn't) for unique-key sets.
    cout << "s.count(10) = " << s.count(10) << endl; // 1
    cout << "s.count(99) = " << s.count(99) << endl; // 0

    // ---- 4. LOWER_BOUND / UPPER_BOUND / EQUAL_RANGE ----
    // lower_bound(key): first element NOT LESS than key (i.e., >= key)
    // upper_bound(key): first element GREATER than key (i.e., > key)
    set<int> data = {1, 3, 5, 7, 9};

    // Find elements >= 4 and < 7
    auto low = data.lower_bound(4);  // points to 5
    auto high = data.upper_bound(7); // points to 9 (first > 7)

    cout << "lower_bound(4): " << (low != data.end() ? to_string(*low) : "end") << endl;
    cout << "upper_bound(7): " << (high != data.end() ? to_string(*high) : "end") << endl;

    // equal_range: returns a pair of iterators (lower_bound, upper_bound).
    auto range = data.equal_range(5); // range.first -> 5, range.second -> 7
    cout << "equal_range(5): [" << *range.first << ", " << *range.second << ")" << endl;

    // ---- 5. ERASE ----
    s.erase(20); // Erases by value (returns 1 if found).
    auto itErase = s.find(30);
    if (itErase != s.end())
        s.erase(itErase); // Erases by iterator.
    printSet(s, "s after erasing 20 & 30");

    // ---- 6. CRITICAL SAFETY CHECK (The bug in your code) ----
    set<int> test = {1, 2, 3};
    auto lb = test.lower_bound(5); // returns end()
    if (lb != test.end())
    {
        cout << "lower_bound(5): " << *lb << endl; // SAFE
    }
    else
    {
        cout << "lower_bound(5): end (no element >= 5)" << endl;
    }

    cout << "\n========== PART 2: std::multiset (Ordered, Duplicate Keys) ==========" << endl;

    multiset<int> ms;
    ms.insert(10);
    ms.insert(10);
    ms.insert(20);
    ms.insert(10);
    printMultiset(ms, "ms after inserts");

    // count() returns the number of duplicates.
    cout << "ms.count(10) = " << ms.count(10) << endl; // 3

    // erase(value) removes ALL occurrences.
    ms.erase(10); // Removes all three 10s.
    printMultiset(ms, "ms after erase(10)");

    // erase(iterator) removes only ONE occurrence.
    ms.insert(5);
    ms.insert(5);
    auto itMS = ms.find(5);
    if (itMS != ms.end())
        ms.erase(itMS); // Removes only one 5.
    printMultiset(ms, "ms after erase(iterator)");

    cout << "\n========== PART 3: std::unordered_set (Unordered, Unique Keys) ==========" << endl;

    unordered_set<int> us;
    us.insert(10);
    us.insert(5);
    us.insert(1);
    us.insert(10);                             // Duplicate ignored.
    printUnorderedSet(us, "us after inserts"); // Order is arbitrary (hash-based).

    // ---- LOOKUP (O(1) average) ----
    cout << "us.find(5) -> " << (us.find(5) != us.end() ? "Found" : "Not found") << endl;
    cout << "us.count(99) = " << us.count(99) << endl;

    // ---- BUCKET INTERFACE (Systems insight) ----
    cout << "Bucket count: " << us.bucket_count() << endl;
    cout << "Load factor: " << us.load_factor() << endl;

    cout << "\n========== PART 4: std::unordered_multiset (Unordered, Duplicate Keys) ==========" << endl;

    unordered_multiset<int> ums;
    ums.insert(1);
    ums.insert(1);
    ums.insert(2);
    ums.insert(2);
    cout << "ums size: " << ums.size() << endl;        // 4
    cout << "ums.count(1) = " << ums.count(1) << endl; // 2

    cout << "\n========== 5. SYSTEMS-LEVEL INSIGHTS ==========" << endl;
    cout << "1. std::set vs std::unordered_set:" << endl;
    cout << "   - set: O(log n), sorted, less memory, range queries (lower/upper bound)." << endl;
    cout << "   - unordered_set: O(1) avg, unsorted, requires hash, more memory." << endl;
    cout << "2. Why no operator[]? Sets have no values, only keys. operator[] makes" << endl;
    cout << "   sense only for maps (key -> value)." << endl;
    cout << "3. lower_bound/upper_bound exist ONLY for ordered sets (set/multiset)." << endl;
    cout << "   unordered_set does NOT have them (data isn't sorted)." << endl;
    cout << "4. Memory: Tree nodes (set) have 2 child pointers + color bit." << endl;
    cout << "   Hash nodes (unordered_set) have a next pointer for collisions." << endl;
    cout << "5. When to use set vs unordered_set:" << endl;
    cout << "   - Need sorted order or range queries? -> set." << endl;
    cout << "   - Only need fast membership checks? -> unordered_set." << endl;

    return 0;
}