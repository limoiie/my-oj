//
// Created by limo on 2018/3/15.
//
// LeetCode121 Best Time to Buy and Sell Stock
//

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class SolutionLeetCode121 {
public:
    int maxProfix(vector<int> &prices) {
        int maxPro = 0;
        int minPrice = INT_MAX;
        for (auto price : prices) {
            minPrice = min(minPrice, price);
            maxPro = max(maxPro, price - minPrice);
        }
        return maxPro;
    }
};