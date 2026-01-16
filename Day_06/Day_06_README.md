# Day 6 – Move Zeros to End (Problem Solving Focus)

## 📌 Problem Statement
Given an array of integers, move all `0` values to the **end of the array** while:
- Keeping the **relative order of non-zero elements**
- Modifying the **same array (in-place)**
- Using **no extra array**

### Example
Input:
[1, 0, 2, 0, 4, 0, 9]

Output:
[1, 2, 4, 9, 0, 0, 0]

---

## 🎯 Learning Objectives
- Learn how to **approach array rearrangement problems**
- Compare a **naive solution vs optimized solution**
- Understand the **two-pointer technique**
- Focus on **logic and thinking**, not language syntax

---

## 🧠 Method 1 – Repeated Swapping (Beginner Approach)

### Core Idea
- Traverse the array multiple times
- Whenever a `0` is found, swap it with the next element
- Gradually, zeros move toward the end

### Intuition
Zeros behave like **bubbles in water**  
They move one step at a time until they reach the end.

### Characteristics
- Uses repeated swaps
- Requires nested looping
- Works correctly but inefficient

### Performance
- Time Complexity: O(n²)
- Space Complexity: O(1)

### Key Observation
This method **wastes operations** because the same elements are moved again and again.

---

## 🚀 Method 2 – Two Pointer Technique (Optimized Approach)

### Core Idea
- Use two pointers:
  - One pointer scans the array
  - One pointer tracks the next position for a non-zero value
- When a non-zero is found:
  - Place it immediately at the correct position
  - Move the position pointer forward

### Real-Life Analogy
Imagine a bus with reserved seats:
- Non-zero values are valid passengers
- Zero values wait outside
- Seats are filled in order without reshuffling passengers

### Why This Works Better
- Each element is handled only once
- No unnecessary shifting
- Order of non-zero elements remains intact

### Performance
- Time Complexity: O(n)
- Space Complexity: O(1)

---

## 🔍 Method Comparison

| Aspect | Method 1 | Method 2 |
|-----|--------|--------|
| Approach | Step-by-step shifting | Position tracking |
| Loops | Nested | Single |
| Efficiency | Slow | Fast |
| Order Preserved | Yes | Yes |
| Interview Use | ❌ | ✅ |

---

## ⚠️ Important Edge Cases
- Array with all zeros
- Array with no zeros
- Zeros already at the end
- Single-element array

Both approaches handle these cases, but **Method 2 does so efficiently**.

---

## 🧩 Key Takeaways (Day 6)
- Always analyze **what is moving unnecessarily**
- Prefer **tracking positions over repeated swapping**
- Two-pointer technique is reusable in many problems
- Logic remains the same across all programming languages

---

## 🔜 What Comes Next (Day 7)
- Partitioning arrays based on conditions
- Moving negatives and positives
- Order-sensitive vs order-insensitive problems
- Building interview-level intuition

---

### ✅ Day 6 Status
Problem understood ✔  
Logic analyzed ✔  
Optimized thinking achieved ✔  
Ready to level up ✔
