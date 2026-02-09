# Day 11 – Programming Fundamentals Practice & PF Final Exam

Today was an excellent day. I practiced important Programming Fundamentals concepts and also appeared in my **PF Final Paper of 1st Semester**, which went very well. The paper felt easy and confidence was high due to consistent daily practice.

## What I Practiced Today
- 2D arrays (matrices)
- Matrix transpose
- Identity matrix logic
- Applying the **same logic** in C++ and Dart without changing algorithms
- Understanding syntax-level differences between C++ and Dart

## 2D Matrix Work
I worked with 3×3 matrices using nested loops. The focus was on understanding how rows and columns are accessed and how loop control defines matrix traversal.

## Identity Matrix Understanding
An identity matrix follows two strict rules:
- All diagonal elements (where row index equals column index) must be `1`
- All non-diagonal elements must be `0`

The logic checks every element:
- If `i == j`, value must be `1`
- If `i != j`, value must be `0`

This logic stays the same in every language.

## Matrix Initialization Difference (C++ vs Dart)

In C++, a 2D matrix can be initialized simply:
`int matrix[3][3] = {0};`

In Dart, the same 3×3 matrix is created using:
`List<List<int>> matrix = List.generate(3, (_) => List.filled(3, 0));`

Here, `List.generate(3, ...)` runs three times to create three rows.  
Each time, `List.filled(3, 0)` creates a row of three zeros.  
This results in a safe and independent 3×3 matrix.

## Integer Division Difference

In C++:
`tempNum = tempNum / 10;`  
This performs integer division when both operands are integers.

In Dart:
`tempNum = tempNum ~/ 10;`  
The `~/` operator is used because `/` returns a double in Dart.  
`~/` ensures the result remains an integer, which is required in logic-based problems.

## Logic vs Language
- Nested loops work the same way in C++ and Dart
- Conditions and algorithms do not change
- Only syntax changes
This reinforced the idea that **logic matters more than the programming language**.

## PF Final Exam Reflection (1st Semester)
- Exam went very smoothly
- Concepts were clear due to regular practice
- Matrix, array, and logic questions were easy
- Confidence remained strong throughout the paper

## What I Learned Today
- Strong fundamentals make exams easy
- One logical solution can work in multiple languages
- C++ and Dart differ in syntax, not in thinking
- Consistency builds confidence

## Status
Day 11 successfully completed  
PF Final Exam of 1st Semester completed with confidence  
Momentum maintained and learning continues
