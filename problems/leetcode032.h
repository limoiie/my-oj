//
// Created by limo on 11/6/2018.
//

#ifndef OJ_LEETCODE032_H
#define OJ_LEETCODE032_H

#include "base.h"

class SolutionLeetcode032 {
public:
    int longestValidParentheses(string const& s) {
        int max_len = 0;
        stack<int> stk;
        for (auto i = 0; i < s.size(); ++i) {
            if (')' == s[i] && !stk.empty()) {
                stk.pop();
                if (stk.empty()) {
                    max_len = max(max_len, i+1);
                } else {
                    max_len = max(max_len, i-stk.top());
                }
            } else {
                stk.push(i);
            }
        }

        return max_len;
    }
};

#endif //OJ_LEETCODE032_H
