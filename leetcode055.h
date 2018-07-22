//
// Created by limo on 2018/5/31.
//
// LeetCode055 jump game
//

#ifndef OJ_LEETCODE055_H
#define OJ_LEETCODE055_H

#include "base.h"

class SolutionLeetCode055 {
public:
    bool canJump(vector<int>& nums) {
        int pos = 0, top = 0;
        while (pos <= top && top < nums.size()) {
            top = max(top, pos + nums[pos]);
            ++pos;
        }
        return top + 1 >= nums.size();
    }
};

#endif //OJ_LEETCODE055_H
