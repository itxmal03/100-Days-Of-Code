#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// ============================================================
//  std::priority_queue QUICK REFERENCE (Date: 2026-09-07)
//  Type: Container Adapter (Heaps - Max/Min)
//  Default Underlying Container: std::vector<T>
//  Header: <queue>
//  Systems Note: Internally implemented as a Binary Heap (tree stored in a vector).
//  Max-Heap: Top is the LARGEST element.
//  Min-Heap: Top is the SMALLEST element.
// ============================================================

// Helper: Prints priority_queue WITHOUT destroying it (pass by value copies it).
void printPQ(string label, priority_queue<int> pq)
{
    cout << label << " (top to bottom): ";
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}

// Overloaded helper for MIN-HEAP (different type)
void printPQMin(string label, priority_queue<int, vector<int>, greater<int>> pq)
{
    cout << label << " (top to bottom): ";
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}

int main()
{
    cout << "========== 1. INITIALIZATION ==========" << endl;

    // (a) Default: Max-Heap (Largest element at top)
    priority_queue<int> maxHeap;
    cout << "maxHeap (default): size = " << maxHeap.size() << endl;

    // (b) Min-Heap: Smallest element at top (uses greater<int>)
    // FIXED: vector<int> NOT vector<int, greater<int>>
    priority_queue<int, vector<int>, greater<int>> minHeap;
    cout << "minHeap: size = " << minHeap.size() << endl;

    // (c) Copy constructor
    priority_queue<int> copyMax;
    copyMax.push(10);
    priority_queue<int> copyMax2(copyMax); // Deep copy
    cout << "copyMax2 size: " << copyMax2.size() << endl;

    cout << "\n========== 2. MODIFIERS (push / emplace / pop) ==========" << endl;

    // ---- MAX-HEAP Test ----
    priority_queue<int> pqMax;
    pqMax.push(10);
    pqMax.push(50);
    pqMax.push(20);
    pqMax.push(1);
    pqMax.emplace(30); // constructs in-place

    printPQ("Max-Heap (top largest)", pqMax); // Prints: 50 30 20 10 1

    pqMax.pop();                             // removes 50
    pqMax.pop();                             // removes 30
    printPQ("Max-Heap after 2 pops", pqMax); // Prints: 20 10 1

    // ---- MIN-HEAP Test ----
    priority_queue<int, vector<int>, greater<int>> pqMin;
    pqMin.push(10);
    pqMin.push(50);
    pqMin.push(20);
    pqMin.push(1);
    pqMin.emplace(30);

    printPQMin("Min-Heap (top smallest)", pqMin); // Prints: 1 10 20 30 50

    pqMin.pop();                                // removes 1
    pqMin.pop();                                // removes 10
    printPQMin("Min-Heap after 2 pops", pqMin); // Prints: 20 30 50

    cout << "\n========== 3. ACCESS (top) ==========" << endl;
    priority_queue<int> q;
    q.push(100);
    q.push(200);
    q.push(150);

    // top() returns a const reference (read-only).
    // Unlike stack/queue, you CANNOT modify the top element directly via assignment.
    // q.top() = 500; // ❌ ERROR! (const reference)
    cout << "q.top() = " << q.top() << endl; // 200 (largest)

    cout << "\n========== 4. CAPACITY (empty / size) ==========" << endl;
    priority_queue<int> q2;
    cout << "q2.empty() = " << (q2.empty() ? "true" : "false") << endl;
    q2.push(5);
    cout << "After push: size = " << q2.size() << endl;

    cout << "\n========== 5. SWAP ==========" << endl;
    priority_queue<int> heapA;
    heapA.push(1);
    heapA.push(2);

    priority_queue<int> heapB;
    heapB.push(99);
    heapB.push(88);
    heapB.push(77);

    cout << "Before swap:" << endl;
    printPQ("heapA", heapA); // 2 1
    printPQ("heapB", heapB); // 99 88 77

    heapA.swap(heapB);
    cout << "After swap:" << endl;
    printPQ("heapA", heapA); // 99 88 77
    printPQ("heapB", heapB); // 2 1

    cout << "\n========== 6. UNDERLYING CONTAINER & COMPARATOR ==========" << endl;
    // priority_queue is an adapter on top of vector (default).
    // The comparator defines the ordering.

    // Default comparator: less<int> -> produces Max-Heap.
    priority_queue<int> defaultMax; // Same as priority_queue<int, vector<int>, less<int>>
    defaultMax.push(5);
    defaultMax.push(1);
    cout << "Default (less<int>) top: " << defaultMax.top() << endl; // 5

    // Explicit Min-Heap: greater<int> -> produces Min-Heap.
    priority_queue<int, vector<int>, greater<int>> explicitMin;
    explicitMin.push(5);
    explicitMin.push(1);
    cout << "Min (greater<int>) top: " << explicitMin.top() << endl; // 1

    cout << "\n========== 7. SYSTEMS-LEVEL INSIGHTS (The Binary Heap) ==========" << endl;
    cout << "1. Implementation: Binary Heap (a complete binary tree)." << endl;
    cout << "   But it's stored in a std::vector! (Tree represented as array)." << endl;
    cout << "   For Max-Heap: Parent >= Children. For Min-Heap: Parent <= Children." << endl;
    cout << "2. Why vector? Contiguous memory -> fast cache access." << endl;
    cout << "3. Complexity: push() and pop() are O(log n) because they perform" << endl;
    cout << "   heapify-up/down (swapping with parent/children)." << endl;
    cout << "4. top() is O(1)." << endl;
    cout << "5. No Iterators: You cannot traverse a priority_queue. Use top/pop to drain." << endl;
    cout << "6. Compare to stack/queue: priority_queue is the only one where" << endl;
    cout << "   the element order depends on the VALUE, not insertion time." << endl;

    return 0;
}