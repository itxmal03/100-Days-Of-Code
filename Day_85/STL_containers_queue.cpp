#include <iostream>
#include <queue>
#include <list>
#include <deque> // default
using namespace std;

// ============================================================
//  std::queue QUICK REFERENCE (Date: 2026-09-07)
//  Type: Container Adapter (FIFO - First In First Out)
//  Default Underlying Container: std::deque<T>
//  Header: <queue>
//  Systems Note: queue is NOT a container. It wraps an existing
//  container (deque/list) and restricts its interface to
//  push/pop/front/back.
//  CRITICAL: vector CANNOT be used as underlying container!
// ============================================================

// Helper: Prints queue WITHOUT destroying it (pass by value copies it).
void printQueue(string label, queue<int> q)
{
    cout << label << " (front to back): ";
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << " | Size (of copy): " << q.size() << endl;
}

int main()
{
    cout << "========== 1. INITIALIZATION ==========" << endl;

    // (a) Default constructor (uses std::deque<int>)
    queue<int> q1;
    cout << "q1 (empty): size = " << q1.size() << endl;

    // (b) Copy constructor (deep copies the underlying container)
    queue<int> q2;
    q2.push(10);
    q2.push(20);
    queue<int> q3(q2); // q3 is a deep copy of q2
    cout << "q3 (copy of q2): size = " << q3.size() << endl;

    cout << "\n========== 2. MODIFIERS (push / emplace / pop) ==========" << endl;
    queue<int> q;

    // push: adds element to the BACK of the queue
    q.push(10);
    q.push(20);
    q.push(30);

    // emplace: constructs in-place (avoids temporary copy).
    q.emplace(40);
    q.emplace(50);

    printQueue("After pushes & emplaces", q); // Prints: 10 20 30 40 50

    // pop: removes element from the FRONT (void return)
    q.pop();                         // removes 10
    q.pop();                         // removes 20
    printQueue("After two pops", q); // Prints: 30 40 50

    cout << "\n========== 3. ACCESS (front / back) ==========" << endl;
    queue<int> q4;
    q4.push(100);
    q4.push(200);
    q4.push(300);

    // front() -> first inserted element (oldest)
    cout << "q4.front() = " << q4.front() << endl; // 100
    // back() -> last inserted element (newest)
    cout << "q4.back() = " << q4.back() << endl; // 300

    // You can MODIFY the front/back directly (returns a reference).
    q4.front() = 999;
    q4.back() = 888;
    cout << "After modification: front=" << q4.front() << ", back=" << q4.back() << endl; // 999, 888

    cout << "\n========== 4. CAPACITY (empty / size) ==========" << endl;
    queue<int> q5;
    cout << "q5.empty() = " << (q5.empty() ? "true" : "false") << endl;
    cout << "q5.size() = " << q5.size() << endl;

    q5.push(1);
    q5.push(2);
    cout << "After 2 pushes: size = " << q5.size() << endl;

    cout << "\n========== 5. SWAP ==========" << endl;
    queue<int> queueA;
    queueA.push(1);
    queueA.push(2);

    queue<int> queueB;
    queueB.push(99);
    queueB.push(88);
    queueB.push(77);

    cout << "Before swap:" << endl;
    printQueue("queueA", queueA); // 1 2
    printQueue("queueB", queueB); // 99 88 77

    queueA.swap(queueB); // Member function (O(1))
    // std::swap(queueA, queueB); // Global overload also works

    cout << "After swap:" << endl;
    printQueue("queueA", queueA); // 99 88 77
    printQueue("queueB", queueB); // 1 2

    cout << "\n========== 6. UNDERLYING CONTAINER (The Critical Gotcha) ==========" << endl;

    // (a) Using std::list as underlying container (WORKS)
    queue<int, list<int>> queueList;
    queueList.push(10);
    queueList.push(20);
    cout << "queue<int, list<int>> front: " << queueList.front() << endl;

    // (b) Using std::deque (default - WORKS)
    queue<int, deque<int>> queueDeque;
    queueDeque.push(5);
    cout << "queue<int, deque<int>> front: " << queueDeque.front() << endl;

    // (c) ❌ IMPORTANT: USING std::vector WILL CAUSE A COMPILATION ERROR!
    // queue<int, vector<int>> queueVec; // ❌ ERROR!
    // Reason: vector does NOT have pop_front().
    // The queue adapter requires the underlying container to support:
    // front(), back(), push_back(), pop_front(), empty(), size().
    // std::vector supports push_back() and back(), but NOT pop_front()
    // (removing the first element of a vector is O(n) and not provided).

    cout << "\n========== 7. SYSTEMS-LEVEL INSIGHTS ==========" << endl;
    cout << "1. FIFO vs LIFO: queue is First-In-First-Out (like a line)." << endl;
    cout << "   stack is Last-In-First-Out (like a pile of plates)." << endl;
    cout << "2. Container Adapter: queue restricts the underlying container." << endl;
    cout << "3. Default: deque. Why not list? deque is faster for this use case" << endl;
    cout << "   due to better cache locality than list." << endl;
    cout << "4. Why Vector Fails: vector lacks pop_front(). Removing the front" << endl;
    cout << "   of a vector requires shifting all elements (O(n)), which breaks" << endl;
    cout << "   the O(1) guarantee of queue. deque and list support O(1) pop_front." << endl;
    cout << "5. Pop returns void: Like stack, pop() does NOT return the value." << endl;
    cout << "   Pattern: int val = q.front(); q.pop();" << endl;

    return 0;
}