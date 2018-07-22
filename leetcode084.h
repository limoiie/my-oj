//
// Created by limo on 2018/5/31.
//
// LeetCode084 largest rectangle in histogram

#ifndef OJ_LEETCODE084_H
#define OJ_LEETCODE084_H

#include "base.h"

class SolutionLeetCode084 {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        vector<int> indexes;
        int res = 0;
        for (int i = 0; i < heights.size(); ++i) {
            while (!indexes.empty() && heights[indexes.back()] > heights[i]) {
                int height = heights[indexes.back()]; indexes.pop_back();
                int index = indexes.empty() ? -1 : indexes.back();
                res = max(res, height * (i-index-1));
            }
            indexes.push_back(i);
        }
        return res;
    }

};

#endif //OJ_LEETCODE084_H
