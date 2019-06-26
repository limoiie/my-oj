//
// Created by limo on 2018/7/16.
//

#ifndef OJ_LEETCODE218_H
#define OJ_LEETCODE218_H

#include "base.h"

class SolutionLeetcode169 {
  using side_t = std::pair<int, int>;
  class PriorityQueue {
    priority_queue<int> pq;
    unordered_map<int, int> removed;

   public:
    void push(int const val) { pq.push(val); }
    void remove(int const val) { ++removed[val]; }
    int peek() {
      while (removed[pq.top()] > 0) {
        --removed[pq.top()];
        pq.pop();
      }
      return pq.top();
    }
  };

 public:
  vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    auto const n = buildings.size();
    vector<side_t> heights;
    for (auto i = 0; i < n; ++i) {
      auto const& building = buildings[i];
      heights.emplace_back(building[0], -building[2]);
      heights.emplace_back(building[1], building[2]);
    }
    sort(heights.begin(), heights.end());

    vector<vector<int>> outputs;

    PriorityQueue pq;
    pq.push(0);

    auto prev_height = 0;
    for (auto const& side : heights) {
      if (side.second < 0) {
        pq.push(-side.second);
      } else {
        pq.remove(side.second);
      }

      auto const curr_height = pq.peek();
      if (prev_height != curr_height) {
        outputs.push_back({side.first, curr_height});
        prev_height = curr_height;
      }
    }
    return outputs;
  }
};

#endif  // OJ_LEETCODE218_H
