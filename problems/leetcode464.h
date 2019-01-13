//
// Created by limo on 2018/6/9.
//
// leetcode 464 can i win
//

#ifndef OJ_LEETCODE464_H
#define OJ_LEETCODE464_H

#include "base.h"

class SolutionLeetCode464 {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (desiredTotal <= 0) return true;

        m = maxChoosableInteger;
        int sum = (m+1) * m >> 1;
        if (sum < desiredTotal) return false;
        if (sum == desiredTotal) return (m & 1) == 1;

        init();
        return canWin(0, desiredTotal);
    }

private:
    bool canWin(int state, int desiredTotal) {
        if (desiredTotal <= 0) return false;

        if (dp.count(state) == 0) {
            for (int i = 0; i < m; ++i) {
                if ((offset[i] & state) == 0) {
                    if (!canWin(state | offset[i], desiredTotal-i-1)) {
                        dp[state] = true;
                        return true;
                    }
                }
            }
            dp[state] = false;
        }
        return dp[state];
    }

    void init() {
        dp.clear();
        for (int i = 0; i < m; ++i) offset[i] = 1 << i;
    }

    unordered_map<int, bool> dp;
    int offset[32];
    int m;

};

#endif //OJ_LEETCODE464_H
