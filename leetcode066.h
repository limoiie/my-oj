//
// Created by limo on 2018/5/30.
//
// Leetcode066 Plus one
//

#include <iostream>
#include <vector>

using namespace std;

class SolutionLeetCode066 {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool flag = true;
        for (auto itr = digits.rbegin(); itr != digits.rend(); ++itr) {
            flag = (*itr += (flag ? 1 : 0)) == 10;
            if (flag) *itr = 0;
        }
        if (flag) digits.insert(digits.begin(), 1);
        return digits;
    }
};
