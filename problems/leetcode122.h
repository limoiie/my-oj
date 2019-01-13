//
// Created by limo on 2018/3/16.
//
// LeetCode122 Best Time to Buy and Sell Stock II
//

#include <iostream>
#include <vector>

using namespace std;

class SolutionLeetCode122 {
public:
    int maxProfit(vector<int> &prices) {
        int res = 0;
        for (auto i = 1; i < prices.size(); ++i) {
            if (prices[i] > prices[i-1])
                res += prices[i] - prices[i-1];
        }
        return res;
    }

};
