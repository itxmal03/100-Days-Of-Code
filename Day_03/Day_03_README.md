# Day 03 – Rate Limiting (Sliding Window Logic)

## Problem Statement

In real-world systems like APIs and servers, users are not allowed to make unlimited requests in a short time.

You are given a list of timestamps (in seconds) representing when a user made requests.

Example:
[1, 2, 4, 5, 6, 7, 19, 25, 30, 40, 41, 42, 43, 44]

Each value means:
A request was made at that exact second.

---

## Real-Life Analogy (Very Important)

Imagine a **security guard at a building entrance**.

Rule:
- A person can enter **only 3 times within 10 minutes**
- If they try a 4th time within the same 10-minute window → ❌ STOPPED

The guard does NOT care about old entries.
He only checks:
"How many times did you enter in the last 10 minutes?"

This is exactly how **rate limiting** works in software systems.

---

## Rule (Rate Limiting Constraint)

- A user can make **at most 3 requests in any 10-second window**
- If a request violates this rule → BLOCK it
- Otherwise → ALLOW it

---

## Logical Approach

For every request at time `T`:

1. Look only at **previous requests**
2. Count how many happened within the last 10 seconds:
   (T - previous_time < 10)
3. If previous count < 3 → Allow current request
4. Else → Block current request

The current request itself is not included in the count.

---

## Step-by-Step Example

Given timestamps:
[1, 2, 4, 5, 6, 7]

For request at `7` seconds:
- Requests within last 10 seconds → [1, 2, 4, 5, 6]
- Count = 5
- Since count ≥ 3 → Request at 7s is BLOCKED

---

## Algorithm (Language Independent)

1. Loop through each timestamp
2. For the current timestamp:
   - Loop through all earlier timestamps
   - Count those where:
     current_time - previous_time < 10
3. If count < 3 → Allow
4. Else → Block

---

## Key Concepts Learned

- Understanding time-based problems
- Translating real-life rules into logic
- Sliding Window technique (basic)
- Nested loop reasoning
- Same logic works in C++ and Dart

---

## Real-World Applications

- API rate limiting
- Login attempt control
- OTP / SMS throttling
- Server request protection
- Abuse prevention systems

---

## Day 03 Status

- Problem understood without panic
- Logic clearly designed before coding
- Implemented in C++
- Implemented in Dart
- Real-life relevance achieved

Day 03 Completed
