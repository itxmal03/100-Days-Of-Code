# Day 13 – Unique Characters Logic (Concept Focus)

## Status
- ✅ 1st Smester Final exams completed (Alhamdulillah)
- ✅ Problem-solving journey restarted
- ⚠️ Mental fatigue acknowledged, pace adjusted

---

## Problem Focus
**Find the first 3 unique characters in a string, in the order they appear.**

Example idea:
- Input string contains repeated characters
- Output should include only the first three characters that appear **for the first time**

---

## Key Concept: What “Unique” Really Means

A character is **unique** if:
- It has **not appeared before** anywhere in the processed part of the string  
- Uniqueness is **not** about comparing adjacent characters

This was the main conceptual correction on Day 13.

---

## Correct Logical Approach (Language Independent)

1. Traverse the string from left to right.
2. Maintain a separate container to store already-found unique characters.
3. For each new character:
   - Check it against **all characters already stored**
   - If it does not exist, add it to the container
4. Stop processing once the container size reaches 3.

---

## Common Mistakes Identified Today

- ❌ Checking only adjacent characters (`str[i] != str[i-1]`)
- ❌ Assuming `< 3` means “run less than 3 times”
- ❌ Accessing characters from an empty string (out-of-bounds risk)

---

## Important Logical Clarifications

- Condition `< 3` allows values `0, 1, 2` → loop can run **three times**
- A loop runs based on **state**, not intention
- Uniqueness always requires **comparison with all previous elements**

---

## Cross-Language Insight

The same logic applies in:
- C++
- Dart
- Any other programming language

Only syntax changes — **thinking does not**.

---

## Reflection – Day 13

- Brain fatigue was real and respected
- Focus shifted from speed to correctness
- Logic finally stabilized for “unique character” problems
- Ending early was a **strategic decision**, not weakness

---

## Next Step (Day 14)

- Fresh mind
- New problem
- Same rule: **logic first, code later**

---

**End of Day 13**  
Consistency over intensity 🌙
