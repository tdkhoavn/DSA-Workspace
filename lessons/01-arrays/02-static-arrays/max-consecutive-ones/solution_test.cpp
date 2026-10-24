#include "solution.hpp"

#include <vector>

#include <gtest/gtest.h>

TEST(MaxConsecutiveOnes, AllOnes) {
    std::vector<int> nums = {1, 1, 1};
    EXPECT_EQ(Solution().findMaxConsecutiveOnes(nums), 3);
}

TEST(MaxConsecutiveOnes, Example1) {
    std::vector<int> nums = {1, 1, 0, 1, 1, 1};
    EXPECT_EQ(Solution().findMaxConsecutiveOnes(nums), 3);
}

TEST(MaxConsecutiveOnes, Example2) {
    std::vector<int> nums = {1, 0, 1, 1, 0, 1};
    EXPECT_EQ(Solution().findMaxConsecutiveOnes(nums), 2);
}

TEST(MaxConsecutiveOnes, LongestRunAtStart) {
    std::vector<int> nums = {1, 1, 1, 0, 1};
    EXPECT_EQ(Solution().findMaxConsecutiveOnes(nums), 3);
}

TEST(MaxConsecutiveOnes, AllZeros) {
    std::vector<int> nums = {0, 0, 0};
    EXPECT_EQ(Solution().findMaxConsecutiveOnes(nums), 0);
}

TEST(MaxConsecutiveOnes, SingleZero) {
    std::vector<int> nums = {0};
    EXPECT_EQ(Solution().findMaxConsecutiveOnes(nums), 0);
}

TEST(MaxConsecutiveOnes, SingleOne) {
    std::vector<int> nums = {1};
    EXPECT_EQ(Solution().findMaxConsecutiveOnes(nums), 1);
}
