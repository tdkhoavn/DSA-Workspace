// Max Consecutive Ones
// https://leetcode.com/problems/max-consecutive-ones/
//
// Approach: single pass, track the current run and the best run seen so far
// Time:  O(n)
// Space: O(1)
#pragma once

#include <algorithm>
#include <vector>

class Solution {
public:
    int findMaxConsecutiveOnes(const std::vector<int>& nums) {
        int best = 0;
        int current = 0;

        for (const int num : nums) {
            if (num == 1) {
                current++;
                best = std::max(best, current);
            } else {
                current = 0;
            }
        }
        return best;
    }
};
