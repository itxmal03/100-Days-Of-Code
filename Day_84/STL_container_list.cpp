#include <iostream>
#include <list>
#include <string>
using namespace std;

// ============================================================
//  std::list QUICK REFERENCE (Date: 2026-09-06)
//  Memory: Doubly linked list (non-contiguous heap nodes).
//  Systems Note: Each node has 'prev' and 'next' pointers.
//  Trade-off: O(1) insert/delete ANYWHERE, but NO random access.
// ============================================================

void printList(const list<int> &lst, const string &label)
{
    cout << label << ": ";
    for (int val : lst)
    {
        cout << val << " ";
    }
    cout << " | Size: " << lst.size() << endl;
}

int main()
{
    cout << "========== 1. INITIALIZATION ==========" << endl;

    // (a) Default constructor (empty)
    list<int> list1;
    cout << "list1 (empty): size = " << list1.size() << endl;

    // (b) Fill constructor: 5 elements, all initialized to 100
    list<int> list2(5, 100);
    printList(list2, "list2 (5x100)");

    // (c) Initializer list
    list<int> list3 = {1, 2, 3, 4, 5};
    printList(list3, "list3 {1,2,3,4,5}");

    // (d) Copy constructor (deep copy)
    list<int> list4(list3);
    printList(list4, "list4 (copy of list3)");

    cout << "\n========== 2. MODIFIERS (PUSH / POP / INSERT) ==========" << endl;
    list<int> l;

    // ---- Insertion at both ends (O(1)) ----
    l.push_back(10);
    l.push_back(20);
    l.push_front(5);
    l.push_front(1);
    printList(l, "After push_front(1,5) & push_back(10,20)");

    // emplace_front and emplace_back (constructs in-place)
    l.emplace_front(0);
    l.emplace_back(30);
    printList(l, "After emplace_front(0) & emplace_back(30)");

    // ---- Deletion from both ends (O(1)) ----
    l.pop_front();
    l.pop_back();
    printList(l, "After pop_front() & pop_back()");

    // ---- Insert in the middle (O(1) IF you have the iterator) ----
    // To insert at a specific position, we need an iterator.
    auto it = l.begin(); // points to first element (1)
    advance(it, 2);      // move iterator forward by 2 positions (now points to 10)
    l.insert(it, 99);    // inserts 99 before the element at 'it'
    printList(l, "After insert(99 at index 2)");

    // ---- emplace (constructs in-place) ----
    it = l.begin();
    advance(it, 1);
    l.emplace(it, 88);
    printList(l, "After emplace(88 at index 1)");

    cout << "\n========== 3. ACCESS (NO random access) ==========" << endl;
    // ⚠️ CRITICAL: list does NOT support operator[] or .at()
    // You can only access front and back in O(1).
    cout << "front() = " << l.front() << endl;
    cout << "back()  = " << l.back() << endl;

    // To access the middle, you MUST traverse with iterators (O(n)).
    auto midIt = l.begin();
    advance(midIt, l.size() / 2);
    cout << "Element at middle = " << *midIt << " (retrieved by advancing iterator)" << endl;

    cout << "\n========== 4. ITERATORS (Bidirectional) ==========" << endl;
    // begin() / end() are bidirectional (can go ++ and --).
    cout << "Forward: ";
    for (list<int>::iterator it = l.begin(); it != l.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    // Reverse iteration (rbegin / rend)
    cout << "Reverse: ";
    for (list<int>::reverse_iterator rit = l.rbegin(); rit != l.rend(); ++rit)
    {
        cout << *rit << " ";
    }
    cout << endl;

    // ⚠️ IMPORTANT: advance() is O(n) for list (it walks the nodes).
    // Unlike vector, you cannot do 'it + 2' because memory is not contiguous.

    cout << "\n========== 5. ERASE (O(1) with iterator) ==========" << endl;
    printList(l, "Before erase");

    // Erase single element (by iterator)
    auto eraseIt = l.begin();
    advance(eraseIt, 2); // point to 3rd element
    l.erase(eraseIt);
    printList(l, "After erase(index 2)");

    // Erase range: erases elements from 'first' to 'last' (exclusive).
    // ⚠️ SAFETY: Ensure iterators are valid.
    if (l.size() >= 4)
    {
        auto first = l.begin();
        auto last = l.begin();
        advance(first, 1);
        advance(last, 4);
        l.erase(first, last);
        printList(l, "After erase(range [1,4))");
    }

    cout << "\n========== 6. CLEAR vs EMPTY vs SIZE ==========" << endl;
    list<int> test = {10, 20, 30};
    printList(test, "Before clear");

    test.clear();
    cout << "After clear(): size = " << test.size() << endl;
    cout << "Is empty? " << (test.empty() ? "Yes" : "No") << endl;

    cout << "\n========== 7. LIST-SPECIFIC OPERATIONS (Advantages) ==========" << endl;
    list<int> a = {1, 2, 3};
    list<int> b = {4, 5, 6};

    // splice: transfer nodes from one list to another (O(1) for entire list).
    a.splice(a.end(), b); // moves all elements from b to the end of a.
    printList(a, "a after splice(b)");
    cout << "b after splice: size = " << b.size() << " (empty)" << endl;

    // reverse: O(n) - reverses the order of nodes.
    a.reverse();
    printList(a, "a after reverse()");

    // sort: O(n log n) - sorts the list (stable).
    a.sort();
    printList(a, "a after sort()");

    // unique: removes consecutive duplicates (O(n)).
    list<int> dup = {1, 1, 2, 3, 3, 4};
    dup.unique();
    printList(dup, "dup after unique()");

    // merge: merges two sorted lists (O(n)).
    list<int> listX = {1, 3, 5};
    list<int> listY = {2, 4, 6};
    listX.merge(listY);
    printList(listX, "listX after merge(listY)");

    cout << "\n========== 8. SYSTEMS-LEVEL INSIGHTS ==========" << endl;
    cout << "1. Contiguity: list nodes are scattered in heap memory (bad cache locality)." << endl;
    cout << "   vector stores elements contiguously (great cache locality)." << endl;
    cout << "2. Random Access: list has NO operator[]. Access is O(n). vector has O(1)." << endl;
    cout << "3. Insert/Delete: list has O(1) anywhere (if you have the iterator)." << endl;
    cout << "   vector has O(n) for insert/erase in middle (shifts elements)." << endl;
    cout << "4. Memory Overhead: Each list node stores 2 extra pointers (prev/next)." << endl;
    cout << "   vector has minimal overhead (just capacity and size)." << endl;
    cout << "5. Iterator Invalidation: In list, iterators remain valid after insert/erase" << endl;
    cout << "   (except for the erased element). In vector, most operations invalidate." << endl;

    return 0;
}