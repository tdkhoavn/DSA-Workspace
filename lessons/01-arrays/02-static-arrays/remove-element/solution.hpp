// Remove Element
// https://leetcode.com/problems/remove-element/
//
// Approach: two indices: read every element, write the ones to keep at k
// Time:  O(n)
// Space: O(1)
#pragma once

#include <vector>

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        int k = 0;
        for (const int num : nums) {
            if (num != val) {
                nums[k] = num;
                k++;
            }
        }
        return k;
    }
};
