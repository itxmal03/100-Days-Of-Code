# Day 4 – Sliding Window Practice 

## Objective

The goal of Day 4 is to strengthen problem-solving skills using sliding window techniques. By the end of this session, you should be able to:

- Understand sliding vs non-sliding windows  
- Solve fixed-size window problems  
- Solve variable-size window problems efficiently  

---

## Concept 1: Fixed-Size Groups of Elements

**Problem:**  
- Divide an array into groups of 3 elements  
- Sum each group  
- No overlap between groups  

**Example:**  

Array: [1, 2, 3, 4, 5, 6, 7, 8, 9, 0]

Sum of set 1: 6 // 1+2+3
Sum of set 2: 15 // 4+5+6
Sum of set 3: 24 // 7+8+9


**Key Points:**  
- Jump index by 3 each time (`i = i + 3`)  
- Simple iteration, no overlapping  

---

## Concept 2: Sliding Window of Fixed Size

**Problem:**  
- Sum 3 consecutive elements, allowing overlaps  
- Slide window forward by 1 element each time  

**Example:**  

Array: [1, 2, 3, 4, 5]

Sum of set 1: 6 // 1+2+3
Sum of set 2: 9 // 2+3+4
Sum of set 3: 12 // 3+4+5


**Key Points:**  
- Add new element to current sum  
- Track counter until window size reached  
- Print sum, reset sum, and slide window  

---

## Concept 3: Smallest Subarray with Sum ≥ Target

**Problem:**  
- Find smallest continuous subarray whose sum is ≥ a given target  

**Example:**  

Array: [1, 2, 3, 4, 5, 6]
Target sum: 7
Output: Length of smallest subarray = 2 // [3,4] or [4,3]


**Sliding Window Logic:**  

1. Initialize `windowSum = 0`, `minLength = large number`, `start = 0`  
2. Expand window by adding `array[end]`  
3. While `windowSum >= target`:  
   - Update `minLength = min(minLength, end-start+1)`  
   - Shrink window by subtracting `array[start]` and increment `start`  
4. Continue until end of array  
5. Print `minLength`  

**Key Points:**  
- Do not reset the sum — shrinking keeps continuity  
- Use a large initial value to track minimum (like INT_MAX in C++)  
- Time Complexity = O(n), Space Complexity = O(1)  

---

## Key Takeaways

- **Sliding Window = Expand + Shrink**  
  - Expand: Add new element to window  
  - Shrink: Remove left element when condition satisfied  

- **Fixed vs Variable Window:**  
  - Fixed: Always same size (e.g., sum of 3 elements)  
  - Variable: Size changes based on condition (e.g., sum ≥ target)  

- **Tracking Minimum:**  
  - Start with very large value (`list.length + 1` in Dart or INT_MAX in C++)  
  - Update whenever smaller length is found  

- **Language Notes:**  
  - Dart: `List<int>` and `list.length`  
  - C++: Arrays and `sizeof`  

---

## Recommended Practice

1. Try different array sizes and different targets  
2. Convert fixed window problems to sliding window problems  
3. Predict window size and sum manually before coding  
4. Analyze time and space complexity  

---

**End of Day 4 – Sliding Window Practice**
