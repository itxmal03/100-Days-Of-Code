# Day 02 – Sorting Practice in C++ & Dart

## Overview

This project demonstrates sorting a list/array using **insertion sort logic** in C++ and Dart. It focuses on **understanding the logic**, practicing **manual swaps**, and observing **how data changes step by step**. Sorting is useful in real-life scenarios like arranging marks, salaries, or daily measurements.  
**Note:** Dart does not have arrays like C++; it uses **List**, which works similarly.

## Implementation

### 1. Manual Sorting (Insertion Sort)
- Loops through the array/list and moves each element to its correct position.
- Swapping can be done using:
  - **Temporary variable** (safe for all values)
  - **Arithmetic method** (works for small numbers, may overflow with very large integers)
- **Edge Cases:**
  - Already sorted array → inner loop runs very few times
  - Reverse-sorted array → inner loop runs maximum times
  - Duplicate values → handled correctly

### 2. Built-in Sorting (Dart)
- Use `list.sort()` to automatically sort in ascending order.
- Recommended for real projects when logic tracing is not required.

## Key Learning Points
- Practiced **insertion sort logic** and dry-run reasoning
- Understood **manual vs built-in methods**
- Learned **edge cases for sorting**
- Reinforced **habit of daily coding practice**
- Learned that **Dart uses List instead of arrays**

## Example Output

Original list:  
[2, 4, 1, 3, 6, 8, 7, 5, 0, 9]  

Sorted list:  
[0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

## Conclusion
This day’s practice **strengthens problem-solving and logic skills**, preparing for **dry-run questions and real-life scenarios**.  
Manual swaps help **understand the process**, while built-in functions help **write clean code efficiently**.  
Dart’s List makes array handling simpler while keeping the logic consistent with C++ arrays.
