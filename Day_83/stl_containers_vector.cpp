#include <iostream>
#include <vector>
using namespace std;

// ============================================================
//  std::vector QUICK REFERENCE (Date: 2026-09-05)
//  Memory: Contiguous heap allocation (like a dynamic array).
//  Systems Note: 'size' = active elements, 'capacity' = allocated memory.
// ============================================================

void printVector(const vector<int> &v, const string &label)
{
    cout << label << ": ";
    for (int val : v)
    { //  FIXED: No variable shadowing (used 'val' instead of 'v')
        cout << val << " ";
    }
    cout << " | Size: " << v.size() << " | Cap: " << v.capacity() << endl;
}

int main()
{
    cout << "========== 1. INITIALIZATION ==========" << endl;

    // (a) Default constructor (empty)
    vector<int> vec1;
    cout << "vec1 (empty): size=" << vec1.size() << ", cap=" << vec1.capacity() << endl;

    // (b) Fill constructor: 5 elements, all initialized to 100
    vector<int> vec2(5, 100);
    printVector(vec2, "vec2 (5x100)");

    // (c) Initializer list
    vector<int> vec3 = {1, 2, 3, 4, 5};
    printVector(vec3, "vec3 {1,2,3,4,5}");

    // (d) Copy constructor (deep copy)
    vector<int> vec4(vec3);
    printVector(vec4, "vec4 (copy of vec3)");

    cout << "\n========== 2. MODIFIERS (PUSH / POP) ==========" << endl;
    vector<int> v;

    // push_back vs emplace_back (for ints, they are identical)
    v.push_back(10);
    v.push_back(20);
    v.emplace_back(30); // constructs in-place (useful for complex objects)
    printVector(v, "After push_back/emplace_back");

    // pop_back (removes last element)
    v.pop_back();
    printVector(v, "After pop_back (removed 30)");

    cout << "\n========== 3. ACCESS (O(1)) ==========" << endl;
    vector<int> nums = {100, 200, 300, 400};

    // operator[] (no bounds checking) vs .at() (throws exception if out of range)
    cout << "nums[1] = " << nums[1] << endl;
    cout << "nums.at(2) = " << nums.at(2) << endl;

    // front() and back() - returns reference to first/last element
    cout << "front = " << nums.front() << ", back = " << nums.back() << endl;

    cout << "\n========== 4. ITERATORS (Pointers to elements) ==========" << endl;
    // begin() -> points to first element.
    // end()   -> points ONE PAST the last element (DO NOT DEREFERENCE).
    cout << "*begin = " << *(nums.begin()) << endl;
    cout << "*(end - 1) = " << *(nums.end() - 1) << " (last element safely)" << endl;
    // ❌ NEVER DO: cout << *(nums.end()) << endl; // CRASH!

    // Forward iteration
    cout << "Forward: ";
    for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    // Reverse iteration (rbegin = reverse begin, rend = reverse end)
    cout << "Reverse: ";
    for (vector<int>::reverse_iterator rit = nums.rbegin(); rit != nums.rend(); rit++)
    {
        cout << *rit << " ";
    }
    cout << endl;

    // Modern range-based for loop (preferred)
    cout << "Range-for: ";
    for (int val : nums)
    {
        cout << val << " ";
    }
    cout << endl;

    cout << "\n========== 5. INSERT & ERASE (O(n) operations) ==========" << endl;
    vector<int> data = {1, 2, 3, 4, 5};
    printVector(data, "Original");

    // Insert: inserts 99 at index 2 (shifts elements right)
    data.insert(data.begin() + 2, 99);
    printVector(data, "After insert(99 at index 2)");

    // Erase single element: removes element at index 3 (value 4)
    data.erase(data.begin() + 3);
    printVector(data, "After erase(index 3)");

    // Erase range: removes indices 1 to 3 (end is exclusive)
    // ⚠️ SAFETY CHECK: Ensure the range is valid before using.
    if (data.size() >= 4)
    {
        data.erase(data.begin() + 1, data.begin() + 4);
        printVector(data, "After erase(range [1,4))");
    }
    else
    {
        cout << "Skipped range erase: vector too small." << endl;
    }

    cout << "\n========== 6. CLEAR vs EMPTY vs CAPACITY ==========" << endl;
    vector<int> test = {10, 20, 30};
    printVector(test, "Before clear");

    // clear() destroys all elements, but capacity remains allocated.
    test.clear();
    cout << "After clear(): size = " << test.size() << ", capacity = " << test.capacity() << " (memory NOT freed)" << endl;

    // empty() checks if size == 0
    cout << "Is empty? " << (test.empty() ? "Yes" : "No") << endl;

    // shrink_to_fit() (non-binding) requests to reduce capacity to size.
    test.shrink_to_fit();
    cout << "After shrink_to_fit(): capacity = " << test.capacity() << " (may have shrunk)" << endl;

    cout << "\n========== 7. SYSTEMS-LEVEL INSIGHTS ==========" << endl;
    cout << "1. Size vs Capacity: Size = active elements, Capacity = allocated heap memory." << endl;
    cout << "2. Reallocation: When capacity is exceeded, vector allocates a new larger block" << endl;
    cout << "   (usually doubles), copies/moves old elements, and frees the old block." << endl;
    cout << "3. Iterator Invalidation: Insert/erase can invalidate iterators (reallocation)." << endl;
    cout << "4. Contiguity: vector elements are stored contiguously, so it has cache-friendly" << endl;
    cout << "   memory access (unlike list/deque)." << endl;

    return 0;
}