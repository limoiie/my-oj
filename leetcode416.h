//
// Created by limoi on 2018/x/x.
//
// LeetCode 416 partition equal subset sum
//

#ifndef OJ_LEETCODE416_H
#define OJ_LEETCODE416_H

#include "base.h"

class SolutionLeetCode416 {
 public:
  bool canPartition(vector<int> &nums) {
    int sum = getSum(nums);
    if (sum & 1) return false;
    
    sum >>= 1;
    bool dp[sum+1];
    memset(dp, 0, sizeof(dp));
    dp[0] = true;
    
    for (const auto& num : nums)
      for (int k = sum; k >= num; --k)
        dp[k] = dp[k] || dp[k-num];
    return dp[sum];
  }

 private:
  int getSum(vector<int> &nums) {
    int sum = 0;
    for (const auto num : nums) sum += num;
    return sum;
  }
  
};

#endif //OJ_LEETCODE416_H
