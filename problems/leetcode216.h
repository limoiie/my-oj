#ifndef LEETCODE216_H
#define LEETCODE216_H

#include <base.h>

class SolutionLeetCode216 {
 public:
  vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> res;
    vector<int> cont;
    search(res, cont, k, n, 1);
    return res;
  }

  void search(vector<vector<int>>& e, vector<int>& c, int k, int r, int t) {
    if (k == 0) {
      if (r == 0) e.push_back(c);
      return;
    }
    for (auto i = t; i <= r && i <= 9; ++i) {
      c.push_back(i);
      search(e, c, k - 1, r - i, i + 1);
      c.pop_back();
    }
  }
};

#endif