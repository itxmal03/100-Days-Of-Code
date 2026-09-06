#include <iostream>
#include <vector>
#include <utility> // std::pair lives here (but often included by <iostream>)
#include <string>
using namespace std;

// =====================================================================
//  std::pair QUICK REFERENCE (Date: 2026-09-06)
//  Definition: A struct that bundles two (possibly different) types.
//  Header: <utility> (but often included by <iostream>/<map>)
//  NOT a container. It is a fundamental building block for
//  associative containers (map, unordered_map) and algorithms.
//  Systems Note: Zero-overhead abstraction. Compiled to raw struct.
// =====================================================================

void printPair(const pair<int, string> &p)
{
    cout << "(" << p.first << ", \"" << p.second << "\")" << endl;
}

int main()
{
    cout << "========== 1. INITIALIZATION ==========" << endl;

    // (a) Default constructor: int=0, string=empty
    pair<int, string> p1;
    cout << "p1 (default): ";
    printPair(p1); // prints (0, "")

    // (b) Value initialization (using constructor)
    pair<int, string> p2(10, "Hello");
    cout << "p2 (constructor): ";
    printPair(p2);

    // (c) Using initializer list (C++11)
    pair<int, string> p3 = {20, "World"};
    cout << "p3 (initializer list): ";
    printPair(p3);

    // (d) Using make_pair (type deduction - useful before C++17)
    auto p4 = make_pair(30, "Auto");
    cout << "p4 (make_pair): ";
    printPair(p4);

    // (e) Structured binding (C++17) - not an init, but a nice destructuring
    auto [num, str] = p4; // num = 30, str = "Auto"
    cout << "Structured binding: num=" << num << ", str=" << str << endl;

    cout << "\n========== 2. ACCESS (first / second) ==========" << endl;
    pair<int, double> p5 = {42, 3.14};
    cout << "p5.first = " << p5.first << endl;   // 42
    cout << "p5.second = " << p5.second << endl; // 3.14

    // first and second are public members. You can modify them directly.
    p5.first = 99;
    p5.second = 2.71;
    cout << "After modification: (" << p5.first << ", " << p5.second << ")" << endl;

    cout << "\n========== 3. SWAP (Swapping pairs) ==========" << endl;
    pair<int, string> a = {1, "Alpha"};
    pair<int, string> b = {2, "Beta"};
    cout << "Before swap: a=";
    printPair(a);
    cout << " b=";
    printPair(b);
    a.swap(b); // swaps both first and second
    cout << "After a.swap(b): a=";
    printPair(a);
    cout << " b=";
    printPair(b);

    // std::swap also works (specialized for pair)
    swap(a, b);
    cout << "After std::swap(a,b): a=";
    printPair(a);
    cout << " b=";
    printPair(b);

    cout << "\n========== 4. COMPARISON OPERATORS (Lexicographic) ==========" << endl;
    // Pairs compare first elements first. If first equal, compare second.
    pair<int, int> x = {1, 100};
    pair<int, int> y = {2, 0};
    pair<int, int> z = {1, 200};

    cout << "(1,100) == (2,0)? " << (x == y ? "true" : "false") << endl;  // false
    cout << "(1,100) <  (2,0)? " << (x < y ? "true" : "false") << endl;   // true (1 < 2)
    cout << "(1,100) <  (1,200)? " << (x < z ? "true" : "false") << endl; // true (100 < 200)

    // All 6 comparison operators are supported: ==, !=, <, <=, >, >=
    cout << "\n========== 5. TUPLE-LIKE BEHAVIOR (get / tie) ==========" << endl;
    pair<int, char> p6 = {7, 'A'};

    // get<0>() and get<1>() - like tuple
    cout << "get<0>(p6) = " << get<0>(p6) << endl; // 7
    cout << "get<1>(p6) = " << get<1>(p6) << endl; // 'A'

    // tie - extracts both into variables (C++11)
    int val1;
    char val2;
    tie(val1, val2) = p6;
    cout << "tie extracted: val1=" << val1 << ", val2=" << val2 << endl;

    cout << "\n========== 6. USAGE WITH VECTORS (Real-world example) ==========" << endl;
    vector<pair<int, string>> vec;
    vec.push_back({1, "Apple"});           // brace init (creates temporary pair)
    vec.emplace_back(2, "Banana");         // emplace avoids temporary (faster)
    vec.push_back(make_pair(3, "Cherry")); // make_pair (explicit)
    cout << "vector of pairs: ";
    for (auto &p : vec)
    {
        cout << "(" << p.first << "," << p.second << ") ";
    }
    cout << endl;

    cout << "\n========== 7. SYSTEMS-LEVEL INSIGHTS ==========" << endl;
    cout << "1. Memory Layout: std::pair<T,U> is exactly a struct { T first; U second; }." << endl;
    cout << "   No virtual functions, no extra pointers. Zero-overhead." << endl;
    cout << "2. Size: sizeof(pair<int, char>) = 8 bytes (due to padding)." << endl;
    cout << "   sizeof(pair<int, int>) = 8 bytes." << endl;
    cout << "3. Alignment: The compiler aligns members for CPU efficiency." << endl;
    cout << "   E.g., pair<int, char> may have padding after char to align to 4 bytes." << endl;
    cout << "4. Performance: Passing pair by const reference is cheap (just 8-16 bytes)." << endl;
    cout << "5. Why it's required: Associative containers (map, unordered_map) store elements" << endl;
    cout << "   as key-value pairs. You CANNOT insert a single key without a value." << endl;
    cout << "   pair is the glue that connects them." << endl;
    cout << "   (You will study maps next—this is exactly why pair is introduced first.)" << endl;
    cout << "6. Important: In maps, value_type is pair<const Key, T> (key is const!)." << endl;

    return 0;
}