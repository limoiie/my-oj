//
// Created by limo on 2018/6/21.
//
// leetcode 629 k inverse pairs array
//

#ifndef OJ_LEETCODE629_H
#define OJ_LEETCODE629_H

#include "base.h"

class SolutionLeetcode629 {
    const int MOD = static_cast<const int>(1e9 + 7);
public:
    int kInversePairs(int n, int k) {
        int dp[n+1][k+1]; memset(dp, 0, sizeof(dp));
        for (int i = 0; i <= n; ++i) dp[i][0] = 1;

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= min(k, i*(i-1)/2); ++j) {
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
                if (j >= i) dp[i][j] = dp[i][j] - dp[i-1][j-i];
                dp[i][j] = (dp[i][j] % MOD + MOD) % MOD;
            }
        }

        return dp[n][k];
    }
};

#endif //OJ_LEETCODE629_H
