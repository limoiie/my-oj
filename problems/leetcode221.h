//
// Created by limo on 2018/7/16.
//

#ifndef OJ_LEETCODE221_H
#define OJ_LEETCODE221_H

#include "base.h"

class SolutionLeetcode221 {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix.front().empty()) return 0;

        auto const m = matrix.size();
        auto const n = matrix.front().size();
        auto dp = vector<vector<int>>(m, vector<int>(n, 0));
        auto max_side = 0;

        for (auto i = 0; i < m; ++i) {
            dp[i][0] = matrix[i][0] - '0';
            max_side = max(max_side, dp[i][0]);
        }

        for (auto j = 0; j < n; ++j) {
            dp[0][j] = matrix[0][j] - '0';
            max_side = max(max_side, dp[0][j]);
        }

        for (auto i = 1; i < m; ++i) {
            for (auto j = 1; j < n; ++j) {
                if (matrix[i][j] == '1')
                    dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j]));
                max_side = max(max_side, dp[i][j]);
            }
        }
        return max_side * max_side;
    }
};

#endif //OJ_LEETCODE221_H
