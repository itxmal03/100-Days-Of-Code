# 📅 Day 25 – Vector & List Deep Dive  
**100 Days of Code – DSA Series Revision**
 
 ### Date 15-Feb-2026
---

## 🎯 Objective of the Day

Today’s goal was to revise and strengthen understanding of:

- Dynamic arrays (`vector` in C++ and `List` in Dart)
- Size vs Capacity
- Linear Search
- Reversing an array using the Two Pointer technique
- XOR trick for finding a single unique number
- Time and Space Complexity analysis
- Differences between C++ and Dart implementations

This day focused on strengthening **problem-solving patterns**, not just syntax.

---

# 📚 Concepts Learned

---

## 1️⃣ Dynamic Arrays – Vector (C++) vs List (Dart)

### What is a Dynamic Array?

A dynamic array:

- Stores elements in contiguous memory - adjacent  to each other
- Allows index-based access
- Automatically resizes when full
- Is allocated in heap memory

---

### 🔹 In C++ (`vector`)

- Part of the Standard Template Library (STL)
- Has:
  - **size()** → number of elements currently stored
  - **capacity()** → allocated storage space
- When capacity becomes full:
  - A new larger memory block is created (usually double the size)
  - Old elements are copied into new memory
  - Old memory is deleted

---

### 🔹 In Dart (`List`)

- By default, lists are growable
- Only **length** is directly accessible
- Internal capacity management is handled automatically
- Memory is managed by garbage collection
- Capacity is not directly visible

---

# 2️⃣ Size vs Capacity (Important Concept)

### Size
Number of elements currently inside the container.

Example:
If elements are `[4, 1, 2]`, then size = 3.

### Capacity (C++ only visible)
Amount of allocated memory available before resizing.

Important:
- Capacity ≥ Size
- When size exceeds capacity → resizing occurs

---

# 3️⃣ Amortized Time Complexity

When inserting elements using:

- `push_back()` in C++
- `add()` in Dart

Most insertions take constant time.

Occasionally resizing occurs, which takes O(n).

Because resizing does not happen every time, the **average insertion cost** becomes:

**Amortized O(1)**

Meaning:
Expensive operations are spread across many cheap operations.

---

# 4️⃣ XOR Trick – Single Number Problem

### Problem Pattern

Given:
- Every element appears twice
- Except one element

Goal:
Find the unique element.

### XOR Properties

- n XOR n = 0  
- n XOR 0 = n  

Duplicates cancel out, leaving only the unique value.

### Example

Array:
4, 1, 2, 1, 2

Duplicates cancel:
1 XOR 1 = 0  
2 XOR 2 = 0  

Remaining = 4

### Complexity

- Time: O(n)
- Space: O(1)

Condition:
Works only when duplicates appear exactly twice.

---

# 5️⃣ Linear Search Pattern

### Logic

- Start from index 0
- Compare each element with target
- If found → return index
- If not found → return -1

### Complexity

- Best case → O(1)
- Worst case → O(n)
- Space → O(1)

This is a brute-force searching technique.

---

# 6️⃣ Reverse Using Two Pointer Technique

### Logic

- Start pointer = 0
- End pointer = n - 1
- Swap elements
- Move inward
- Continue until start < end

### Why O(n/2)?

Only half the elements are swapped.

### Why O(n)?

In Big-O notation, constants are ignored.

O(n/2) simplifies to O(n).

### Complexity

- Time: O(n)
- Space: O(1)

This pattern is commonly used in:

- Palindrome checking
- Partition problems
- Removing duplicates in sorted arrays
- Many advanced algorithms

---

# 🔄 Differences Between C++ and Dart Used Today

---

## 1️⃣ Data Structure Name

| C++ | Dart |
|------|------|
| vector | List |

---

## 2️⃣ Memory Model

| C++ | Dart |
|------|------|
| Manual memory management | Garbage collected |
| Explicit capacity control | Runtime-managed capacity |
| Low-level control | Managed runtime environment |

---

## 3️⃣ Size and Capacity

| C++ | Dart |
|------|------|
| size() available | length available |
| capacity() available | capacity not directly accessible |

---

## 4️⃣ Adding Elements

| C++ | Dart |
|------|------|
| push_back() | add() |

Both are **Amortized O(1)**.

---

## 5️⃣ Removing Last Element

| C++ | Dart |
|------|------|
| pop_back() | removeLast() |

---

## 6️⃣ Accessing Elements

| C++ | Dart |
|------|------|
| vec[i] | list[i] |
| vec.at(i) | elementAt(i) |

Both provide **O(1)** access time.

---

## 7️⃣ Swapping Elements

C++:
- Built-in `swap()` function

Dart:
- Manual swapping using a temporary variable

---

## 8️⃣ Passing by Reference

C++:
- Must explicitly use `&` to avoid copying

Dart:
- Objects are passed by reference automatically
- No need for special syntax

---

# ⚙️ Time Complexity Summary

| Operation | Complexity |
|------------|------------|
| Access by index | O(1) |
| Add at end | Amortized O(1) |
| Linear search | O(n) |
| Reverse | O(n) |
| XOR single number | O(n) |

---

# 🚀 Key Takeaways

1. Logic is language-independent.
2. Vector and List behave similarly for DSA.
3. Big-O ignores constants.
4. XOR is powerful for duplicate cancellation.
5. Two-pointer is a foundational problem-solving pattern.
6. Always analyze time and space complexity.
7. C++ requires explicit reference handling; Dart does not.

---

# 🧠 Mental Exercises for Reinforcement

1. Why does the XOR trick fail if elements appear three times?
2. Why is inserting at index 0 costly?
3. Why does doubling capacity prevent O(n²) insertion?
4. What edge cases should be tested for reverse?

---

# 📈 Progress Reflection – Day 25

Today strengthened:

- Dynamic array understanding
- Amortized analysis
- Bit manipulation pattern
- Linear scanning
- Two-pointer technique
- Big-O simplification

This was foundational reinforcement for advanced DSA problems.


**Day 25 Complete ✅**
