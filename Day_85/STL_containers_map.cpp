#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;

// ============================================================
//  ASSOCIATIVE CONTAINERS QUICK REFERENCE (Date: 2026-09-07)
//  ------------------------------------------------------------------
//  1. std::map          : Ordered, Unique Keys, O(log n) operations (Red-Black Tree).
//  2. std::multimap     : Ordered, Duplicate Keys Allowed, O(log n) operations.
//  3. std::unordered_map: Unordered, Unique Keys, O(1) average (Hash Table).
//  4. std::unordered_multimap: Unordered, Duplicate Keys Allowed, O(1) average.
//  Header: <map> (for map/multimap) and <unordered_map> (for unordered versions)
//  Systems Note: Tree-based maps store keys in sorted order. Hash-based maps
//  store keys in arbitrary order (based on hash).
// ============================================================

// Helper: Print a map (ordered, unique keys)
void printMap(const map<string, int> &m, const string &label)
{
    cout << label << " (sorted by key): ";
    for (const auto &p : m)
    {
        cout << "{" << p.first << ":" << p.second << "} ";
    }
    cout << " | Size: " << m.size() << endl;
}

// Helper: Print a multimap (ordered, duplicate keys)
void printMultimap(const multimap<string, int> &m, const string &label)
{
    cout << label << " (sorted, duplicates allowed): ";
    for (const auto &p : m)
    {
        cout << "{" << p.first << ":" << p.second << "} ";
    }
    cout << " | Size: " << m.size() << endl;
}

// Helper: Print an unordered_map (unsorted, unique keys)
void printUnorderedMap(const unordered_map<string, int> &m, const string &label)
{
    cout << label << " (unsorted, unique keys): ";
    for (const auto &p : m)
    {
        cout << "{" << p.first << ":" << p.second << "} ";
    }
    cout << " | Size: " << m.size() << endl;
}

