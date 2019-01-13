//
// Created by limo on 2018/7/16.
//

#ifndef OJ_LEETCODE169_H
#define OJ_LEETCODE169_H

#include "base.h"

class SolutionLeetcode169 {
public:
    int majorityElement(vector<int> &nums) {
        int cnt = 0, maj = nums.front();
        for (const auto num : nums) {
            if (maj == num) ++cnt;
            else if (cnt) --cnt;
            else {
                maj = num;
                cnt = 1;
            }
        }
        return maj;
    }
};

#endif //OJ_LEETCODE169_H
