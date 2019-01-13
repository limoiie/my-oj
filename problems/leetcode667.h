//
// Created by limo on 2018/6/13.
//
// leetcode 667 beautiful arrangement II

#ifndef OJ_LEETCODE667_H
#define OJ_LEETCODE667_H

#include "base.h"

class SolutionLeetCode667 {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> test; test.reserve(static_cast<unsigned long>(n));
        for (int i = 1, j = n; i <= j; ) {
            if (k > 1) {
                test.push_back(k-- & 1 ? i++ : j--);
            } else
                test.push_back(i++);
        }
        return test;
    }
};

#endif //OJ_LEETCODE667_H
