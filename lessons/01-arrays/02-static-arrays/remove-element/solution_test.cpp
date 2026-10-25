#include "solution.hpp"

#include <algorithm>
#include <vector>

#include <gtest/gtest.h>

// Checks the result the same way the LeetCode judge does:
// k must equal the expected count, and the first k elements of nums,
// once sorted, must equal the expected elements (order does not matter).
void expectRemoved(std::vector<int> nums, int val, std::vector<int> expected) {
    const int k = Solution().removeElement(nums, val);

    ASSERT_EQ(k, static_cast<int>(expected.size()));
    std::sort(nums.begin(), nums.begin() + k);
    std::sort(expected.begin(), expected.end());
    EXPECT_EQ(std::vector<int>(nums.begin(), nums.begin() + k), expected);
}

TEST(RemoveElement, Example1) {
    expectRemoved({3, 2, 2, 3}, 3, {2, 2});
}

TEST(RemoveElement, Example2) {
    expectRemoved({0, 1, 2, 2, 3, 0, 4, 2}, 2, {0, 1, 3, 0, 4});
}

TEST(RemoveElement, EmptyArray) {
    expectRemoved({}, 1, {});
}

TEST(RemoveElement, ValNotPresent) {
    expectRemoved({1, 1, 2, 0, 1, 2}, 3, {1, 1, 2, 0, 1, 2});
}

TEST(RemoveElement, AllElementsEqualVal) {
    expectRemoved({1, 1, 1, 1, 1}, 1, {});
}

TEST(RemoveElement, ValOnlyAtStart) {
    expectRemoved({1, 2, 3, 2, 3}, 1, {2, 3, 2, 3});
}

TEST(RemoveElement, ValOnlyAtEnd) {
    expectRemoved({1, 2, 3, 2, 3, 4}, 4, {1, 2, 3, 2, 3});
}
