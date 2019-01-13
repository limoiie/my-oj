//
// Created by limoi on 2018/6/4.
//
// LeetCode 698 partiion to k equal sum subsets
//

#ifndef OJ_LEETCODE698_H
#define OJ_LEETCODE698_H

#include "base.h"

class SolutionLeetCode698 {
public:
  bool canPartitionKSubsets(vector<int> &nums, int k) {
    int s = sum(nums);
    if (k <= 0 || (s % k)) return false;
    memset(visited, 0, sizeof(visited));
    return canPartition(nums, s/k, k, 0, 0);
  }
  
private:
  int sum(vector<int> &nums) {
    int s = 0;
    for (auto const num : nums) s += num;
    return s;
  }

  bool canPartition(vector<int> &nums, const int p, const int k, const int i, const int n) {
    if (k == 1) return true;
    if (n == p) return canPartition(nums, p, k-1, 0, 0);
    for (int j = i; j < nums.size(); ++j) {
      if (visited[j] || n+nums[j] > p) continue;
      visited[j] = true;
      if (canPartition(nums, p, k, j+1, n+nums[j]))
        return true;
      visited[j] = false;
    }

    return false;
  }

  bool visited[16];
  
};

#endif //OJ_LEETCODE698_H
