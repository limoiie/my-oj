//
// Created by limo on 2018/6/2.
//
// leetcode789
//

#ifndef OJ_LEETCODE789_H
#define OJ_LEETCODE789_H

#include "base.h"

class SolutionLeetCode789 {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int max = abs(target[0]) + abs(target[1]);
        for (auto const &ghost : ghosts) {
            if (abs(ghost[0] - target[0]) + abs(ghost[1] - target[1]) <= max)
                return false;
        }
        return true;
    }
};

#endif //OJ_LEETCODE789_H
