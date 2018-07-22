//
// Created by limo on 2018/6/1.
//
// LeetCode830 positioin of large groups
//

#ifndef OJ_LEETCODE830_H
#define OJ_LEETCODE830_H

#include "base.h"

class SolutionLeetCode830 {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> res;
        if (s.size() < 3)
            return res;

        s.push_back('A');

        int max_l = 3, l = 0;
        char c = s[0];
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] != c) {
                if (i >= max_l + l)
                    res.emplace_back(vector<int>{l, i-1});
                c = s[l = i];
            }
        }

        s.pop_back();
        return res;
    }
};

#endif //OJ_LEETCODE830_H
