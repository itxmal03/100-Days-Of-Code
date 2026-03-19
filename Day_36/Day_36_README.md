# 📘 Day 36 – Bash Scripting (Intermediate Concepts)

## 📅 Date

March 19, 2026

---

## 🎯 Objective

To move beyond basic Bash scripting and develop a deeper understanding of **decision-making, comparisons, functions, and control flow**, which are essential for building logical thinking in programming.

---

## 📚 Concepts Learned

### 1. Conditional Statements (if-else)

Conditional statements allow a program to make decisions based on conditions.

* A condition is evaluated as **true or false**
* Based on the result, different blocks of code are executed

#### Types of Syntax

* **Single brackets `[ ]`**

  * Traditional method
  * Internally treated as a command (`test`)
  * Requires strict spacing

* **Double brackets `[[ ]]`**

  * Modern and safer approach
  * Better handling of variables and conditions

✔ Preferred approach: Always use `[[ ]]` for better readability and safety

---

### 2. Comparison Operators

Comparison operators are used to compare values and return a boolean result.

#### 🔢 Numeric Comparisons

* Equal → `-eq`
* Not Equal → `-ne`
* Greater Than → `-gt`
* Less Than → `-lt`
* Greater or Equal → `-ge`
* Less or Equal → `-le`

👉 Used when working with numbers

---

#### 🔤 String Comparisons

* Equal → `=` or `==`
* Not Equal → `!=`
* Empty String → `-z`
* Non-Empty String → `-n`

👉 Used when working with text values

---

### 3. Arithmetic Evaluation `(( ))`

Used for performing mathematical operations in a cleaner and more natural way.

* Allows standard operators like `+`, `-`, `%`, `==`
* No need for `-eq`, `-gt`, etc.

#### Use Case:

* Checking even/odd numbers
* Performing calculations

---

### 4. Functions in Bash

Functions help organize code into reusable blocks.

* Accept input as parameters
* Access parameters using positional variables like:

  * `$1` → first argument
  * `$2` → second argument

#### Key Understanding:

* Passing the **value** of a variable is important (not the variable name itself)

---

### 5. Case Statement (Switch Alternative)

Used to simplify multiple condition checks.

* Matches a value against multiple patterns
* Executes corresponding block

#### Benefits:

* Cleaner than multiple if-else statements
* Ideal for menu-driven programs

---

### 6. While Loop

A loop that continues executing as long as a condition remains true.

#### Use Cases:

* Counting sequences
* Continuous checks (e.g., monitoring file existence)

---

### 7. File Existence Check

Used to verify whether a file exists in the system.

* Enables real-world automation
* Can be combined with loops for continuous monitoring

---

## 🧠 Patterns / Techniques Learned

### 🔹 Pattern 1: Compare → Decide

* Compare two values
* Execute action based on result

Used in:

* Number comparisons
* Even/odd logic
* String checks

---

### 🔹 Pattern 2: Input → Process → Output

* Take input from user 
* Apply logic
* Display result

Used in:

* Calculator program
* Conditional checks

---

### 🔹 Pattern 3: Menu-Based Decision Making

* Present options to user
* Take input
* Execute corresponding logic

Used in:

* Case-based calculator

---

### 🔹 Pattern 4: Repetition Until Condition Changes

* Execute repeatedly
* Stop when condition becomes false

Used in:

* Counting loop
* File monitoring loop

---

## ⚠️ Important Learnings & Corrections

* Always use proper spacing inside brackets
* Prefer `[[ ]]` over `[ ]` for conditions
* Use `(( ))` for mathematical operations
* Ensure correct value passing in functions
* Be cautious of invalid operations (e.g., division by zero)
* Use quotes around variables to avoid unexpected issues

---

## 💡 Key Takeaways

* Programming is about **decision-making and repetition**
* Conditions form the backbone of logic building
* Understanding comparisons is critical for solving problems
* Functions improve code structure and reusability
* Case statements simplify complex decision trees
* Loops enable automation and continuous execution

---

## 🧠 Mental Exercises

* Think about how to check if a number is divisible by multiple values
* Consider how to prevent invalid user inputs
* Imagine building a loop that continues until correct input is given

---

## 🚀 Progression Note

Day 36 marks a significant step toward **real problem-solving in Bash scripting**. You are now transitioning from simple commands to **logical thinking patterns**, which are essential for tackling real-world programming problems.

Next step:

* Strengthen control flow
* Combine loops + conditions
* Start building small real-world scripts with logic

Keep going — consistency is building your problem-solving mindset 💪
