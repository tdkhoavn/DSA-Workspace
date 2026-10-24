# Max Consecutive Ones

🟢 Easy · [LeetCode](https://leetcode.com/problems/max-consecutive-ones/) · Lesson 2 — [Static Arrays](../NOTES.md) · [Solution](solution.hpp) · [Tests](solution_test.cpp)

**In short:** given an array of 0s and 1s, return the length of the longest run of consecutive 1s.

## Approach

Walk the array once, remembering two numbers:

- `current` — length of the run of 1s we are inside right now
- `best` — the longest run seen so far

| We see | `current` | `best` |
|---|---|---|
| `1` | `current + 1` | `max(best, current)` |
| `0` | reset to `0` | unchanged — a record never goes down |

## Visualize the algorithm step by step

`nums = [1, 1, 0, 1, 1, 1]`, expected answer `3`.

```
start    [ 1   1   0   1   1   1 ]   current = 0   best = 0

i = 0    [ 1   1   0   1   1   1 ]   see 1 → current = 1   best = 1
           ^
i = 1    [ 1   1   0   1   1   1 ]   see 1 → current = 2   best = 2   ← new record
               ^
i = 2    [ 1   1   0   1   1   1 ]   see 0 → current = 0   best = 2   ← run broken, record kept
                   ^
i = 3    [ 1   1   0   1   1   1 ]   see 1 → current = 1   best = 2   ← 1 < 2, record stays
                       ^
i = 4    [ 1   1   0   1   1   1 ]   see 1 → current = 2   best = 2
                           ^
i = 5    [ 1   1   0   1   1   1 ]   see 1 → current = 3   best = 3   ← new record
                               ^
return best = 3
```

The runs the algorithm discovered:

```
[ 1   1 | 0 | 1   1   1 ]
  └─2─┘       └───3───┘   → longest = 3
```

### The trap: `best` must never follow `current` down

`nums = [1, 1, 1, 0, 1]` — the longest run is at the **start**.

| i | num | current | best (correct) | best if it just copied current ❌ |
|---|---|---|---|---|
| 0 | 1 | 1 | 1 | 1 |
| 1 | 1 | 2 | 2 | 2 |
| 2 | 1 | 3 | **3** | 3 |
| 3 | 0 | 0 | **3** | 0 |
| 4 | 1 | 1 | **3** | 1 ← wrong answer |

Covered by the `LongestRunAtStart` test.

## Complexity

- **Time O(n)** — every element is visited exactly once.
- **Space O(1)** — only two integers, no matter how long the array is.
