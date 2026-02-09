# Day 10 – Programming Fundamentals (PF)

## 📌 Focus of the Day
Strengthening problem-solving skills by applying **Insertion Sort** to different data structures and improving control over **2D matrix indexing**.

---

## 🎯 Objectives
- Gain strong command over **Insertion Sort**
- Apply insertion sort:
  - Row-wise in a 2D matrix
  - On the entire matrix by converting it into a 1D array
- Practice **boundary printing** of a matrix
- Maintain the same logic while switching between **C++ and Dart**
- Improve index handling and loop discipline (PF exam focused)

---

## 🧠 Concepts Practiced

### 1. Insertion Sort (Core Concept)
- Build a sorted part of the array step by step
- Compare the current element with previous elements
- Shift elements until the correct position is found

**Key Idea:**  
> “Keep comparing backward until the correct position or the first element is reached.”

---

### 2. Row-Wise Matrix Sorting
- Treat each row as a separate 1D array
- Apply insertion sort on every row independently
- Row index remains fixed while column index moves left

---

### 3. Sorting the Entire Matrix
- Convert the 4×4 matrix into a **1D array of 16 elements**
- Apply insertion sort on the 1D array
- Copy the sorted values back into the matrix in row-major order

**Important Learning:**  
Sorting a matrix requires defining a **linear order** before applying any sorting algorithm.

---

### 4. Boundary Printing of a Matrix
- Print only the outer elements of a matrix
- Identify boundary conditions using row and column indices

---

## 🧪 Problems Solved
- Print boundary elements of a 2D matrix
- Sort each row of a matrix using insertion sort
- Sort the entire matrix using insertion sort
- Convert 2D matrix → 1D array → sorted matrix

---

## 🛠 Languages Used
- C++
- Dart (exact logic translation, no optimization)

---

## ⚠️ Common Mistakes Identified & Fixed
- Skipping elements while flattening a matrix
- Incorrect loop bounds when copying data back
- Confusing linear order with diagonal movement
- Incomplete matrix traversal

---

## 📈 Learning Outcome (Day 10)
- Clear understanding of **Insertion Sort**
- Confidence in handling **2D arrays**
- Stronger grip on indices and loop control
- Ability to translate logic across programming languages
- Improved PF-exam readiness

---

## ✅ Status
**Day 10 completed successfully ✔**
