# Day 31 – Moore’s Voting Algorithm (Majority Element)

## 📅 Date 01-Mar-2026   
Day 31 of Daily Problem Solving Journey

---

# 🎯 Objective

To understand and implement an optimal algorithm to find the **Majority Element** in an array using Moore’s Voting Algorithm.

We focused on:

- Understanding the problem deeply
- Building intuition before coding
- Learning candidate elimination logic
- Comparing guaranteed vs non-guaranteed majority cases
- Analyzing time and space complexity

---

# 📌 Problem Statement

Given an array of integers:

- A **majority element** is an element that appears **more than n/2 times** in an array of size n.
- If such an element exists, return it.
- If it does not exist, return -1.

---

# 🧠 Step 1 – Understanding the Problem (Beginner Level)

If the size of array = n  
Then majority element must appear strictly more than:

n / 2 times

Example:

If n = 5  
Then majority must appear at least 3 times.

Why?

Because more than half means strictly greater than n/2.

---

# 💡 Core Idea – Pairwise Cancellation Logic

Moore’s Voting Algorithm works on this idea:

- Same element → increase frequency
- Different element → decrease frequency
- If frequency becomes 0 → choose new candidate

This works because:

If an element appears more than half the time,
it cannot be completely cancelled out by other elements.

This is called:

**Candidate Elimination Technique**

---

# 🪄 Intuition Behind Why It Works

Assume:

- Majority element appears x times
- All other elements together appear y times
- Total elements = x + y

For majority:
x > n/2  
Which implies:
x > y

When cancellation happens:

Each different element cancels one majority element.

After all cancellations:

Remaining majority = x − y

Since x > y,
Remaining value is positive.

Therefore, majority element survives.

This is the mathematical proof of correctness.

---

# 🔄 Two Versions of the Solution

## 1️⃣ When Majority is Guaranteed

If the problem states that a majority element always exists:

We:
- Run one pass
- Return the final candidate

Time Complexity: O(n)  
Space Complexity: O(1)

This is optimal.

---

## 2️⃣ When Majority is NOT Guaranteed

If majority might not exist:

We need:

Step 1 → Find candidate using Moore’s logic  
Step 2 → Count occurrences of candidate  
Step 3 → If count > n/2 → return it  
Otherwise → return -1  

Why second pass?

Because Moore’s algorithm only guarantees correctness if majority exists.

If not, the final candidate might be incorrect.

---

# 📊 Complexity Analysis

## Time Complexity

First pass → O(n)  
Second pass (if needed) → O(n)

Total → O(n)

## Space Complexity

Only two variables used:
- candidate
- frequency

So → O(1) (constant space)

This is highly efficient.

---

# 🔍 Edge Cases Considered

- Array of size 1
- All elements same
- No majority element
- Large arrays
- Negative numbers

Algorithm handles all cases properly.

---

# 🔁 Concept Mapping (C++ vs Dart)

| Concept | C++ | Dart |
|----------|------|------|
| Array | int arr[] | List<int> |
| Size | size variable | arr.length |
| Integer division | / | ~/ |
| Output | cout | print |

Important understanding:

The logic remains exactly the same across languages.  
Only syntax changes.

---

# 🧠 Pattern Learned Today

This is not just a problem.

It is a reusable pattern:

**Majority / Candidate Elimination Pattern**

Similar ideas are used in:

- Finding element > n/3 times
- Misra-Gries algorithm
- Streaming frequency problems

This is intermediate-level problem solving.

---

# 🔥 Key Takeaways

- Always understand problem before coding
- Convert brute force thinking into pattern-based thinking
- Majority > n/2 means mathematical dominance
- Moore’s algorithm works because of cancellation logic
- Verification step is mandatory if majority is not guaranteed
- Optimal solutions reduce time AND space

---

# 🧩 Mental Exercise

1. Manually simulate algorithm on:
   2, 2, 1, 1, 1, 2, 2

2. Think:
   How many candidates are needed if we want elements that appear more than n/3 times?

3. Why can there only be at most one element greater than n/2?

---

# 📈 Progress Reflection – Day 31

Before:
- Used nested loops (O(n²))
- Counted every element

Now:
- Recognize pattern
- Apply O(n) solution
- Understand proof
- Convert across languages

This is real growth.

---


Day 31 completed successfully.

Consistency > Motivation.
Keep going.