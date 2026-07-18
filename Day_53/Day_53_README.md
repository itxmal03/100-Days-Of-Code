# Maximum Subarray Sum – Kadane's Algorithm Progression
**Date:** 2026-07-18  
**Language:** C++ (primary) + Dart (translation)  
**Topic:** Array subarray generation & maximum sum optimization

**Kotlin setup** Print hello world in kotlin 
---

## Implemented Functions

| Function | Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- | :--- |
| `printSubArray()` | Triple nested loops – prints all subarrays | O(n³) | O(1) |
| `maxSubArrSum()` | Brute force – sums each subarray from scratch | O(n³) | O(1) |
| `maxSubArrSum2()` | Optimized brute force – reuses previous `local_sum` | O(n²) | O(1) |
| `kadanesAlgoMaxSum()` | Kadane's Algorithm – discards negative prefix | O(n) | O(1) |

---

## Key Takeaways

- **`INT_MIN` (`-2147483648` from `<climits>`)** is used instead of `0` to correctly handle **all-negative arrays**.
  - Example: `{-1, -2, -3}` returns `-1` (correct), not `0` (incorrect).
- **Compilation fix:** Added `#include <algorithm>` for `std::max` (not implicitly included via `<iostream>`).
- **Dart translation:** Mirrors the C++ logic exactly for `printSubArray()`.

---

## Test Input & Output

**Array:** `{1, 2, 3, 4, 5}`  
**Maximum Subarray Sum:** `15` (entire array)

**All functions produce the same correct output** for this input.

---

## Status
✅ Complete – compiles and runs correctly.