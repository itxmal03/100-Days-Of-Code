# Day 17 – Array Patterns and Brute Force Techniques

**Date:** Day 17  
**Topic:** Adjacent Comparison, Strict vs Non-Strict Order, Brute Force Pair Sum

---

## Objective

The goal of Day 17 was to strengthen **problem-solving patterns** using arrays rather than solving random problems.  
By the end of the day, you should be able to:

1. Recognize and apply **adjacent comparison patterns**.  
2. Understand **strictly increasing vs non-strictly increasing** definitions.  
3. Implement **brute force pair sum checking**.  
4. Apply **early stopping / break patterns** to improve efficiency.

---

## Key Concepts Learned

### 1. Adjacent Comparison Pattern

- Many array problems can be solved by comparing **adjacent elements** instead of every element with every other element.  
- **Typical use cases:**  
  - Checking if an array is sorted in ascending order.  
  - Checking if an array is strictly increasing.  
- **Rule:** Compare `arr[i]` with `arr[i + 1]` and stop when the order is violated.  

---

### 2. Strictly Increasing vs Non-Strictly Increasing

- **Non-Strictly Increasing (Sorted):**  
  - Allowed to have equal adjacent elements.  
  - Example: `[2, 3, 4, 4, 6]` → considered sorted.  
- **Strictly Increasing:**  
  - No equal adjacent elements allowed.  
  - Example: `[2, 3, 4, 4, 6]` → **not strictly increasing**.  
- **Memory Tip:**  
  - “Strictly” always means **no equality allowed**.  
  - Always use `<` instead of `<=` for strictly increasing checks.

---

### 3. Brute Force Pair Sum Pattern

- **Problem:** Check if any two different elements in an array sum to a target value.  
- **Approach:**  
  1. Loop through each element.  
  2. Compare it with every other element.  
  3. Stop early when a valid pair is found.  
- **Key Notes:**  
  - Ensure the same element is not used twice.  
  - Early stopping prevents unnecessary checks once the pair is found.  
- **Time Complexity:** O(n²)  
- **Space Complexity:** O(1)  

---

### 4. Early Stopping / Break Pattern

- **Concept:** Stop iteration as soon as the answer is known instead of continuing unnecessarily.  
- **Examples:**  
  - In sorted or strictly increasing checks, break immediately when order is violated.  
  - In pair sum checking, break inner loop when a valid pair is found, and optionally break outer loop too.  
- **Benefit:** Reduces unnecessary computation while keeping logic simple.

---

## Patterns Reinforced

| Pattern | Description | Example Use Case |
|---------|-------------|----------------|
| Adjacent Comparison | Compare consecutive elements to check order | Sorted array, strictly increasing |
| Brute Force Pairs | Check all possible pairs in array | Pair sum problem |
| Early Stopping | Stop loops as soon as the result is determined | All three problems above |

---

## Key Takeaways

1. **Logic before code:** Always reason out the pattern and conditions before writing code.  
2. **Definitions control conditions:** Strict vs non-strict changes the comparison operator.  
3. **Pattern reuse:** Adjacent comparison and early stopping are foundational; they appear in sorting, subsequence problems, and array checks.  
4. **Confidence building:** Once patterns are recognized, brute force problems become manageable and less intimidating.  

---

**Day 17 Mental Win ✅**

- Pattern-based thinking adopted.  
- Brute force mindset trained.  
- Strict vs non-strict logic fully understood.  
- Adjacent comparison and early stopping internalized.  
