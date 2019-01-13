//
// Created by limo on 11/6/2018.
//

#ifndef OJ_LEETCODE303_H
#define OJ_LEETCODE303_H

#include "base.h"

class SolutionLeetcode303 {
    class NumArray {
    public:
        NumArray(vector<int> nums) {
            sums.swap(nums);
            for (int i = 1; i < sums.size(); ++i) {
                sums[i] += sums[i-1];
            }
        }

        int sumRange(int i, int j) {
            return i <= 0 ? sums[j] : sums[j] - sums[i];
        }

    private:
        vector<int> sums;

    };
};

#endif //OJ_LEETCODE303_H
