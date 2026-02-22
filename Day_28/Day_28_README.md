# Day 28 – Pair Sum Problem (Two Sum)

**Date:** 22-Feb-2026   
**Topic:** Pair Sum / Two Sum problem in C++ and Dart

---

## Objective

The goal of today’s session was to solve the **Pair Sum Problem**, which is:

> Given an array and a target sum, find indices of **two numbers** that add up to the target.

We implemented three approaches:

1. Brute Force (efficient brute)  
2. Brute Force 2 (checks all pairs including duplicates)  
3. Optimal Two Pointer (works for sorted arrays)

We also translated the solution from C++ to Dart and learned differences in memory handling and syntax.

---

## Concepts Learned

### 1. Brute Force Approach

**Logic:**

- Check every element with every other element.
- If sum matches target, return the pair of indices.
- Time Complexity: O(n²)
- Works for unsorted arrays.

**Key Points:**

- Loop from `i = 0 to n-1`
- Inner loop from `j = i+1 to n-1`
- Only first valid pair is returned.
- Safe return when no pair exists: `[-1, -1]`.

**C++ vs Dart Differences:**

| Concept | C++ | Dart |
|---------|-----|------|
| Array | int* arr | List<int> arr |
| Size | Passed manually | arr.length |
| Return container | vector<int> | List<int> |
| Memory safety | Must initialize vector size | Dart auto-handles memory |

---

### 2. Brute Force 2 Approach

**Logic:**

- Check **all pairs** `(i,j)` including duplicates.
- Avoid pairing same element with itself using `i != j`.
- Slightly less efficient: does unnecessary duplicate comparisons.
- Time Complexity: O(n²)

**Note:** Works correctly, but the first brute force is cleaner and preferred.

---

### 3. Optimal Two Pointer Approach (Sorted Array)

**Logic:**

- Works only if array is sorted.
- Initialize two pointers:
  - `i = 0` (smallest)
  - `j = n-1` (largest)
- While `i < j`:
  - If `arr[i] + arr[j] > target`, decrease `j`
  - If `arr[i] + arr[j] < target`, increase `i`
  - If `arr[i] + arr[j] == target`, return `[i, j]`
- Time Complexity: O(n)

**Advantages:**

- Checks **all possible pairs efficiently**.
- Works with duplicates.
- Returns `[-1, -1]` if no pair exists.

---

## Edge Cases Considered

1. **No pair exists** → return `[-1, -1]`  
2. **Array with duplicate numbers** → two-pointer still works  
3. **Unsorted array** → brute force only  
4. **Sorted array** → two-pointer is optimal

---

## C++ vs Dart Key Differences

| Feature | C++ | Dart |
|---------|-----|------|
| Arrays | `int arr[]` or `int* arr` | `List<int>` |
| Vector/List Initialization | Must provide size before using `[]` | Lists are dynamic, no pre-size needed |
| Return Type | `vector<int>` | `List<int>` |
| Memory Safety | Out-of-bounds access can crash | Dart handles memory safely |

**Important:** In C++, accessing `ans[0]` on an empty vector causes undefined behavior. In Dart, `List` handles dynamic resizing safely.

---

## Sample Input & Output

**Example:**   
Input (unsorted): [3, 5, 2, 1, 9, 0], target = 10
Output: [3, 4] → 1 + 9 = 10

Input (sorted): [1, 3, 5, 7, 9], target = 14
Output: [2, 4] → 5 + 9 = 14    


---

## Summary of Approaches

| Approach | Works for | Time Complexity | Space Complexity | Notes |
|----------|-----------|----------------|-----------------|-------|
| Brute Force | Unsorted | O(n²) | O(1) | Cleanest brute solution |
| Brute Force 2 | Unsorted | O(n²) | O(1) | Checks duplicates unnecessarily |
| Two Pointer | Sorted | O(n) | O(1) | Optimal for sorted arrays, handles duplicates |

---

## Key Takeaways

1. **Correctness first, optimization later.**  
   - Even O(n) logic fails if not correct for all pairs.
2. **Two Pointer technique is powerful** for sorted arrays.  
   - Smart movement avoids checking every pair.
3. **Defensive programming:**  
   - Always return `[-1, -1]` if no pair exists.
4. **Language awareness:**  
   - Dart handles dynamic memory safely.  
   - C++ requires careful vector initialization.
5. **Edge case thinking** is essential in interviews and coding tests.

---


This concludes **Day 28 – Pair Sum Problem**. ✅