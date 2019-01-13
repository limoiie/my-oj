//
// Created by limo on 2018/6/7.
//
// leetcode 466 count the repetitions

#ifndef OJ_LEETCODE466_H
#define OJ_LEETCODE466_H

#include "base.h"

class SolutionLeetcode466 {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        vector<int> matched_rounds_after_round(s2.size()+1, -1);
        vector<int> matched_chars_after_round(s2.size()+1, -1);
        int period_start_round = -1;
        int period_end_round = -1;
        matched_rounds_after_round[0] = matched_chars_after_round[0] = 0;

        for (int r1 = 1, i2 = 0, r2 = 0; r1 <= s2.size() + 1; ++r1) {
            for (auto const c : s1) {
                if (c == s2[i2]) {
                    ++i2;
                    if (i2 == s2.size()) {
                        i2 = 0;
                        ++r2;
                    }
                }
            }

            for (int i = 0; i < r1; ++i) {
                if (matched_chars_after_round[i] == i2) {
                    period_start_round = i;
                    period_end_round = r1;
                    break;
                }
            }

            matched_rounds_after_round[r1] = r2;
            matched_chars_after_round[r1] = i2;

            if (period_start_round >= 0) break;
        }

        if (period_start_round >= n1)
            return matched_rounds_after_round[n1-1] / n2;

        const int period = period_end_round - period_start_round;
        const int rounds_per_period = matched_rounds_after_round[period_end_round] -
                matched_rounds_after_round[period_start_round];

        const int rounds = (n1 - period_start_round) / period * rounds_per_period +
                matched_rounds_after_round[(n1 - period_start_round) % period + period_start_round];

        return rounds / n2;
    }
};

#endif //OJ_LEETCODE466_H
