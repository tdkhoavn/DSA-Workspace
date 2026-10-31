# Replace Elements With Greatest Element On Right Side

🟢 Easy · [LeetCode](https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/) · Lesson 2 — [Static Arrays](../NOTES.md) · [Solution](solution.hpp) · [Tests](solution_test.cpp)

**In short:** swap every element for the largest value to its right; the last element has nothing to its right, so it becomes `-1`.

## Approach

### Brute force — O(n²)

For each `i`, scan everything to its right and keep the max. Start that max at `-1`, so the last element (empty scan) gets `-1` with no special case.

The waste: the scan for `i` repeats almost all of the scan for `i + 1`.

### Reverse scan — O(n)

The right side of `i` is just `arr[i + 1]` plus the right side of `i + 1`. So walk **right to left** and carry the answer along:

- `rightMax` = the largest value **already walked past**, i.e. the largest value to the right of where we stand. Starts at `-1` (nothing walked past yet).

At each `i`, in this order:

1. **Write first:** `arr[i] = rightMax` — the answer for `i`.
2. **Update after:** `rightMax = max(rightMax, old arr[i])` — `i` is now to the right of `i - 1`.

Because we write into `arr` itself, the old `arr[i]` is saved in `currentVal` before it is overwritten.

## Visualize the algorithm step by step

`arr = [2, 4, 5, 3, 1, 2]`, expected `[5, 5, 3, 2, 2, -1]`.

| `i` | `arr[i]` (old) | `rightMax` before | write `arr[i]` | `rightMax` after |
|---|---|---|---|---|
| 5 | 2 | -1 | **-1** | max(-1, 2) = 2 |
| 4 | 1 | 2 | **2** | max(2, 1) = 2 |
| 3 | 3 | 2 | **2** | max(2, 3) = 3 |
| 2 | 5 | 3 | **3** | max(3, 5) = 5 |
| 1 | 4 | 5 | **5** | max(5, 4) = 5 |
| 0 | 2 | 5 | **5** | max(5, 2) = 5 (never used) |

```
           ←── walk this way
arr      [ 2  4  5  3  1  2 ]
result   [ 5  5  3  2  2 -1 ]
                 ↑
          at i = 2, rightMax holds 3 = max of [3 1 2], not yet 5
```

"`rightMax` before" in each row is "`rightMax` after" of the row above: that is the value being carried.

### The trap: update before write

Swap the two steps and every element counts **itself**:

| `i` | `arr[i]` | update first | then write | correct |
|---|---|---|---|---|
| 2 | 5 | `rightMax` = max(3, 5) = 5 | **5** ❌ | 3 |

The same thing happens if you forget `currentVal`: after `arr[i] = rightMax`, the old value is gone and `max(rightMax, arr[i])` compares `rightMax` with itself.

### Edge case: one element

`arr = [7]` → the loop runs once: write `-1`, then update (unused). Result `[-1]`. Starting `rightMax` at `-1` covers this with no `if`.

## Complexity

| | Time | Space (extra) |
|---|---|---|
| Brute force | O(n²) — (n−1) + (n−2) + … + 1 = n(n−1)/2 steps | O(n) — a separate `result` vector |
| Reverse scan | O(n) — one write and one compare per element | O(1) — in place, one variable |

Returning `arr` copies the vector, because `arr` is a reference to the caller's data. That copy is the required output, so it is not counted as extra space.
