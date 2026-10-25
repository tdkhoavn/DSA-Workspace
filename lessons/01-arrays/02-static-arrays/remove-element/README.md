# Remove Element

🟢 Easy · [LeetCode](https://leetcode.com/problems/remove-element/) · Lesson 2 — [Static Arrays](../NOTES.md) · [Solution](solution.hpp) · [Tests](solution_test.cpp)

**In short:** remove every copy of `val` from `nums` in place, and return `k`, the number of elements left. Only the first `k` slots are checked, in any order.

## Approach

Don't **delete** the bad elements — **copy the good ones forward**.

- `num` (the loop) **reads** every element, left to right.
- `k` is where the **next good element is written**, and also how many good elements we kept so far.

| We read | Action | `k` |
|---|---|---|
| `num != val` (good) | `nums[k] = num` | `k + 1` |
| `num == val` (bad) | skip | unchanged |

Since `k` never passes the read position, we only ever overwrite slots we have already read.

## Visualize the algorithm step by step

`nums = [0, 1, 2, 2, 3, 0, 4, 2]`, `val = 2`, expected `k = 5`.
`r` = read position, `w` = write position (`k`).

```
start          [ 0  1  2  2  3  0  4  2 ]    k = 0
                 rw

read 0 (good)  [ 0  1  2  2  3  0  4  2 ]    nums[0] = 0, k = 1
                 rw                           (r and w are together:
read 1 (good)  [ 0  1  2  2  3  0  4  2 ]     copying onto itself)
                    rw                        nums[1] = 1, k = 2

read 2 (bad)   [ 0  1  2  2  3  0  4  2 ]    skip, k = 2
                       wr
read 2 (bad)   [ 0  1  2  2  3  0  4  2 ]    skip, k = 2   ← w waits at the first bad slot
                       w  r

read 3 (good)  [ 0  1  3  2  3  0  4  2 ]    nums[2] = 3, k = 3
                       w     r                ↑ pulled forward 2 slots
read 0 (good)  [ 0  1  3  0  3  0  4  2 ]    nums[3] = 0, k = 4
                          w     r
read 4 (good)  [ 0  1  3  0  4  0  4  2 ]    nums[4] = 4, k = 5
                             w     r
read 2 (bad)   [ 0  1  3  0  4  0  4  2 ]    skip, k = 5
                                w     r

return k = 5   [ 0  1  3  0  4 | 0  4  2 ]
                 └── kept ───┘   leftovers, not checked
```

### Copy, don't swap

`nums[k] = num` **copies**: the old value at the read position stays where it is. That is why the leftovers look like `0 4 2` instead of `2 2 2` — and that is fine, because nothing after `k` is checked. Swapping would also be correct, but costs three assignments instead of one for no benefit.

### Why not delete-and-shift?

Deleting one element from the middle of an array is O(n) (lesson 2). If many elements equal `val`, deleting each one costs O(n) **each time** — O(n²) in total when every element is `val`. Copying good elements forward moves each element at most once.

## Complexity

- **Time O(n)** — every element is read once and written at most once.
- **Space O(1)** — only the counter `k`; the array is modified in place.
