//
// Created by limo on 2018/6/21.
//
// leetcode 312 burst balloons
//

#ifndef OJ_LEETCODE312_H
#define OJ_LEETCODE312_H

#include "base.h"

class SolutionLeetcode312 {
public:
    int maxCoins(vector<int> &nums) {
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        int dp[nums.size()][nums.size()]; memset(dp, 0, sizeof(dp));

        for (int j = 0; j < nums.size(); ++j) {
            for (int i = j-1; i >= 0; --i) {
                int max_coins = 0;
                for (int k = i+1; k < j; ++k)
                    max_coins = max(max_coins, dp[i][k] + dp[k][j] + nums[i] * nums[j] * nums[k]);
                dp[i][j] = max_coins;
            }
        }
        return dp[0][nums.size()-1];
    }

};

#endif //OJ_LEETCODE312_H
