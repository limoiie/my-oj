//
// Created by limo on 2018/6/16.
//
// leetcode 546 remove boxes
//

#ifndef OJ_LEETCODE546_H
#define OJ_LEETCODE546_H

#include "base.h"

class SolutionLeetcode546 {
public:
    int removeBoxes(vector<int> &boxes) {
        auto n = static_cast<int>(boxes.size());
        int dp[n][n][n];
        memset(dp, 0, sizeof(dp));

        for (int i = 0; i < n; ++i)
            for (int k = 0; k <= i; ++k)
                dp[i][i][k] = (k+1) * (k+1);

        for (int l = 1; l < n; ++l) {
            for (int j = l; j < n; ++j) {
                int i = j - l;
                for (int k = 0; k <= i; ++k) {
                    int candi = (k+1) * (k+1) + dp[i+1][j][0];
                    for (int m = i+1; m <= j; ++m)
                        if (boxes[m] == boxes[i])
                            candi = max(candi, dp[i+1][m-1][0] + dp[m][j][k+1]);
                    dp[i][j][k] = candi;
                }
            }
        }

        return n == 0 ? 0 : dp[0][n-1][0];
    }

};

#endif //OJ_LEETCODE546_H
