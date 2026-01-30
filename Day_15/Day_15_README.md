# Day 15: Problem Solving — Missing Number & Add One

## Overview

Today we focused on **two classic problems**:

1. **Finding a missing number** in a consecutive sequence.
2. **Adding 1 to a number stored in a list/vector**, handling carries.

We translated the original **C++ logic into Dart** while maintaining the **same programming style**, clarified all concepts, and fixed common mistakes.

---

## 1. Missing Number Problem

**Problem Statement:**

Given an array of size `n` containing numbers from `1` to `n+1` with **exactly one missing number**, find the missing number.

**Formula Used:**

- Sum of first `N` numbers:  

Sum = N * (N + 1) / 2


- Missing number = Total sum - sum of array elements

**Example:**

- Input: `[1, 2, 3, 5]`  
- Step 1: N = size + 1 = 5  
- Step 2: Exact sum = 1 + 2 + 3 + 4 + 5 = 15  
- Step 3: Array sum = 1 + 2 + 3 + 5 = 11  
- Step 4: Missing number = 15 - 11 = 4 ✅

**Key Notes:**

- Works only if:
  1. Numbers start from 1
  2. Numbers are consecutive
  3. Exactly **one number missing**
  4. No duplicates
- In C++ arrays decay to pointers → **must pass size explicitly**.  
- In Dart, **lists know their length**, so passing size is optional.

---

## 2. Add One to Number Stored in Vector/List

**Problem Statement:**

Given a number stored as digits in a vector/list, add 1 to it, handling carries.

**Algorithm Steps:**

1. Start from the **last element** (least significant digit).  
2. If digit = 9 → set it to 0 (carry continues).  
3. If digit < 9 → add 1, stop carry.  
4. If all digits were 9 → insert 1 at the beginning.

**Examples:**

- Input: `[9, 9, 9, 0]` → Output: `[9, 9, 9, 1]`  
- Input: `[9, 9, 9]` → Output: `[1, 0, 0, 0]`  

**Key Notes:**

- Dart lists are **reference types**, so changes reflect outside the function.  
- Printing without newline:
  - `stdout.write(x)` → like `cout << x;` in C++  
  - `print(x)` → always adds newline
- Removed `terminator` from Dart because it's Python-specific.

---

## 3. C++ vs Dart Differences

| Feature | C++ | Dart |
|---------|-----|------|
| Array size in function | Decays to pointer → must pass size | List knows `.length` |
| Passing by reference | `&` | Lists are reference types |
| Vector/List | `vector<int>` | `List<int>` |
| Insert at beginning | `v.insert(v.begin(), x)` | `v.insert(0, x)` |
| Printing without newline | `cout << x` | `stdout.write(x)` |
| Integer division | `/` | `~/` |

---

## 4. Common Mistakes & Fixes

1. **Missing number formula**  
   - Original C++ formula used `size*(size+1)/2` → only works if size = total numbers including missing  
   - Fixed: N = size + 1 → `(size + 1)*(size + 2)/2`

2. **Array decay in C++** → Always pass size

3. **AddOne algorithm**  
   - Original code had unnecessary nested conditions → simplified to clean carry logic

4. **Dart `print(..., terminator: "")`** → removed, replaced with `stdout.write()`

5. **Edge cases**  
   - All 9s → AddOne inserts 1 at the start  
   - Missing number at start or end → formula still works

---

## 5. Examples for Quick Reference

**Missing Number Examples:**

| Array           | Size | Missing Number |
|-----------------|------|----------------|
| `[1, 2, 3, 5]`  | 4    | 4              |
| `[1, 2, 4]`     | 3    | 3              |
| `[2, 3, 4]`     | 3    | 1              |

**Add One Examples:**

| Input          | Output       |
|----------------|-------------|
| `[9, 9, 9, 0]` | `[9, 9, 9, 1]` |
| `[1, 2, 3]`    | `[1, 2, 4]` |
| `[9, 9, 9]`    | `[1, 0, 0, 0]` |

---

## 6. Key Learnings

1. Verify **assumptions** when using formulas.  
2. Understand **array decay in C++ vs list behavior in Dart**.  
3. Loops can be translated **line by line** across languages.  
4. Use `stdout.write()` in Dart to simulate `cout` behavior.  
5. Always handle **edge cases**: all 9s, missing numbers at start/end.

---

**End of Day 15**
