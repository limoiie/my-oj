//
// Created by limo on 2018/6/15.
//
// leetcode 664
//

#ifndef OJ_LEETCODE664_H
#define OJ_LEETCODE664_H

#include "base.h"

class SolutionLeetcode664 {
public:
    int strangePrinter(string s) {
        if (s.size() < 2) return static_cast<int>(s.size());

        vector<int> pre, x(256, -1);
        for (int i = 0; i < s.size(); ++i) {
            pre.push_back(x[s[i]]);
            x[s[i]] = i;
        }

        int dp[s.size()][s.size()];
        memset(dp, 0, sizeof(dp));

        for (int d = 0; d < s.size(); ++d)
            dp[d][d] = 1;

        for (int d = 1; d < s.size(); ++d) {
            for (int b = 0; b < s.size() - d; ++b) {
                int candi = dp[b][b+d-1] + 1;
                int t = pre[b+d];
                while (t >= b) {
                    candi = min(candi, dp[b][t]+dp[t+1][b+d-1]);
                    t = pre[t];
                }
                dp[b][b+d] = candi;
            }
        }
        return dp[0][s.size()-1];
    }
};

#endif //OJ_LEETCODE664_H
