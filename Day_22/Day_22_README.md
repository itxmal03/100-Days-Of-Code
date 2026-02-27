# 📘 Day 22 – Bitwise Operators & Even/Odd Check (C++ and Dart)

**Date:** 11-Feb-2026   
**Track:** Progressive Problem Solving – Beginner to Advanced  

---

## 🎯 Objective of the Day

The goal of Day 22 was to deeply understand:

- Binary representation of numbers  
- Bitwise operators: AND (&), OR (|), XOR (^), Left Shift (<<), Right Shift (>>)  
- Checking even or odd using bitwise logic  
- Operator precedence issues  
- Difference between C++ and Dart behavior  

This day marks the beginning of **binary-level thinking**, which is essential for mastering DSA and competitive programming.

---

# 🧠 Core Concept – Computers Think in Binary

Computers do not directly understand numbers like 5, 10, or 100.

They understand:

0 and 1 (bits)

Whenever we apply a bitwise operator:

1. The number is converted to binary.
2. Operation is performed bit by bit.
3. Result is converted back to decimal.

Understanding this internal process removes fear and confusion.

---

# 🔢 Binary Refresher

Example:

5 in decimal → 0101 in binary  
3 in decimal → 0011 in binary  

Each bit position represents a power of 2:

- Rightmost → 2⁰  
- Next → 2¹  
- Next → 2²  
- Next → 2³  

Binary representation is simply expressing numbers using powers of 2.

---

# 🔹 Bitwise Operators Learned

## 1️⃣ AND (&)

### Rule:
Result is 1 only when both bits are 1.

Example:

5 → 0101  
3 → 0011  

Result → 0001  
Decimal → 1  

**Meaning:** AND keeps only the common set bits.

---

## 2️⃣ OR (|)

### Rule:
Result is 1 if at least one bit is 1.

Example:

5 → 0101  
3 → 0011  

Result → 0111  
Decimal → 7  

**Meaning:** OR combines all set bits.

---

## 3️⃣ XOR (^)

### Rule:
Result is 1 when bits are different.

Example:

5 → 0101  
3 → 0011  

Result → 0110  
Decimal → 6  

### Important XOR Properties:

- a ^ a = 0  
- a ^ 0 = a  
- XOR is reversible  

These properties are extremely powerful in problem solving.

---

## 4️⃣ Left Shift (<<)

### Concept:
Shifts bits to the left.

Each left shift multiplies the number by 2.

Mathematical relation:

a << b = a × (2^b)

Example:

3 << 3 = 24  
Because 3 × 8 = 24

**Meaning:** Fast multiplication by powers of 2.

---

## 5️⃣ Right Shift (>>)

### Concept:
Shifts bits to the right.

Each right shift divides the number by 2 (integer division).

Mathematical relation:

a >> b = a ÷ (2^b)

Example:

8 >> 2 = 2  

**Meaning:** Fast division by powers of 2.

---

# 🔍 Even or Odd Using Bitwise Operator

## Key Insight

The last binary bit determines parity:

- If last bit = 1 → number is odd  
- If last bit = 0 → number is even  

When we perform:

number & 1

We isolate the last bit.

Examples:

6 → 110  
6 & 1 → 0 → even  

5 → 101  
5 & 1 → 1 → odd  

This method is efficient and fundamental.

---

# ⚠ Important Learning – Operator Precedence

In C++, writing:

n & 1 == 1

may not behave as expected due to operator precedence.

Always use parentheses when mixing operators:

(n & 1) == 1

This prevents logical bugs.

---

# ⚠ C++ vs Dart Difference

## C++ Behavior

- 0 is treated as false  
- Any non-zero value is treated as true  
- Implicit conversion from int to bool is allowed  

Example reasoning:
If result is 1 → treated as true  
If result is 0 → treated as false  

---

## Dart Behavior

- Condition must be boolean  
- Integers are NOT automatically converted to boolean  
- Explicit comparison is required  

This strict typing prevents hidden bugs.

---

# 🧩 Patterns Learned

1. Binary representation thinking  
2. Using AND to isolate last bit  
3. XOR cancellation property  
4. Fast multiplication using left shift  
5. Fast division using right shift  
6. Understanding operator precedence  
7. Understanding type system differences i.e Different programming languages treat types differently, especially when it comes to booleans and integers.

---


# 🔑 Key Takeaways

- Bitwise operators manipulate individual bits.
- AND keeps common bits.
- OR merges bits.
- XOR keeps different bits.
- Left shift multiplies by powers of 2.
- Right shift divides by powers of 2.
- Last bit determines parity.
- Parentheses prevent precedence bugs.
- C++ allows implicit conversion.
- Dart enforces strict boolean conditions.
- Binary thinking is foundational for advanced DSA.

---

# 🚀 Progression

Day 22 builds foundation for:

- Power of 2 checking  
- Finding single non-repeating element  
- Bit masking  
- Subset generation using bits  
- Setting, clearing, toggling bits  
- Advanced competitive programming techniques  

---

## ✅ Day 22 Completed Successfully

Today you moved from decimal-level thinking to binary-level reasoning.
