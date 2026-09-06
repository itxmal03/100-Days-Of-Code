#include <iostream>
#include <deque>
#include <string>
using namespace std;

// ============================================================
//  std::deque QUICK REFERENCE (Date: 2026-09-06)
//  Memory: Chunked dynamic array (list of fixed-size blocks).
//  Systems Note: It's NOT a single contiguous block (like vector)
//  and NOT scattered nodes (like list). It's a middle-ground.
//  Trade-off: O(1) push/pop at BOTH ends, O(1) random access.
// ============================================================

void printDeque(const deque<int> &d, const string &label)
{
    cout << label << ": ";
    for (int val : d)
    {
        cout << val << " ";
    }
    cout << " | Size: " << d.size() << endl;
}

int main()
{
    cout << "========== 1. INITIALIZATION ==========" << endl;

    // (a) Default constructor (empty)
    deque<int> d1;
    cout << "d1 (empty): size = " << d1.size() << endl;

    // (b) Fill constructor: 5 elements, all initialized to 100
    deque<int> d2(5, 100);
    printDeque(d2, "d2 (5x100)");

    // (c) Initializer list
    deque<int> d3 = {1, 2, 3, 4, 5};
    printDeque(d3, "d3 {1,2,3,4,5}");

    // (d) Copy constructor (deep copy)
    deque<int> d4(d3);
    printDeque(d4, "d4 (copy of d3)");

    cout << "\n========== 2. MODIFIERS (PUSH / POP / INSERT) ==========" << endl;
    deque<int> d;

    // ---- Insertion at BOTH ends (O(1)) ----
    d.push_back(10);
    d.push_back(20);
    d.push_front(5);
    d.push_front(1);
    printDeque(d, "After push_front(1,5) & push_back(10,20)");

    // emplace_front and emplace_back (constructs in-place)
    d.emplace_front(0);
    d.emplace_back(30);
    printDeque(d, "After emplace_front(0) & emplace_back(30)");

    // ---- Deletion from BOTH ends (O(1)) ----
    d.pop_front();
    d.pop_back();
    printDeque(d, "After pop_front() & pop_back()");

    // ---- Insert in the middle (O(n) - shifts elements) ----
    // Unlike list, deque supports random access iterators.
    auto it = d.begin();
    advance(it, 2);   // move iterator forward by 2 positions (now points to 10)
    d.insert(it, 99); // inserts 99 before the element at 'it'
    printDeque(d, "After insert(99 at index 2)");

    // ---- emplace (constructs in-place) ----
    it = d.begin();
    advance(it, 1);
    d.emplace(it, 88);
    printDeque(d, "After emplace(88 at index 1)");

    cout << "\n========== 3. ACCESS (O(1) random access) ==========" << endl;
    // ✅ deque supports operator[] and .at() (unlike list, just like vector).
    cout << "d[0] = " << d[0] << endl;
    cout << "d.at(2) = " << d.at(2) << endl;
    cout << "front() = " << d.front() << endl;
    cout << "back()  = " << d.back() << endl;

    // ⚠️ .at() throws an exception if out of bounds (safe).
    // operator[] does NO bounds checking (fast, but dangerous).

    cout << "\n========== 4. ITERATORS (Random Access) ==========" << endl;
    // deque iterators are random-access (like vector).
    // You CAN do 'it + 2' (unlike list).
    cout << "Forward: ";
    for (deque<int>::iterator it = d.begin(); it != d.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    // Reverse iteration (rbegin / rend)
    cout << "Reverse: ";
    for (deque<int>::reverse_iterator rit = d.rbegin(); rit != d.rend(); ++rit)
    {
        cout << *rit << " ";
    }
    cout << endl;

    // Pointer arithmetic works (because it's random-access).
    auto midIt = d.begin() + d.size() / 2;
    cout << "Element at middle (using +): " << *midIt << endl;

    cout << "\n========== 5. ERASE (O(n) - shifts elements) ==========" << endl;
    printDeque(d, "Before erase");

    // Erase single element (by iterator)
    auto eraseIt = d.begin();
    advance(eraseIt, 2); // point to 3rd element
    d.erase(eraseIt);
    printDeque(d, "After erase(index 2)");

    // Erase range: erases elements from 'first' to 'last' (exclusive).
    if (d.size() >= 4)
    {
        auto first = d.begin();
        auto last = d.begin();
        advance(first, 1);
        advance(last, 4);
        d.erase(first, last);
        printDeque(d, "After erase(range [1,4))");
    }

    cout << "\n========== 6. CLEAR vs EMPTY vs SIZE ==========" << endl;
    deque<int> test = {10, 20, 30};
    printDeque(test, "Before clear");

    test.clear();
    cout << "After clear(): size = " << test.size() << endl;
    cout << "Is empty? " << (test.empty() ? "Yes" : "No") << endl;

    cout << "\n========== 7. SYSTEMS-LEVEL INSIGHTS ==========" << endl;
    cout << "1. Memory Layout: deque is a list of fixed-size arrays (chunks)." << endl;
    cout << "   It is NOT a single contiguous block (unlike vector)." << endl;
    cout << "2. Random Access: O(1) because it maps index to chunk + offset." << endl;
    cout << "   This mapping is slightly slower than vector (a few extra arithmetic ops)." << endl;
    cout << "3. Push/Pop at ends: O(1) - it can allocate/deallocate chunks at edges." << endl;
    cout << "4. Middle Insert/Erase: O(n) - shifts elements within the chunks." << endl;
    cout << "5. Cache Locality: Better than list (chunks are contiguous), but worse than" << endl;
    cout << "   vector (iterating skips between chunks)." << endl;
    cout << "6. Iterator Invalidation: Inserting at ends only invalidates iterators if" << endl;
    cout << "   a reallocation happens. Inserting in the middle invalidates all iterators." << endl;
    cout << "7. Deque vs Dequeue: 'deque' is the container (double-ended queue)." << endl;
    cout << "   'dequeue' is a verb meaning 'to remove from the front of a queue'." << endl;

    return 0;
}