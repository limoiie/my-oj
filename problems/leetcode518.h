//
// Created by limo on 2019/1/30.
//

#ifndef OJ_LEETCODE528_H
#define OJ_LEETCODE528_H

#include "base.h"

class SolutionLeetcode518 {
public:
    int change(int const amount, vector<int> const& coins) {
        int dp[amount+1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;

        for (auto const coin : coins) {
            for (auto j = coin; j <= amount; ++j) {
                dp[j] += dp[j-coin];
            }
        }
        return dp[amount];
    }
};

#endif //OJ_LEETCODE528_H
