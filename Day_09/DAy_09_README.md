# Day 9 – Removing Duplicates and Sorting a Matrix

**Date:** Day 9 of Progressive Problem Solving Project  
**Topic:** Remove duplicate numbers from a 3x3 matrix after sorting  
**Languages Practiced:** C++ and Dart  

---

## Objective

Today, the goal was to:

1. Flatten a 2D matrix into a 1D array.  
2. Sort the array using **Insertion Sort**.  
3. Identify and remove **duplicate numbers** by shifting elements.  
4. Fill remaining positions with `-1` to maintain the matrix size.  
5. Map the 1D array back to a 2D matrix.  

This exercise helped reinforce concepts of **array manipulation**, **sorting algorithms**, **duplicate handling**, and **logical array sizing**.

---

## Problem Description

Given a 3x3 matrix with possible duplicate elements:

**Input Matrix:**
1 2 3
3 4 5
5 6 6



We need to:

1. Sort all elements.  
2. Remove duplicates.  
3. Fill empty spaces with `-1`.  
4. Reconstruct the 3x3 matrix.

---

## Approach and Logic

### Step 1: Flatten the Matrix
- Convert the 3x3 matrix into a 1D array for easier processing.

**Flattened Array:**
[1, 2, 3, 3, 4, 5, 5, 6, 6]



### Step 2: Sort the Array
- Used **Insertion Sort** to sort the array in ascending order.  

**Sorted Array:**
[1, 2, 3, 3, 4, 5, 5, 6, 6]


### Step 3: Remove Duplicates
- Iterate through the sorted array.  
- If a duplicate is found (`current == previous`):  
  - Shift all elements after the duplicate **one position to the left**.  
  - Reduce **logical size** of array (`tempSize`).  
- This ensures **all duplicates are removed in-place**.

**After Removing Duplicates (logical size = 6):**
[1, 2, 3, 4, 5, 6, ?, ?, ?] // ? are leftover elements



### Step 4: Fill Remaining Slots
- Fill leftover positions with `-1` to maintain array length.

**Array after filling -1:**
[1, 2, 3, 4, 5, 6, -1, -1, -1]



### Step 5: Map Back to 3x3 Matrix
- Reconstruct the matrix using the modified 1D array.

**Final 3x3 Matrix:**
1 2 3
4 5 6
-1 -1 -1


---

## Key Concepts Learned

1. **Flattening 2D arrays** to simplify manipulation.  
2. **Insertion Sort** implementation in both C++ and Dart.  
3. **Duplicate removal** using element shifting and logical array size.  
4. Handling **leftover array elements** by filling with a placeholder (`-1`).  
5. Mapping a 1D array back into a 2D structure.  

---

## Languages Implemented

- **C++**: Full manual implementation with loops and array shifting.  
- **Dart**: Direct translation using Dart `List` and similar logic.

---

## Conclusion

Today’s exercise strengthened **array manipulation skills**, reinforced **logical thinking** for handling duplicates, and showed the importance of **tracking logical size** when modifying arrays.  

This will be useful for solving **real-life problems** where duplicates must be removed without changing the size of data structures.
