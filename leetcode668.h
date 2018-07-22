//
// Created by limo on 2018/6/13.
//
// leetcode 668 kth smallest number in multiplication table
//

#ifndef OJ_LEETCODE668_H
#define OJ_LEETCODE668_H

#include "base.h"

class SolutionLeetCode668 {
public:
    int findKthNumber(int m, int n, int k) {
        int l = 0, r = m*n;
        while (l <= r) {
            int test = (l + r) >> 1;
            if (noLessThanKth(m, n, k, test))
                r = test - 1;
            else l = test + 1;
        }
        return l;
    }

private:
    bool noLessThanKth(int m, int n, int k, int test) {
        int countNumsLEThanTest = 0;
        for (int i = 1; i <= m && i <= test; ++i)
            countNumsLEThanTest += min(n, test / i);
        return countNumsLEThanTest >= k;  // this means test is the kth number or bigger
    }

};

#endif //OJ_LEETCODE668_H
