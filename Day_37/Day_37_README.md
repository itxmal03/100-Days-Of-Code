# 📘 Day 37 — Bash Scripting: Loops, File Automation & Error Handling

## 📅 Date

20 March 2026

---

# 🎯 Objective

The goal of today was to move from basic Bash syntax toward **real-world scripting practices**, including:

* Automating repetitive tasks using loops
* Working with files using pattern matching
* Detecting system type (OS-based logic)
* Handling command outputs (success vs error)
* Introducing basic error handling using exit status

---

# 🧠 Concepts Learned

## 🔹 1. Iteration Using `for` Loop

A `for` loop allows repeating a task multiple times.

### Beginner Understanding:

It means:
👉 “Do something again and again for a set of values”

### Two Forms Learned:

* **Manual list iteration**
  → Loop runs on explicitly given values

* **Range-based iteration**
  → Automatically generates a sequence of numbers

### Key Idea:

Iteration helps automate repetitive work instead of writing the same command multiple times.

---

## 🔹 2. File Pattern Matching (Globbing)

Used pattern:

* `*.log`

### Meaning:

👉 Select all files that end with `.log` inside a directory

### Real-World Use:

This allows scripts to:

* Process multiple files automatically
* Avoid hardcoding file names

---

## 🔹 3. File Compression Automation

Task performed:

* Loop through log files
* Compress each file into an archive

### Logical Flow:

1. Pick a file
2. Pass it to compression tool
3. Generate compressed output

### Learning:

This demonstrates **batch processing** — performing the same operation on multiple inputs.

---

## 🔹 4. Conditional Execution (`if-elif-else`)

Used to execute different commands based on system type.

### Two Approaches Learned:

#### Approach 1: Directory Check

* Check if a specific system directory exists

#### Approach 2: OS File Inspection (Better)

* Read system information from a configuration file
* Search for keywords to identify OS

### Key Insight:

Checking system files is **more reliable** than checking directories.

---

## 🔹 5. Output Redirection

Two types of outputs:

| Type                     | Description     |
| ------------------------ | --------------- |
| Standard Output (stdout) | Normal messages |
| Error Output (stderr)    | Error messages  |

### Learned:

* Redirect normal output to one file
* Redirect errors to another file

### Benefit:

👉 Clean logging system
👉 Easier debugging

---

## 🔹 6. Exit Status (`$?`)

Every command returns a status:

| Value    | Meaning |
| -------- | ------- |
| 0        | Success |
| Non-zero | Failure |

### Usage:

* Check if a command worked or failed
* Perform actions based on result

### Important Rule:

👉 Exit status must be checked **immediately after the command**

---

## 🔹 7. Basic Error Handling

Logic applied:

* Run a command
* Check its exit status
* Show an error message if it fails

### Real-World Importance:

* Prevent silent failures
* Improve script reliability

---

# 🧩 Patterns / Techniques Learned

## 🔸 1. Iteration Pattern

Repeat operations efficiently across multiple values or files.

---

## 🔸 2. Automation Pattern

Perform tasks (like compression or updates) without manual intervention.

---

## 🔸 3. Environment-Based Logic

Run different commands depending on system configuration.

---

## 🔸 4. Logging Pattern

Separate success logs and error logs into different files for clarity.

---

## 🔸 5. Validation Pattern

Check whether a command succeeded before proceeding.

---

# ⚠️ Key Observations & Improvements

* Repeated logic (error checking) can be optimized in future
* Output files grow continuously due to append behavior
* Script currently focuses more on failure detection than success confirmation
* File naming during compression can be improved for cleaner output

---

# 🧠 Key Takeaways

* Loops are essential for automation
* Pattern matching simplifies working with multiple files
* System-aware scripts are more flexible and powerful
* Separating output and error logs is a professional practice
* Exit status checking is critical for reliable scripting

---

# 🧪 Mental Exercises

* Think how the script behaves if no files match a pattern
* Consider how to avoid reprocessing already handled files
* Analyze what happens if commands require user interaction (e.g., password input)
* Reflect on how to reduce repetition in logic

---

# 🚀 Progression Note

Today marks a transition from **basic scripting** to **practical automation and system-level thinking**.

Next step will focus on:

* Improving script robustness
* Handling edge cases safely
* Writing cleaner and reusable logic
* Introducing structured scripting techniques (like modular thinking)

---

✅ You are now entering **intermediate-level problem-solving in Bash scripting**.
