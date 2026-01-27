# Day 14 — Logic-Focused

## Goal
The goal of Day 14 was **not just writing code**, but to:
- Understand the **logic behind each function**
- Translate the **same logic from C++ to Dart**
- Learn **new Dart concepts** without breaking already-learned reasoning

This README explains:
- What each function does
- How it works logically
- Key **differences between C++ and Dart**
- Any **new concepts** introduced in Dart

---

## Problems Covered

1. Swap two numbers  
2. Odd / Even check using bitwise operator  
3. Check if a string contains a digit  
4. Convert an array into **wave form**

---

## 1️⃣ Swap Two Numbers

### Concept
Swap two values using **one line**, without a temporary variable.

### Logic Used
Arithmetic swap:
a = (a + b) - (b = a)


### Important Concept (Same in C++ & Dart)
- Function parameters are passed **by value**
- Only local copies are swapped
- Original variables remain unchanged

### Learning Point
> A function can be logically correct but still useless if values are passed by value.

---

## 2️⃣ Odd / Even Using Bitwise Operator

### Logic (Language Independent)
- Every number is stored in binary
- The **last bit** decides:
  - `1` → odd
  - `0` → even

### Condition Used
n & 1


### C++ vs Dart Comparison

| Feature | C++ | Dart |
|------|----|----|
| Bitwise AND | `n & 1` | `n & 1` |
| Condition check | implicit | explicit `(n & 1) == 1` |

### Learning Point
> Bitwise operators behave **exactly the same** in both languages.

---

## 3️⃣ Check if String Contains a Digit

### Problem Definition
- Check whether a string contains **at least one digit**
- Stop checking as soon as a digit is found (efficient)

---

### C++ Method
Uses:
isdigit(c)


---

### Dart Difference ❗ (New Concept)
Dart does **NOT** have `isdigit()`.

### Dart Solution Used
c.codeUnitAt(0)


### Logic Behind `codeUnitAt`
- Converts a character into its ASCII/Unicode value
- Digits lie between:
'0' → 48
'9' → 57


### Learning Point
> Dart requires manual character checks, but the **logic remains identical**.

---

## 4️⃣ Wave Array (Main Problem)

### Definition of Wave Array
a0 > a1 < a2 > a3 < a4 ...


---

## Method 1 — Local Wave Fixing (⚠️ Not Guaranteed)

### Idea
- Fix local violations by comparing neighbors
- Does NOT reorder entire array

### Limitation
- Works only for specific inputs
- No global guarantee of correct wave pattern

### Status
❌ Input dependent  
❌ Not reliable for all cases

---

## Method 2 — Guaranteed Wave Construction ✅

### Steps
1. Sort the array
2. Swap adjacent elements

### Why This Works
- Sorting establishes order
- Pairwise swapping guarantees wave pattern for **any input**

---

## Sorting Technique Used
**Insertion Sort**

### Reason
- Simple and understandable
- Previously learned logic
- Suitable for small arrays

### Time Complexity
O(n²)


---

## C++ vs Dart — Wave Array Differences

| Concept | C++ | Dart |
|------|----|----|
| Array type | `int arr[8]` | `List<int>` |
| Size | Fixed | Dynamic |
| Passing | By value | By reference |
| Swap | `swap(a,b)` | Manual temp variable |
| Printing | loop + `cout` | `join()` |

---

## New Dart Concept Introduced ⭐

### `join()`

print(array.join(" "));


### What It Does
- Converts list elements into a **single string**
- Inserts a separator between elements

### Example
[2, 1, 3].join(" ")


Output:
2 1 3


### Why It’s Useful
- Removes need for loops
- Cleaner and readable
- Automatically converts integers to strings

---

## Key Conceptual Learnings (IMPORTANT)

- Logic is **language independent**
- Syntax changes, thinking does not
- Some C++ utilities don’t exist in Dart
- Dart provides cleaner alternatives
- Always distinguish:
  - **Guaranteed algorithms**
  - **Input-dependent fixes**

---

## Day 14 Outcome ✅

By the end of Day 14:
- Logic was successfully translated from C++ to Dart
- Unsafe approaches were identified
- New Dart concepts were learned correctly
- Array manipulation and bitwise logic improved

---

📌 **Rule Followed:**  
Logic first → language second → optimization later