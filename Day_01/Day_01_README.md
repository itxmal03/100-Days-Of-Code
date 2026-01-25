# Day_01: Relative Speed Problem

## Problem Statement

Two people (or objects) are moving along a straight path. The goal is to calculate **when they will meet** based on:

- Their **speeds** (in meters per second)  
- The **distance** between them (in meters)  
- The **direction of motion** (towards each other or in the same direction)

The program should handle **dynamic input** and **edge cases**, such as:

- Both moving at the same speed in the same direction → they will never meet  
- Moving towards each other → they will meet if relative speed is greater than zero  

---

## Inputs

1. Speed of the first person  
2. Speed of the second person  
3. Distance between them  
4. Direction of motion:  
   - 1 → Moving towards each other  
   - 2 → Moving in the same direction  

---

## Approach / How I Solved It

1. **Identify the direction**:
   - **Towards each other:** The distance decreases at a rate equal to the **sum of their speeds**.  
   - **Same direction:** The distance changes at a rate equal to the **difference of their speeds**.  

2. **Handle edge cases**:
   - If the **relative speed is zero**, the distance never changes → they will never meet.  
   - If the **distance is zero**, they are already together → time = 0.

3. **Calculate meeting time**:
   - **Formula:** `time = distance / relative speed`  
   - For same-direction motion, the relative speed must always be **positive** to avoid negative time.

---

## Handling Absolute Values in Different Languages

- **Dart:**  
  - Used `(speed1 - speed2).abs()` to calculate the **absolute difference of speeds** when moving in the same direction.  
  - The `abs()` method is a **function of the number itself** (double or int), which ensures the result is always positive.  

- **C++:**  
  - Used `fabs(speed1 - speed2)` from the `<cmath>` library.  
  - `fabs()` stands for **floating absolute**, and it converts negative differences into positive numbers, preventing negative time calculations.  

> Both ensure the **relative speed is always positive** when calculating time for same-direction motion.

---

## Examples / Understanding

1. **Moving Towards Each Other:**  
   - Speeds: 4 m/s and 6 m/s, distance = 100 m  
   - Relative speed = 4 + 6 = 10 m/s  
   - Time to meet = 100 / 10 = 10 seconds  

2. **Same Direction, Faster Behind:**  
   - Speeds: 8 m/s and 5 m/s, distance = 100 m  
   - Relative speed = |8 - 5| = 3 m/s  
   - Time to meet = 100 / 3 ≈ 33.3 seconds  

3. **Same Direction, Equal Speeds:**  
   - Speeds: 5 m/s and 5 m/s, distance = 50 m  
   - Relative speed = |5 - 5| = 0  
   - Result: They will never meet  

---

## Key Learnings

1. **Relative speed** is the rate at which the distance between two objects changes.  
2. **Towards each other:** Add speeds.  
3. **Same direction:** Use **absolute difference of speeds**.  
4. **Edge cases:** Zero relative speed → never meet.  
5. **Time calculation formula:** `time = distance / relative speed`.  
6. Always ensure **output is clear and readable**.

---

## Notes

- For same-direction motion, this program assumes the **faster person is behind**.  
- Distance and speed should be **positive numbers**.  
- This approach works for **people, cars, trains, or any moving objects** along a straight path.  
- Understanding `abs()` in Dart and `fabs()` in C++ is **crucial for correct time calculation** in same-direction problems.
