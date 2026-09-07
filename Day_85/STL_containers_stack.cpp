#include <iostream>
#include <stack>
#include <vector>
#include <list>
using namespace std;

// ============================================================
//  std::stack QUICK REFERENCE (Date: 2026-09-07)
//  Type: Container Adapter (LIFO - Last In First Out)
//  Default Underlying Container: std::deque<T>
//  Header: <stack>
//  Systems Note: stack is NOT a container. It wraps an existing
//  container (deque/vector/list) and restricts its interface to
//  just push/pop/top. Zero overhead abstraction.
// ============================================================

// Helper function to print stack WITHOUT destroying the original.
// We pass by VALUE (copy) so the original remains untouched.
void printStack(string label, stack<int> s)
{
    cout << label << " (top to bottom): ";
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << " | Size: " << s.size() << endl; // will print 0 because we popped the copy
}

// Overloaded print that prints size before popping the copy.
void printStackWithSize(string label, stack<int> s)
{
    cout << label << " (before pop copy): size=" << s.size() << ", top to bottom: ";
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main()
{
    cout << "========== 1. INITIALIZATION ==========" << endl;

    // (a) Default constructor (uses std::deque<int> as underlying container)
    stack<int> s1;
    cout << "s1 (empty): size = " << s1.size() << endl;

    // (b) Copy constructor (deep copies the underlying container)
    stack<int> s2;
    s2.push(10);
    s2.push(20);
    stack<int> s3(s2); // s3 is a copy of s2
    cout << "s3 (copy of s2): size = " << s3.size() << endl;

    cout << "\n========== 2. MODIFIERS (push / emplace / pop) ==========" << endl;
    stack<int> s;

    // push: copies/moves an existing object into the stack
    s.push(10);
    s.push(20);
    s.push(30);

    // emplace: constructs the object in-place (avoids temporary copy).
    // For ints, it's identical to push, but for heavy objects it's faster.
    s.emplace(40);
    s.emplace(50);

    printStack("After pushes & emplaces", s); // Prints: 50 40 30 20 10

    // pop: removes the top element (void return)
    s.pop();                         // removes 50
    s.pop();                         // removes 40
    printStack("After two pops", s); // Prints: 30 20 10

    cout << "\n========== 3. ACCESS (top) ==========" << endl;
    stack<int> s4;
    s4.push(100);
    s4.push(200);
    s4.push(300);

    // top() returns a reference to the last inserted element.
    cout << "s4.top() = " << s4.top() << endl; // 300

    // You can modify the top element directly (since it returns a reference).
    s4.top() = 999;
    cout << "s4.top() after modification = " << s4.top() << endl; // 999

    cout << "\n========== 4. CAPACITY (empty / size) ==========" << endl;
    stack<int> s5;
    cout << "s5.empty() = " << (s5.empty() ? "true" : "false") << endl;
    cout << "s5.size() = " << s5.size() << endl;

    s5.push(1);
    s5.push(2);
    cout << "After 2 pushes: size = " << s5.size() << endl;
    cout << "s5.empty() = " << (s5.empty() ? "true" : "false") << endl;

    cout << "\n========== 5. SWAP ==========" << endl;
    stack<int> stackA;
    stackA.push(1);
    stackA.push(2);

    stack<int> stackB;
    stackB.push(99);
    stackB.push(88);
    stackB.push(77);

    cout << "Before swap:" << endl;
    printStack("stackA", stackA); // 2 1
    printStack("stackB", stackB); // 77 88 99

    // swap exchanges the underlying containers efficiently (O(1) usually).
    stackA.swap(stackB); // Member function
    // std::swap(stackA, stackB); // Also works (global overload)

    cout << "After swap:" << endl;
    printStack("stackA", stackA); // 77 88 99
    printStack("stackB", stackB); // 2 1

    cout << "\n========== 6. UNDERLYING CONTAINER (The Systems Secret) ==========" << endl;
    // By default, stack uses std::deque. Why?
    // Because deque offers O(1) push/pop at both ends and DOES NOT
    // invalidate pointers/references to existing elements when growing.

    // (a) Using std::vector as underlying container
    stack<int, vector<int>> stackVec;
    stackVec.push(1);
    stackVec.push(2);
    cout << "stack<int, vector<int>> top: " << stackVec.top() << endl;

    // (b) Using std::list as underlying container
    stack<int, list<int>> stackList;
    stackList.push(10);
    stackList.push(20);
    cout << "stack<int, list<int>> top: " << stackList.top() << endl;

    cout << "\n========== 7. SYSTEMS-LEVEL INSIGHTS ==========" << endl;
    cout << "1. Container Adapter: std::stack is not a container. It is a wrapper." << endl;
    cout << "   It restricts the underlying container to LIFO operations only." << endl;
    cout << "2. Default Choice (deque): Why not vector?" << endl;
    cout << "   - vector reallocates memory when it grows, invalidating references." << endl;
    cout << "   - deque allocates in chunks, so push_back() does NOT invalidate" << endl;
    cout << "     references to existing elements (only iterators)." << endl;
    cout << "   - deque gives O(1) push/pop at both ends." << endl;
    cout << "3. When to use vector: If you need absolute memory contiguity, you can" << endl;
    cout << "   use stack<int, vector<int>>, but be aware of reallocation costs." << endl;
    cout << "4. Underlying Container Requirements:" << endl;
    cout << "   Must support: back(), push_back(), pop_back(), empty(), size()." << endl;
    cout << "   (vector, deque, list all satisfy this)." << endl;
    cout << "5. Pop returns void: std::stack::pop() does NOT return the value." << endl;
    cout << "   This is by design (exception safety). You must use top() before pop()." << endl;
    cout << "   Correct pattern: int val = s.top(); s.pop();" << endl;

    return 0;
}