int main()
{
    cout << "========== PART 1: std::map (Ordered, Unique Keys) ==========" << endl;

    // ---- 1. INITIALIZATION ----
    map<string, int> m1;                                    // Default: empty, sorts by key (ascending).
    map<string, int> m2 = {{"z", 26}, {"a", 1}, {"m", 13}}; // Initializer list.
    printMap(m2, "m2 (initialized)");

    // ---- 2. MODIFIERS (insert / emplace / operator[]) ----
    map<string, int> m;

    // operator[]: If key doesn't exist, it inserts with default value (0 for int).
    m["apple"] = 5;  // Inserts {"apple", 5}
    m["banana"] = 3; // Inserts {"banana", 3}
    m["apple"] = 10; // Updates existing key (overwrites value).

    // insert: Does NOT overwrite if key exists. Returns a pair<iterator, bool>.
    auto result = m.insert({"apple", 99}); // Fails (key exists). result.second == false.
    m.insert({"cherry", 7});               // Inserts {"cherry", 7}.

    // emplace: Constructs in-place (avoids temporary). Same behavior as insert.
    m.emplace("date", 12);

    printMap(m, "m after insert/emplace");

    // ---- 3. ACCESS (operator[] and at()) ----
    cout << "m[\"banana\"] = " << m["banana"] << endl;       // 3
    cout << "m.at(\"cherry\") = " << m.at("cherry") << endl; // 7

    // at() does bounds checking (throws exception if key missing).
    // operator[] inserts a default value if key missing (USE WITH CARE).

    // ---- 4. ITERATION (sorted by key) ----
    cout << "Iterating m (sorted): ";
    for (auto it = m.begin(); it != m.end(); ++it)
    {
        cout << "{" << it->first << ":" << it->second << "} ";
    }
    cout << endl;

    // ---- 5. LOOKUP (find / count) ----
    // find: returns iterator or end()
    auto it = m.find("banana");
    if (it != m.end())
        cout << "Found banana: " << it->second << endl;

    // count: returns 1 (exists) or 0 (doesn't) for unique-key maps.
    cout << "count(\"apple\") = " << m.count("apple") << endl; // 1
    cout << "count(\"grape\") = " << m.count("grape") << endl; // 0

    // ---- 6. ERASE ----
    m.erase("apple"); // Erases by key (returns 1 if found).
    auto itErase = m.find("date");
    if (itErase != m.end())
        m.erase(itErase); // Erases by iterator.
    printMap(m, "m after erasing apple & date");

    cout << "\n========== PART 2: std::multimap (Ordered, Duplicate Keys) ==========" << endl;

    // ---- 1. INITIALIZATION ----
    multimap<string, int> mm;
    // ❌ IMPORTANT: multimap does NOT support operator[] (because key is not unique).
    // mm["x"] = 1; // ❌ COMPILATION ERROR!

    // ---- 2. MODIFIERS (insert / emplace) ----
    mm.emplace("x", 1);
    mm.emplace("x", 2);  // Duplicate key allowed.
    mm.insert({"x", 3}); // Duplicate key allowed.
    mm.emplace("y", 10);
    printMultimap(mm, "mm after inserts");

    // ---- 3. LOOKUP (find / count) ----
    // count returns the number of elements with that key.
    cout << "mm.count(\"x\") = " << mm.count("x") << endl; // 3

    // find returns an iterator to the FIRST occurrence of the key.
    auto itMM = mm.find("x");
    if (itMM != mm.end())
    {
        cout << "First occurrence of 'x': {" << itMM->first << ":" << itMM->second << "}" << endl;
    }

    // ---- 4. ERASE ----
    // erase(key) removes ALL elements with that key.
    mm.erase("x"); // Deletes all three "x" entries.
    printMultimap(mm, "mm after erase(\"x\")");

    // erase(iterator) removes only ONE occurrence.
    mm.emplace("z", 5);
    mm.emplace("z", 6);
    auto itEraseMM = mm.find("z");
    if (itEraseMM != mm.end())
        mm.erase(itEraseMM); // Removes only first "z" (5).
    printMultimap(mm, "mm after erase(iterator)");

    cout << "\n========== PART 3: std::unordered_map (Unordered, Unique Keys) ==========" << endl;

    // ---- 1. INITIALIZATION ----
    unordered_map<string, int> um;
    um["alpha"] = 1;
    um["beta"] = 2;
    um["gamma"] = 3;
    printUnorderedMap(um, "um after insertions");

    // ---- 2. COMPLEXITY & ORDER ----
    // Notice the output order is NOT sorted. It is determined by the hash of the key.
    // Operations are O(1) on average, O(n) in worst case (many hash collisions).

    // ---- 3. LOOKUP (find / count) ----
    cout << "um.count(\"beta\") = " << um.count("beta") << endl; // 1

    auto itUM = um.find("gamma");
    if (itUM != um.end())
        cout << "Found gamma: " << itUM->second << endl;

    // ---- 4. BUCKET INTERFACE (Advanced - for systems understanding) ----
    cout << "Number of buckets: " << um.bucket_count() << endl;
    cout << "Load factor: " << um.load_factor() << endl; // avg elements per bucket.

    cout << "\n========== PART 4: std::unordered_multimap (Unordered, Duplicate Keys) ==========" << endl;

    unordered_multimap<string, int> umm;
    umm.emplace("a", 1);
    umm.emplace("a", 2);
    umm.emplace("b", 3);
    cout << "umm size: " << umm.size() << endl;              // 3
    cout << "umm.count(\"a\") = " << umm.count("a") << endl; // 2

    cout << "\n========== 5. SYSTEMS-LEVEL INSIGHTS ==========" << endl;
    cout << "1. std::map vs std::unordered_map:" << endl;
    cout << "   - map: O(log n) operations, sorted order, less memory, better cache" << endl;
    cout << "     for range queries (e.g., find all keys between A and Z)." << endl;
    cout << "   - unordered_map: O(1) average, unsorted, requires a hash function," << endl;
    cout << "     uses more memory (buckets + linked lists for collisions)." << endl;
    cout << "2. multimap vs map: Use multimap when you need multiple values for a key." << endl;
    cout << "   (e.g., students sharing the same name)." << endl;
    cout << "3. operator[] vs insert: operator[] default-constructs a value if key missing." << endl;
    cout << "   insert does NOT overwrite if key exists (returns bool false)." << endl;
    cout << "4. Memory: Tree nodes (map) have 3 pointers (parent, left, right) + color." << endl;
    cout << "   Hash nodes (unordered_map) have a pointer to the next node in the bucket." << endl;
    cout << "5. Complexity Correction: You wrote 'nlogn' for map. It is O(log n) per operation." << endl;
    cout << "   O(n log n) is for sorting the entire map, not for a single lookup/insertion." << endl;

    return 0;
}