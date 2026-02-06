# Day 19 – Prime Number Problem Analysis

**Date:** Day 19  
**Topic:** Prime Number Check in C++ and Dart (Day 1 of DSA Playlist)  

---

## Objective

The goal was to solve the **Prime Number Problem**, where we want to determine if a given number `n` is prime:

- A number is **prime** if it is **greater than 1** and has **exactly two divisors**: 1 and itself.  
- For example:  
  - Prime numbers → 2, 3, 5, 7, 11  
  - Non-prime numbers → 0, 1, 4, 6, 9  

Instead of solving random problems, we **officially started following the DSA playlist by Ma’am Shradha Khapra**, marking **Day 1** of this structured DSA journey.

---

## Method 1: C++ Implementation

**Idea:**

1. Check if `n` is less than or equal to 1 → not prime.  
2. Loop from `i = 2` to `i * i <= n` and check:  
   - If `n % i == 0`, then `n` is **not prime**.  
   - Otherwise, `n` remains **potentially prime**.  
3. Print result accordingly.

**Time Complexity:**  
- O(√n) because we only check divisors up to √n.  

**Edge Cases:**

- `n = 0` or `n = 1` → not prime  
- `n = 2` → prime (loop does not run)  
- Negative numbers → not prime

---

## Method 2: Dart Implementation

**Idea:**  

1. Same logic as C++ implementation.  
2. Use Dart's `print()` function instead of `cout`.  
3. Initialize `bool isPrime = true;` to follow Dart’s null safety.  
4. Loop from `i = 2` to `i * i <= n` and check divisibility using `%`.

**Example Flow:**

- `n = 5` → no divisors found → prime  
- `n = 9` → divisible by 3 → not prime  
- `n = 2` → loop skipped → prime

**Time Complexity:**  
- O(√n) same as C++ version.  

---

## Key Observations

- Always check for `n <= 1` first.  
- `%` operator is used to check divisibility.  
- Looping up to √n is an **optimization** over looping up to `n-1`.  
- Both C++ and Dart implementations use the **same logical approach**, only syntax differs.  
- Understanding the logic is more important than memorizing syntax.  

---

## Summary

- Solved **Prime Number Problem** in **C++ and Dart**.  
- Learned to **analyze a problem step by step** before coding.  
- Learned to handle **edge cases** correctly.  
- Practiced **translating the same logic across languages**.  
- Officially **started DSA playlist by Ma’am Shradha Khapra**, marking Day 1 of this structured journey.

---

## Day 19 completed !  
