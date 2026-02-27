# Day 29 – OOP Revision (Dart vs C++ Privacy)

## Date   23-Feb-2026
Day 29 – OOP Practice & Comparison

---

# Objective

Today’s goal was simple:

- Revise basic OOP structure
- Understand how private members work in Dart
- Compare privacy behavior with C++
- Practice setter and getter usage in both languages

No advanced concepts — only what was actually practiced.

---

# What Was Practiced Today

## 1️⃣ Creating a Class

Both in Dart and C++, a class named `Teacher` was created.

The class contained:

- A private data member for salary
- Public data members for name and department
- Setter method to assign salary
- Getter method to retrieve salary

The purpose was to understand how private data behaves differently in both languages.

---

# 2️⃣ Privacy in Dart

In Dart, a variable becomes private when:

It starts with an underscore `_`.

Example concept:

- `_salary` is private.
- But private in Dart means: **private to the file (library)**.

Important behavior observed today:

- If `main()` and the class are inside the same file,
  `_salary` can still be accessed.
- If the class is moved to another file, `_salary` cannot be accessed outside that file.

So the key rule learned:

> Dart provides file-level privacy.

This is different from C++.

---

# 3️⃣ Privacy in C++

In C++, we use:

- `private`
- `public`

When a member is marked `private`:

- It cannot be accessed outside the class.
- Even if `main()` is in the same file, it still cannot access private members.

Key rule learned:

> C++ provides class-level privacy.

So in C++:
- You must use setter and getter to access private data.
- Direct access from `main()` is not allowed.

---

# 4️⃣ Setter and Getter Usage Difference

## In Dart

Setter is used like variable assignment.

Getter is used like accessing a variable.

It does not look like a normal function call.

This is part of Dart’s syntax style.

---

## In C++

Setter and getter are normal functions.

They must be called like regular methods.

Example behavior practiced:

- `setSalary()` is called to assign value.
- `getSalary()` is called to retrieve value.

---

# 5️⃣ Important Difference Observed Today

| Feature | Dart | C++ |
|----------|------|------|
| Private mechanism | `_` underscore | `private` keyword |
| Privacy level | File (library) | Class |
| Access inside same file | Allowed | Not allowed |
| Setter call style | Property-style | Function-style |

This was the main comparison practiced today.

---

# What Was Confusing (And Now Clear)

Confusion:

In C++, private members cannot be accessed in `main()`.

But in Dart, `_salary` was accessible.

Reason:

Dart privacy is file-based, not class-based.

Once this rule was understood, the confusion was resolved.

---

# Key Takeaways from Day 29

- Dart uses `_` for private members.
- Dart privacy works at file level.
- C++ privacy works at class level.
- Setter/getter syntax differs between Dart and C++.
- Same OOP idea, different language implementation.

---

# Progress Note

Today focused only on:

- Class structure
- Private members
- Setter and getter
- Dart vs C++ privacy difference

No advanced OOP concepts were covered today.

Tomorrow can build on this foundation step by step.