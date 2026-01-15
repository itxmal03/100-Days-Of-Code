# 📘 Day 5 – Dynamic Arrays (C++) & Lists (Dart)

## 🎯 Goal of Day 5
The goal of Day 5 was to understand **dynamic arrays**, why they are used, and how the **same concept is implemented differently in C++ and Dart**.  
This day focused on **concept learning** instead of heavy problem solving due to the ICT final exam.

---

## 🧠 What is a Dynamic Array?
A **dynamic array** is an array whose size is decided **at runtime**, not at compile time.

### ❌ Static Array (Fixed Size)
- Size is fixed at compile time.
- Cannot change size during execution.

### ✅ Dynamic Array
- Size is determined at runtime.
- Memory is allocated while the program is running.

---

## 🔹 Dynamic Array in C++ (Using Pointers)
In C++, dynamic arrays are created using **heap memory** and **pointers**.

### Core Concepts
- `new` allocates memory at runtime.
- Pointer stores the starting address of the array.
- `delete[]` frees memory manually.

### Important Points
- Memory is **not initialized**.
- Garbage values may exist.
- Programmer must free memory.
- Forgetting `delete[]` causes **memory leak**.

---

## 🔹 Dynamic Array in Dart (Using List)
Dart does **not** support pointers like C++.

Instead, Dart uses **List**, which behaves like a dynamic array but is:
- Safer
- Automatically managed
- Free from memory leaks

### Key Points in Dart
- Use `List.filled(size, value)` to create a fixed-size list.
- Every index has an initial value to prevent uninitialized memory.
- Dart Lists replace pointer-based arrays in C++.

---

## 🔄 C++ vs Dart Comparison

| Feature | C++ | Dart |
|---------|-----|-----|
| Dynamic allocation | Uses `new int[size]` | Uses `List.filled(size, value)` |
| Memory management | Manual | Automatic |
| Garbage values | Possible | Not allowed |
| Free memory | Required (`delete[]`) | Not required |
| Pointer arithmetic | Allowed | Not allowed |

---

## 🌍 Real-Life Analogy

### C++ Dynamic Array
Like **renting a room**:
- You get the key.
- You must return it yourself.
- Forgetting causes problems (memory leak).

### Dart List
Like staying in a **hotel**:
- Room is allocated for you.
- Cleaning is automatic.
- No memory stress.

---

## 🧩 Key Takeaways
- Dynamic memory allocation happens at runtime.
- C++ gives low-level control but is risky.
- Dart avoids memory errors using garbage collection.
- Dart does not allow uninitialized memory.
- Dart `List` replaces arrays + pointers.
- Use `List.filled(size, value)` in Dart when size is known.

---

## 🧠 Exam-Oriented Notes
- Dynamic memory is stored in **heap**.
- C++ uses `new` and `delete`.
- Dart uses **garbage collection**.
- Dart Lists are safer than pointer-based arrays.
- Understand differences in memory handling for theory questions.

---

## 📓 Daily Progress Log
**Day 5 – Concepts Learned**
- Dynamic arrays using pointers in C++.
- Manual vs automatic memory management.
- Dart List as dynamic array alternative.
- Why Dart avoids pointers and garbage values.
- Syntax and memory handling differences between C++ and Dart.

---

## 🚀 Next Steps
- Deep dive into pointers and heap memory.
- Practice dynamic array problem solving.
- Connect Dart Lists with Flutter `ListView` for real apps.

---

✅ **Status**: Day 5 Completed  
📌 **Focus**: Concept clarity over problem solving
