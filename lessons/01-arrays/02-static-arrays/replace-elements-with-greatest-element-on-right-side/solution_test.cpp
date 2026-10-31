#include "solution.hpp"

#include <gtest/gtest.h>
#include <vector>

namespace {

// Checks both approaches on the same input.
void expectReplaced(std::vector<int> arr, const std::vector<int>& expected) {
    Solution s;
    EXPECT_EQ(s.replaceElementsBruteForce(arr), expected) << "brute force";
    EXPECT_EQ(s.replaceElements(arr), expected) << "reverse scan";
}

}  // namespace

TEST(ReplaceElementsWithGreatestElementOnRightSide, Example1) {
    expectReplaced({2, 4, 5, 3, 1, 2}, {5, 5, 3, 2, 2, -1});
}

TEST(ReplaceElementsWithGreatestElementOnRightSide, Example2) {
    expectReplaced({3, 3}, {3, -1});
}

TEST(ReplaceElementsWithGreatestElementOnRightSide, SingleElement) {
    expectReplaced({7}, {-1});
}

TEST(ReplaceElementsWithGreatestElementOnRightSide, DecreasingArray) {
    expectReplaced({5, 4, 3, 2, 1}, {4, 3, 2, 1, -1});
}
