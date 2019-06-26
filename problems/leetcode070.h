#ifndef LEETCODE070_H
#define LEETCODE070_H

#include "base.h"

class SolutionLeetCode070 {
public:
    int climbStairs(int n) {
        int dp[n+1];
        dp[0] = 1, dp[1] = 1;
        for (auto i = 2; i <= n; ++i) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }

};

#endif