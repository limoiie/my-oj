//
// Created by limo on 2018/3/16.
//
// LeetCode123 Best Time to Buy and Sell Stock III
//

#include <iostream>
#include <vector>

using namespace std;

class SolutionLeetCode123 {
public:
    int maxProfit(vector<int>& prices) {
        int buy1 = INT32_MIN, buy2 = INT32_MIN;
        int sell1 = 0, sell2 = 0;
        for (const auto price : prices) {
            sell2 = max(sell2, buy2 + price);
            buy2 = max(buy2, sell1 - price);
            sell1 = max(sell1, buy1 + price);
            buy1 = max(buy1, -price);
        }
        return sell2;
    }

};