// Replace Elements With Greatest Element On Right Side
// https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/
//
// Approach: Walk from right to left carrying the largest value seen so far;
//           write it into arr[i] first, then fold the old arr[i] into it.
// Time:  O(n)
// Space: O(1) extra (in place; returning the vector copies it as the output)
//
// Brute force (replaceElementsBruteForce): O(n^2) time, O(n) for the result.

#pragma once
#include <algorithm>
#include <vector>

class Solution {
public:
    static std::vector<int> replaceElements(std::vector<int>& arr) {
        int rightMax = -1;
        for (std::size_t i = arr.size(); i-- > 0;) {
            const int currentVal = arr[i];
            arr[i] = rightMax;
            rightMax = std::max(rightMax, currentVal);
        }
        return arr;
    }

    static std::vector<int> replaceElementsBruteForce(const std::vector<int>& arr) {
        std::vector<int> result(arr.size());
        for (std::size_t i = 0; i < arr.size(); i++) {
            int max = -1;
            for (std::size_t k = i + 1; k < arr.size(); k++) {
                max = std::max(max, arr[k]);
            }
            result[i] = max;
        }

        return result;
    }
};
