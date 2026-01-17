# Day 7 — Sliding Window Practice (Subarrays)

## What I Worked On Today
Today I focused on **sliding window technique** and practiced three common subarray problems using logic (not brute force):

1. **Smallest subarray with sum ≥ target**
2. **Largest subarray with sum ≥ target**
3. **Largest subarray with sum = target**

The goal was not just to write code, but to **understand when to expand the window and when to shrink it**.

---

## Key Concept: Sliding Window
Sliding window works when:
- The array contains **non-negative numbers**
- We move two pointers:
  - `startIndex` → start of window
  - `currentIndex` → end of window

### Two operations:
- **Expand window** → add new element to sum
- **Shrink window** → remove element from start

---

## 1. Smallest Subarray (sum ≥ target)
### Logic
- Expand window until `sum ≥ target`
- Once condition is satisfied, **shrink from the start**
- Keep shrinking to get the **minimum possible length**
- Store the smallest length found

### Why shrinking is required
If the sum already satisfies the condition, removing elements may still keep it valid and give a **shorter subarray**, which is exactly what we want.

---

## 2. Largest Subarray (sum ≥ target)
### Logic
- Expand window normally
- Whenever `sum ≥ target`, update maximum length
- **Do not shrink**, because shrinking would reduce the length

### Key Insight
For “largest” problems:
- We **prefer longer windows**
- Shrinking is unnecessary unless explicitly required

---

## 3. Largest Subarray (sum = target)
### Logic
- Expand window and add elements to sum
- If `sum > target`, **shrink until sum ≤ target**
- If `sum == target`, update maximum length

### Important Rule
- Shrink only when `sum > target`
- Do NOT shrink when `sum == target`
  - Because removing elements may break equality
  - And we want the longest valid window

---

## Major Learning Moment Today
I initially thought shrinking should happen even when `sum == target`.

Then I realized:
- For **equal-to problems**, shrinking early can remove a valid longer solution
- Shrinking should happen **only when sum exceeds the target**

This clarified why:
- `>=` problems and `==` problems need **different window rules**

---

## Initialization Insight
- For **minimum length**, start with a very large value
- For **maximum length**, start with `0`
  - Because length can never be negative
  - `0` cleanly represents “not found yet”

---

## Constraints I Understood
Sliding window **only works correctly** when:
- All array elements are **non-negative**
- Otherwise, sum behavior becomes unpredictable

---

## Summary
✔ Learned correct expand/shrink rules  
✔ Understood difference between `>= target` and `== target`  
✔ Fixed logical mistakes, not syntax  
✔ Improved intuition instead of memorizing code  

---

## Day 7 Status
**Conceptual clarity improved.  
Sliding window logic finally makes sense.** ✅
