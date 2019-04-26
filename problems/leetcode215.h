//
// Created by limo on 2018/7/16.
//

#ifndef OJ_LEETCODE215_H
#define OJ_LEETCODE215_H

#include "base.h"

class SolutionLeetcode215 {
public:
    int findKthLargest(vector<int> &nums, int k) {
        nth_element(nums.begin(), nums.begin()+k-1, nums.end(), greater<int>());
        return nums[k-1];
    }
};

#endif //OJ_LEETCODE215_H
