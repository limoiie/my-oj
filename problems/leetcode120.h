//
// Created by limo on 2018/3/15.
//
// LeetCode120 Triangle
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class SolutionLeetCode120 {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        const auto total_level = triangle.size();
        auto dp(triangle.back());

        for (auto layer = total_level-1; layer > 0; --layer) {
            for (auto i = 0; i < layer; ++i) {
                dp[i] = min(dp[i], dp[i+1]) + triangle[layer-1][i];
            }
        }
        return dp[0];
    }

};
