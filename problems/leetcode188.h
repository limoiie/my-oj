//
// Created by limo on 2018/6/3.
//

#ifndef OJ_LEETCODE188_H
#define OJ_LEETCODE188_H

#include "base.h"

class SolutionLeetCode188 {
public:
    int maxProfit(int k, vector<int>& prices) {
        auto const len = prices.size();
        if (k >= len / 2) return quick_solve(prices);

        int dp[k+1][len];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= k; ++i) {
            auto max_profit = -prices[0];
            for (int j = 1; j < len; ++j) { 
                dp[i][j] = max(dp[i][j-1], prices[j]+max_profit);
                max_profit = max(max_profit, dp[i-1][j-1]-prices[j]);
            }
        }
        return dp[k][len-1];
    }

private:
    int quick_solve(vector<int>& prices) {
        auto profit = 0;
        for (auto i = 1; i < prices.size(); ++i) {
            if (prices[i] > prices[i-1])
                profit += prices[i] - prices[i-1];
        }
        return profit;
    }

};

#endif //OJ_LEETCODE188_H
