//
// Created by limoi on 2018/x/x.
//
// LeetCode 494 target sum
//

#ifndef OJ_LEETCODE494_H
#define OJ_LEETCODE494_H

#include "base.h"

class SolutionLeetCode494 {
  /* my version, ugly
 public:
  int findTargetSumWays(vector<int> &nums, int S) {
    int sum = 0;
    for (const auto &num : nums) sum += num;
    if (S > sum || S < -sum) return 0;

    const int d_sum = (sum << 1) + 1;
    int dp[2][d_sum];
    memset(dp, 0, sizeof(dp));
    dp[0][sum] = 1;

    bool f = false;
    for (const auto n : nums) {
      f = !f;
      int *curr = dp[f?0:1], *next = dp[f?1:0];
      for (int i = 0; i < d_sum; ++i) {
        if (curr[i]) {
          next[i-n] += curr[i];
          next[i+n] += curr[i];
        }
      }
      memset(dp[f?0:1], 0, sizeof(int)*d_sum);
    }
    return dp[f?1:0][sum+S];
  }
  */
 public:
  int findTargetSumWays(vector<int>& nums, int s) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    return sum < s || (s + sum) & 1 ? 0 : subsetSum(nums, (s + sum) >> 1); 
  }   
  
  int subsetSum(vector<int>& nums, int s) {
    int dp[s+1]; memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int n : nums)
      for (int i = s; i >= n; i--)
        dp[i] += dp[i-n];
    return dp[s];
  }
  
};

#endif //OJ_LEETCODExxx_H
