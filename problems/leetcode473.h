//
// Created by limoi on 2018/x/x.
//
// LeetCode 473 matchsticks to square
//

#ifndef OJ_LEETCODE473_H
#define OJ_LEETCODE473_H

#include "base.h"

class SolutionLeetCode473 {
public:
    bool makesquare(vector<int> &nums) {
        const auto sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 0x3) return false;

        sort(nums.begin(), nums.end(), greater<>());
        memset(visited, 0, sizeof(visited));
        return make_square(nums, 0, 4, sum >> 2, sum >> 2);
    }

private:
    bool make_square(const vector<int> &nums, int s, int k, int r, int p) {
        if (k == 0) return true;

        for (int i = s; i < nums.size(); ++i) {
            int t = r-nums[i];
            if (visited[i] || t < 0) continue;

            visited[i] = true;
            if (t == 0) {
                if (make_square(nums, 0, k-1, p, p)) return true;
            } else {
                if (make_square(nums, i+1, k, t, p)) return true;
            }
            visited[i] = false;
        }
        return false;
    }

    bool visited[16];
};

#endif //OJ_LEETCODExxx_H
