//
// Created by limoi on 2018/1/25.
//
// LeetCode 010 regular expression matching

#ifndef OJ_LEETCODE041_H
#define OJ_LEETCODE041_H

#include "base.h"

class SolutionLeetCode041 {
public:
    int firstMissingPositive(vector<int>& nums) {
        auto const n = nums.size();
        for (auto i = 0; i < n; ++i) {
            if (nums[i] > 0 && nums[i] <= n) {
                if (nums[i] != nums[nums[i]-1]) {
                    std::swap(nums[i], nums[nums[i]-1]);
                    i = i - 1;
                }
            }
        }
        for (auto i = 0; i < n; ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return n + 1;
    }

};

#endif //OJ_LEETCODE041_H
