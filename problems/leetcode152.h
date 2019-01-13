//
// Created by limo on 2018/5/18.
//
// LeetCode152 maximum product sub-array

#ifndef OJ_LEETCODE152_H
#define OJ_LEETCODE152_H

#include <vector>

using namespace std;

class SolutionLeetCode152 {
public:
    int maxProduct(vector<int> &nums) {
        if (nums.empty())
            return 0;
        int max_p = 1, min_p = 1, res = nums[0];
        for (const auto &num : nums) {
            int tmp = max_p;
            max_p = max(num, max(num*min_p, num*tmp));
            min_p = min(num, min(num*min_p, num*tmp));
            res = max(max_p, res);
        }
        return res;
    }

};

#endif //OJ_LEETCODE152_H
