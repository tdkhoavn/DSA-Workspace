# DSA Workspace

[![CI](https://github.com/tdkhoavn/DSA-Workspace/actions/workflows/ci.yml/badge.svg)](https://github.com/tdkhoavn/DSA-Workspace/actions/workflows/ci.yml)

My journey through NeetCode's [Algorithms and Data Structures for Beginners](https://neetcode.io/courses/dsa-for-beginners/0) course, solved in **modern C++ (C++20)**.

Every solution is my own work, is covered by unit tests ([GoogleTest](https://github.com/google/googletest)), and is built and tested on every push by GitHub Actions with AddressSanitizer and UndefinedBehaviorSanitizer enabled.

## Repository layout

```
lessons/<NN-topic>/<NN-lesson>/
├── NOTES.md                 # lesson notes (Vietnamese)
├── playground/<name>.cpp    # runnable experiments, each with its own main()
└── <problem-slug>/
    ├── README.md            # approach + step-by-step visualization of the algorithm
    ├── solution.hpp         # class Solution, LeetCode-compatible signature
    └── solution_test.cpp    # unit tests
cpp-notes/                   # C++ concepts learned along the way
templates/problem/           # starting point for a new problem
tools/new-problem.sh         # scaffolds a problem folder from the template
```

Lesson numbers match the course URLs: `lessons/01-arrays/02-static-arrays` ↔ `neetcode.io/courses/dsa-for-beginners/2`.

## Build & test

Requires CMake ≥ 3.24 and a C++20 compiler. GoogleTest is fetched automatically.

```sh
cmake -S . -B build -G Ninja
cmake --build build
ctest --test-dir build --output-on-failure
```

In CLion, open the folder as a CMake project and run `tools/gen-run-configs.sh` once: every problem gets its own run configuration that builds and runs only that problem's tests (e.g. `02-remove-element`), and every playground file gets `<lesson>-pg-<name>` (e.g. `02-pg-static_array`). `tools/new-problem.sh` regenerates them automatically.

Start a new problem:

```sh
tools/new-problem.sh lessons/01-arrays/02-static-arrays remove-element \
    "Remove Element" https://leetcode.com/problems/remove-element/ easy
```

## Progress

⬜ not started · ✅ done · 🔁 revisited with a different technique

### Arrays

| # | Lesson | Problem | Difficulty | Approach | Time | Space | Status |
|---|---|---|---|---|---|---|---|
| 1 | [RAM](https://neetcode.io/courses/dsa-for-beginners/1) | — | | | | | ⬜ |
| 2 | [Static Arrays](https://neetcode.io/courses/dsa-for-beginners/2) | [Max Consecutive Ones](https://leetcode.com/problems/max-consecutive-ones/) | 🟢 Easy | [Single pass, current vs. best run](lessons/01-arrays/02-static-arrays/max-consecutive-ones/) | O(n) | O(1) | ✅ |
|  |  | [Remove Element](https://leetcode.com/problems/remove-element/) | 🟢 Easy | [Read/write indices, copy kept elements forward](lessons/01-arrays/02-static-arrays/remove-element/) | O(n) | O(1) | ✅ |
|  |  | [Replace Elements With Greatest Element On Right Side](https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/) | 🟢 Easy | [Reverse scan, carry the max seen so far](lessons/01-arrays/02-static-arrays/replace-elements-with-greatest-element-on-right-side/) | O(n) | O(1) | ✅ |
| 3 | [Dynamic Arrays](https://neetcode.io/courses/dsa-for-beginners/3) | [Concatenation of Array](https://leetcode.com/problems/concatenation-of-array/) | 🟢 Easy | | | | ⬜ |
| 4 | [Stacks](https://neetcode.io/courses/dsa-for-beginners/4) | [Baseball Game](https://leetcode.com/problems/baseball-game/) | 🟢 Easy | | | | ⬜ |
|  |  | [Valid Parentheses](https://leetcode.com/problems/valid-parentheses/) | 🟢 Easy | | | | ⬜ |
|  |  | [Min Stack](https://leetcode.com/problems/min-stack/) | 🟡 Medium | | | | ⬜ |

### Linked Lists

| # | Lesson | Problem | Difficulty | Approach | Time | Space | Status |
|---|---|---|---|---|---|---|---|
| 5 | [Singly Linked Lists](https://neetcode.io/courses/dsa-for-beginners/5) | [Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/) | 🟢 Easy | | | | ⬜ |
|  |  | [Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/) | 🟢 Easy | | | | ⬜ |
| 6 | [Doubly Linked Lists](https://neetcode.io/courses/dsa-for-beginners/6) | [Design Linked List](https://leetcode.com/problems/design-linked-list/) | 🟡 Medium | | | | ⬜ |
|  |  | [Design Browser History](https://leetcode.com/problems/design-browser-history/) | 🟡 Medium | | | | ⬜ |
| 7 | [Queues](https://neetcode.io/courses/dsa-for-beginners/7) | [Number of Students Unable to Eat Lunch](https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/) | 🟢 Easy | | | | ⬜ |
|  |  | [Implement Stack Using Queues](https://leetcode.com/problems/implement-stack-using-queues/) | 🟢 Easy | | | | ⬜ |

### Recursion

| # | Lesson | Problem | Difficulty | Approach | Time | Space | Status |
|---|---|---|---|---|---|---|---|
| 8 | [Factorial](https://neetcode.io/courses/dsa-for-beginners/8) | [Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/) 🔁 | 🟢 Easy | | | | ⬜ |
| 9 | [Fibonacci Sequence](https://neetcode.io/courses/dsa-for-beginners/9) | [Climbing Stairs](https://leetcode.com/problems/climbing-stairs/) | 🟢 Easy | | | | ⬜ |

### Sorting

| # | Lesson | Problem | Difficulty | Approach | Time | Space | Status |
|---|---|---|---|---|---|---|---|
| 10 | [Insertion Sort](https://neetcode.io/courses/dsa-for-beginners/10) | — | | | | | ⬜ |
| 11 | [Merge Sort](https://neetcode.io/courses/dsa-for-beginners/11) | [Merge Sorted Array](https://leetcode.com/problems/merge-sorted-array/) | 🟢 Easy | | | | ⬜ |
|  |  | [Merge K Sorted Lists](https://leetcode.com/problems/merge-k-sorted-lists/) | 🔴 Hard | | | | ⬜ |
| 12 | [Quick Sort](https://neetcode.io/courses/dsa-for-beginners/12) | [K Closest Points to Origin](https://leetcode.com/problems/k-closest-points-to-origin/) | 🟡 Medium | | | | ⬜ |
| 13 | [Bucket Sort](https://neetcode.io/courses/dsa-for-beginners/13) | [Sort Colors](https://leetcode.com/problems/sort-colors/) | 🟡 Medium | | | | ⬜ |

### Binary Search

| # | Lesson | Problem | Difficulty | Approach | Time | Space | Status |
|---|---|---|---|---|---|---|---|
| 14 | [Search Array](https://neetcode.io/courses/dsa-for-beginners/14) | [Binary Search](https://leetcode.com/problems/binary-search/) | 🟢 Easy | | | | ⬜ |
|  |  | [Search a 2D Matrix](https://leetcode.com/problems/search-a-2d-matrix/) | 🟡 Medium | | | | ⬜ |
| 15 | [Search Range](https://neetcode.io/courses/dsa-for-beginners/15) | [Guess Number Higher or Lower](https://leetcode.com/problems/guess-number-higher-or-lower/) | 🟢 Easy | | | | ⬜ |
|  |  | [Koko Eating Bananas](https://leetcode.com/problems/koko-eating-bananas/) | 🟡 Medium | | | | ⬜ |

### Trees

| # | Lesson | Problem | Difficulty | Approach | Time | Space | Status |
|---|---|---|---|---|---|---|---|
| 16 | [Binary Tree](https://neetcode.io/courses/dsa-for-beginners/16) | — | | | | | ⬜ |
| 17 | [Binary Search Tree](https://neetcode.io/courses/dsa-for-beginners/17) | — | | | | | ⬜ |
| 18 | [BST Insert and Remove](https://neetcode.io/courses/dsa-for-beginners/18) | [Insert into a Binary Search Tree](https://leetcode.com/problems/insert-into-a-binary-search-tree/) | 🟡 Medium | | | | ⬜ |
|  |  | [Delete Node in a BST](https://leetcode.com/problems/delete-node-in-a-bst/) | 🟡 Medium | | | | ⬜ |
| 19 | [Depth-First Search](https://neetcode.io/courses/dsa-for-beginners/19) | [Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal/) | 🟢 Easy | | | | ⬜ |
|  |  | [Balanced Binary Tree](https://leetcode.com/problems/balanced-binary-tree/) | 🟢 Easy | | | | ⬜ |
|  |  | [Kth Smallest Element in a BST](https://leetcode.com/problems/kth-smallest-element-in-a-bst/) | 🟡 Medium | | | | ⬜ |
|  |  | [Construct Binary Tree from Preorder and Inorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/) | 🟡 Medium | | | | ⬜ |
| 20 | [Breadth-First Search](https://neetcode.io/courses/dsa-for-beginners/20) | [Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/) | 🟡 Medium | | | | ⬜ |
|  |  | [Binary Tree Right Side View](https://leetcode.com/problems/binary-tree-right-side-view/) | 🟡 Medium | | | | ⬜ |
| 21 | [BST Sets and Maps](https://neetcode.io/courses/dsa-for-beginners/21) | — | | | | | ⬜ |

### Backtracking

| # | Lesson | Problem | Difficulty | Approach | Time | Space | Status |
|---|---|---|---|---|---|---|---|
| 22 | [Tree Maze](https://neetcode.io/courses/dsa-for-beginners/22) | [Path Sum](https://leetcode.com/problems/path-sum/) | 🟢 Easy | | | | ⬜ |
|  |  | [Subsets](https://leetcode.com/problems/subsets/) | 🟡 Medium | | | | ⬜ |
|  |  | [Combination Sum](https://leetcode.com/problems/combination-sum/) | 🟡 Medium | | | | ⬜ |

### Heap / Priority Queue

| # | Lesson | Problem | Difficulty | Approach | Time | Space | Status |
|---|---|---|---|---|---|---|---|
| 23 | [Heap Properties](https://neetcode.io/courses/dsa-for-beginners/23) | — | | | | | ⬜ |
| 24 | [Push and Pop](https://neetcode.io/courses/dsa-for-beginners/24) | [Kth Largest Element in a Stream](https://leetcode.com/problems/kth-largest-element-in-a-stream/) | 🟢 Easy | | | | ⬜ |
| 25 | [Heapify](https://neetcode.io/courses/dsa-for-beginners/25) | [Last Stone Weight](https://leetcode.com/problems/last-stone-weight/) | 🟢 Easy | | | | ⬜ |
|  |  | [K Closest Points to Origin](https://leetcode.com/problems/k-closest-points-to-origin/) 🔁 | 🟡 Medium | | | | ⬜ |
|  |  | [Kth Largest Element in an Array](https://leetcode.com/problems/kth-largest-element-in-an-array/) | 🟡 Medium | | | | ⬜ |

### Hashing

| # | Lesson | Problem | Difficulty | Approach | Time | Space | Status |
|---|---|---|---|---|---|---|---|
| 26 | [Hash Usage](https://neetcode.io/courses/dsa-for-beginners/26) | [Contains Duplicate](https://leetcode.com/problems/contains-duplicate/) | 🟢 Easy | | | | ⬜ |
|  |  | [Two Sum](https://leetcode.com/problems/two-sum/) | 🟢 Easy | | | | ⬜ |
|  |  | [Valid Anagram](https://leetcode.com/problems/valid-anagram/) | 🟢 Easy | | | | ⬜ |
|  |  | [LRU Cache](https://leetcode.com/problems/lru-cache/) | 🟡 Medium | | | | ⬜ |
| 27 | [Hash Implementation](https://neetcode.io/courses/dsa-for-beginners/27) | — | | | | | ⬜ |

### Graphs

| # | Lesson | Problem | Difficulty | Approach | Time | Space | Status |
|---|---|---|---|---|---|---|---|
| 28 | [Intro to Graphs](https://neetcode.io/courses/dsa-for-beginners/28) | — | | | | | ⬜ |
| 29 | [Matrix DFS](https://neetcode.io/courses/dsa-for-beginners/29) | [Flood Fill](https://leetcode.com/problems/flood-fill/) | 🟢 Easy | | | | ⬜ |
|  |  | [Number of Islands](https://leetcode.com/problems/number-of-islands/) | 🟡 Medium | | | | ⬜ |
|  |  | [Max Area of Island](https://leetcode.com/problems/max-area-of-island/) | 🟡 Medium | | | | ⬜ |
| 30 | [Matrix BFS](https://neetcode.io/courses/dsa-for-beginners/30) | [Shortest Path in Binary Matrix](https://leetcode.com/problems/shortest-path-in-binary-matrix/) | 🟡 Medium | | | | ⬜ |
|  |  | [Rotting Oranges](https://leetcode.com/problems/rotting-oranges/) | 🟡 Medium | | | | ⬜ |
| 31 | [Adjacency List](https://neetcode.io/courses/dsa-for-beginners/31) | [Clone Graph](https://leetcode.com/problems/clone-graph/) | 🟡 Medium | | | | ⬜ |
|  |  | [Course Schedule](https://leetcode.com/problems/course-schedule/) | 🟡 Medium | | | | ⬜ |

### Dynamic Programming

| # | Lesson | Problem | Difficulty | Approach | Time | Space | Status |
|---|---|---|---|---|---|---|---|
| 32 | [1-Dimension DP](https://neetcode.io/courses/dsa-for-beginners/32) | [Climbing Stairs](https://leetcode.com/problems/climbing-stairs/) 🔁 | 🟢 Easy | | | | ⬜ |
|  |  | [House Robber](https://leetcode.com/problems/house-robber/) | 🟡 Medium | | | | ⬜ |
| 33 | [2-Dimension DP](https://neetcode.io/courses/dsa-for-beginners/33) | [Unique Paths](https://leetcode.com/problems/unique-paths/) | 🟡 Medium | | | | ⬜ |
|  |  | [Unique Paths II](https://leetcode.com/problems/unique-paths-ii/) | 🟡 Medium | | | | ⬜ |
|  |  | [Longest Common Subsequence](https://leetcode.com/problems/longest-common-subsequence/) | 🟡 Medium | | | | ⬜ |

### Bit Manipulation

| # | Lesson | Problem | Difficulty | Approach | Time | Space | Status |
|---|---|---|---|---|---|---|---|
| 34 | [Bit Operations](https://neetcode.io/courses/dsa-for-beginners/34) | [Number of 1 Bits](https://leetcode.com/problems/number-of-1-bits/) | 🟢 Easy | | | | ⬜ |
|  |  | [Counting Bits](https://leetcode.com/problems/counting-bits/) | 🟢 Easy | | | | ⬜ |
|  |  | [Reverse Bits](https://leetcode.com/problems/reverse-bits/) | 🟢 Easy | | | | ⬜ |

## License

Code is released under the [MIT License](LICENSE). Course content belongs to [NeetCode](https://neetcode.io); this repository links to problems rather than reproducing them.
