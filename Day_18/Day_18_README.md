# Day 18 – Array Patterns & Adjacent Comparison

**Date:** 3-Feb-2026

---

## Objective

The goal of Day 18 was to **strengthen array problem-solving skills** using **adjacent comparisons** and related patterns. By the end of today, you should be able to:

- Identify and apply **adjacent comparison patterns** in arrays.  
- Check **absolute differences** between consecutive elements.  
- Determine whether an array is **alternating**.  
- Count **local peaks and valleys**.  
- Reason about array patterns **before coding**.  
- Translate these concepts **between C++ and Dart** confidently.

---

## Concepts Learned

### 1. Adjacent Comparison Pattern
- **Definition:** Compare each element only with its **immediate neighbors** rather than all elements.  
- **Why it matters:** Simplifies logic, reduces unnecessary comparisons, and allows **linear-time solutions** for many array problems.  
- **Applications:**  
  - Checking if an array is sorted or strictly increasing.  
  - Detecting alternating sequences.  
  - Counting peaks and valleys.

- **Language Notes:**  
  - **C++:** Use array indexing with `arr[i]` and `arr[i+1]`. Loops often use `size - 1` as the upper bound.  
  - **Dart:** Use `List<int>` with `.length` for size. Access elements with `array[i]`. Behavior is almost identical to C++, but `abs()` comes from `dart:math`.

- **Time Complexity:** O(n)  
- **Space Complexity:** O(1)

---

### 2. Absolute Difference Check
- **Pattern:** Check `abs(arr[i] - arr[i+1])` for each pair of consecutive elements.  
- **Use case:** Determine if differences are consistent (e.g., always 1).  
- **Behavior in Languages:**  
  - **C++:** Use `fabs()` for absolute values (works for both integers and floating points).  
  - **Dart:** Use `(array[i] - array[i+1]).abs()` from `dart:math`.  
- **Time Complexity:** O(n)  
- **Space Complexity:** O(1)

---

### 3. Alternating Arrays
- **Definition:** An array is alternating if each internal element (from index 1 to `size-2`) is either:  
  - A **local maximum** (greater than both neighbors)  
  - OR a **local minimum** (smaller than both neighbors)  

- **Pattern:** Loop through elements and check neighbors to verify alternating property.  

- **Language Notes:**  
  - **C++:** Use `for(int i = 1; i < size - 1; i++)` and logical operators.  
  - **Dart:** Use `for(int i = 1; i < array.length - 1; i++)` and the same logical conditions.  

- **Time Complexity:** O(n)  
- **Space Complexity:** O(1)

---

### 4. Peaks and Valleys
- **Peak:** Element greater than both neighbors.  
- **Valley:** Element smaller than both neighbors.  
- **Pattern:** Loop through the array, check each element’s neighbors, increment counters for peaks and valleys.  

- **Language Notes:**  
  - **C++:** Maintain integer counters for peaks and valleys. Print using `cout`.  
  - **Dart:** Maintain integer counters, print using `print()`. Indexing logic is identical.  

- **Applications:**  
  - Signal processing  
  - Stock price highs/lows  
  - Preparing alternating sequences  

- **Time Complexity:** O(n)  
- **Space Complexity:** O(1)

---

## Patterns / Techniques Applied

1. **Brute-force adjacent comparison:**  
   - Only compare neighboring elements to reduce unnecessary work.

2. **Early termination with flags:**  
   - Stop iteration as soon as a condition fails. Saves time in larger arrays.

3. **Counting pattern:**  
   - Use counters for peaks and valleys in a single pass.  
   - Avoids additional loops or storage.

4. **Cross-language translation:**  
   - Most array logic can be applied identically in Dart with minimal syntax changes.  
   - Main differences are in function names (`fabs()` vs `.abs()`) and array length access (`size` vs `.length`).

---

## Key Takeaways

- **Adjacent comparisons** are a fundamental array pattern.  
- **Single-pass logic** can replace nested loops for efficiency.  
- Boolean flags and counters are simple yet powerful.  
- Understanding **peaks, valleys, and alternating sequences** prepares you for intermediate array challenges.  
- Translation between **C++ and Dart** is straightforward with minor syntax adjustments.

---

## Mental Exercises

1. Given `[1, 2, 1, 2, 1]`, predict peaks and valleys without coding.  
2. Check if `[3, 4, 5, 6]` is alternating and explain why.  
3. Think of real-world scenarios for detecting peaks and valleys (e.g., stock prices, temperature changes).  
4. Convert a small C++ function for adjacent difference into Dart manually to practice cross-language thinking.

