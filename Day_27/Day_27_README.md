# 📘 Day 27 – Kadane’s Algorithm (Maximum Subarray Problem)

**Date:** 21-Feb-2026    
**Topic:** Kadane’s Algorithm  
**Languages Practiced:** C++ and Dart  
**Learning Source:** Shradha Khapra (Apna College)

---

## 🎯 Objective

The goal of Day 27 was to deeply understand and implement **Kadane’s Algorithm**, which solves the:

> Maximum Sum Contiguous Subarray Problem

Focus areas:

- Understanding the problem clearly
- Solving using brute force first
- Discovering the optimization insight
- Handling edge cases properly
- Comparing C++ and Dart logic
- Analyzing time and space complexity

---

# 🧠 Problem Understanding

## 🔎 Problem Statement

Given an integer array, find the **maximum possible sum** of any **contiguous subarray**.

### ❗ Important Term: Contiguous

Contiguous means elements must be adjacent (next to each other).

Example array:

1, -2, 4, 5, 6, -9

Possible contiguous subarrays:

- 1  
- 1, -2  
- 4  
- 4, 5  
- 4, 5, 6  
- 5, 6  

The maximum sum contiguous subarray is:

4, 5, 6  

Sum = 15  

Final Answer = 15

---

# 🪜 Step 1 – Brute Force Approach (Beginner Thinking)

## 💡 Logic

1. Pick every index as a starting point.
2. Extend the subarray forward.
3. Calculate the sum.
4. Keep track of the maximum sum found.

## ⏱ Time Complexity

If array size = n:

- n starting points
- For each start, up to n extensions

Time Complexity = O(n²)

Correct but inefficient.

---

# 🚀 Step 2 – Optimization Insight

Key observation:

If the current running sum becomes negative, it will reduce the sum of any future subarray.

Example:

Current sum = -5  
Next element = 10  

Option 1: -5 + 10 = 5  
Option 2: Start fresh from 10  

Clearly, starting fresh is better.

---

# 💡 Core Idea of Kadane’s Algorithm

At every index, decide:

- Extend the previous subarray  
OR  
- Start a new subarray from the current element  

If current sum becomes negative → reset it to 0.

This reduces complexity from O(n²) to O(n).

---

# 🧮 Mathematical Form (Advanced Understanding)

At index i:

CurrentSum(i) = max(array[i], array[i] + CurrentSum(i-1))

This is a 1D Dynamic Programming transition.

---

# 🧱 Structured Algorithm Steps

1. Initialize:
   - currentSum
   - maxSum

2. Traverse the array once.

3. Add current element to currentSum.

4. Update maxSum.

5. If currentSum < 0 → reset to 0.

6. Return maxSum.

---

# 🧪 Dry Run Example

Array:

1, -2, 4, 5, 6, -9

| Index | Element | Current Sum | Max Sum |
|--------|----------|-------------|----------|
| 0 | 1 | 1 | 1 |
| 1 | -2 | -1 → reset to 0 | 1 |
| 2 | 4 | 4 | 4 |
| 3 | 5 | 9 | 9 |
| 4 | 6 | 15 | 15 |
| 5 | -9 | 6 | 15 |

Final Answer = 15

---

# ⚠️ Important Edge Cases

## 1️⃣ All Negative Numbers

Example:

-5, -2, -8

Correct Answer = -2

This is why maxSum must be initialized properly (first element or minimum integer).

---

## 2️⃣ Single Element Array

Example:

[7]

Answer = 7

Algorithm must handle this correctly.

---

## 3️⃣ Empty Array

If array size = 0:

Possible approaches:

- Return 0
- Throw an error
- Handle explicitly

Always validate input.

---

## 4️⃣ Large Negative Prefix

Example:

-10, -5, 3, 4

Correct subarray:

3, 4  
Sum = 7

Algorithm ignores negative prefix automatically.

---

# 🔄 C++ vs Dart – Conceptual Differences

| Concept | C++ | Dart |
|----------|------|------|
| Data Structure | Fixed size array | List |
| Minimum Integer | INT_MIN | Use first element or manual value |
| Max Function | From algorithm header | From dart:math |
| Memory Handling | Manual control | Managed by runtime |

Logic remains identical. Only syntax differs.

---

# ⏱ Time and Space Complexity

Time Complexity: O(n)  
Space Complexity: O(1)

Why?

- Single loop traversal
- Only two variables used

This is optimal.

---

# 🧠 Pattern Learned

- Running Sum Pattern
- Reset Pattern
- Greedy Decision
- 1D Dynamic Programming Optimization

This pattern appears in:

- Stock profit problems
- Maximum circular subarray
- 2D maximum submatrix sum
- Many interview problems

---

# 🎓 Key Takeaways

- Always understand brute force first.
- Optimization comes from observation.
- Negative running sums are harmful in accumulation problems.
- Edge cases determine correctness.
- Kadane reduces O(n²) → O(n).
- This is your first dynamic programming mindset shift.

---

# 🧩 Mental Exercises

1. Why must maxSum be updated before resetting currentSum?
2. Can we modify this to return the actual subarray?
3. How would this work for circular arrays?
4. What changes if we want minimum subarray sum?

Think deeply before coding.

---

# 🚀 Progress Note

Day 27 marks a major milestone:

Moved from:

Basic loops → Optimization thinking → Pattern recognition.

Next Levels:

- Return the actual subarray
- Maximum Circular Subarray
- 2D Kadane (Advanced)
- Formal Dynamic Programming explanation

---

**End of Day 27**  
Progressive Problem Solving Journey Continues 🔥