//
// Created by limo on 2018/7/16.
//

#ifndef OJ_LEETCODE347_H
#define OJ_LEETCODE347_H

#include "base.h"

class SolutionLeetcode347 {
public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        map<int, int> cnt_map;
        for (const auto &num : nums) {
            ++cnt_map[num];
        }

        vector<vector<int>> buckets(nums.size()+1, vector<int>{});
        for (const auto &p : cnt_map) {
            buckets[p.second].push_back(p.first);
        }

        vector<int> res;
        for (auto itr = buckets.rbegin(); itr != buckets.rend(); ++itr) {
            for (const auto &num : *itr) {
                res.push_back(num);
                if (--k == 0) return res;
            }
        }
        return res;
    }
};

#endif //OJ_LEETCODE347_H
