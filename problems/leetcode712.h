
#ifndef OJ_LEETCODE712_H
#define OJ_LEETCODE712_H

#include "base.h"

class SolutionLeetCode712 {
public:
    int minimumDeleteSum(string s1, string s2) {
        auto const n = s1.size();
        auto const m = s2.size();

        int dp[n+1][m+1];
        memset(dp, 0, sizeof(dp));
        for (auto i = 0; i < n; ++i) {
            dp[i+1][0] = dp[i][0] + s1[i];
        }
        for (auto j = 0; j < m; ++j) {
            dp[0][j+1] = dp[0][j] + s2[j];
        }

        for (auto i = 0; i < n; ++i) {
            for (auto j = 0; j < m; ++j) {
                dp[i+1][j+1] = min(
                    dp[i+1][j] + s2[j],
                    dp[i][j+1] + s1[i]
                );
                if (s1[i] == s2[j]) {
                    dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j]);
                } else {
                    dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j]+s1[i]+s2[j]);
                }
            }
        }
        return dp[n+1][m+1];
    }
};

#endif // OJ_LEETCODE712_H
