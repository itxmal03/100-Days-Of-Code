# Day 16 – Celebrity Problem Analysis

**Date:** Day 16  
**Topic:** Celebrity Problem in C++ and Dart  

---

## Objective

The goal was to solve the **Celebrity Problem**, where we have a matrix representing `n` people at a party:

- `matrix[i][j] == 1` → person `i` knows person `j`  
- `matrix[i][j] == 0` → person `i` does not know person `j`  

A **celebrity** is defined as a person who:

1. **Everyone knows** (all other people know this person).  
2. **Knows no one** (does not know any other person).  

We implemented **two methods** to find the celebrity.

---

## Method 1: Brute-force Approach

**Idea:**

1. Check each person to see if they **know anyone**.  
   - If a person knows someone else, they **cannot be a celebrity**.  
   - If a person knows no one, they are a **potential candidate**.  
2. Verify that **everyone else knows this candidate**.  
   - If any person does not know the candidate, there is **no celebrity**.  

**Time Complexity:**  
- O(n²) because we check every person against every other person in the matrix.  

**Example Matrix:**

**Example Matrix:**

|   | 0 | 1 | 2 |
|---|---|---|---|
| 0 | 1 | 1 | 1 |
| 1 | 1 | 1 | 1 |
| 2 | 0 | 0 | 1 |



- Step 1 finds potential candidate (person 2).  
- Step 2 verifies that everyone knows person 2 → confirmed celebrity.

---

## Method 2: Optimized Approach (O(n))

**Idea:**

1. Assume the **first person (0)** is a candidate.  
2. Compare candidate with each other person:  
   - If candidate **knows person i**, candidate cannot be celebrity → update candidate to `i`.  
   - Otherwise, candidate remains.  
3. Verify the final candidate by checking:  
   - Candidate does **not know anyone else**.  
   - **Everyone knows candidate**.  

**Time Complexity:**  
- O(n) because we make a **single pass to find candidate** and another **pass to verify**.  

**Example Flow:**

- Candidate starts at 0.  
- Compare with 1 → update candidate if necessary.  
- Compare with 2 → update candidate if necessary.  
- Verify candidate 2 → confirmed celebrity.

---

## Key Observations

- **Method 1** is easy to understand but less efficient.  
- **Method 2** is optimal for larger `n`, with **linear time complexity**.  
- Both methods require careful handling of edge cases (e.g., no celebrity exists).  
- In Dart, using `bool` requires **initialization** due to null safety.  
- In C++, uninitialized `bool` can cause **undefined behavior**, so it is safer to initialize.  

---

## Summary

- Solved **Celebrity Problem** in **C++ and Dart**.  
- Implemented **brute-force O(n²)** and **optimized O(n)** approaches.  
- Learned best practices for variable initialization and verification.  
- Practiced translating logic between C++ and Dart.  

---


 ## Day 16 completed !

