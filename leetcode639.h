//
// Created by limo on 2018/6/17.
//
// leetcode 639 decode ways II
//

#ifndef OJ_LEETCODE639_H
#define OJ_LEETCODE639_H

#include "base.h"

class SolutionLeetcode639 {
    const int MOD = 1000000000 + 7;
public:
    int numDecodings(string s) {
        if (s[0] == '0') return 0;

        long long int curr = 0, pre1 = 1, pre2 = s[0] == '*' ? 9 : 1;
        for (int i = 2; i <= s.size(); ++i) {
            char first = s[i-2], second = s[i-1];
            if (second == '*') curr = pre2 * 9;
            else if (second != '0') curr = pre2;
            else curr = 0;

            if (first == '*') {
                if (second == '*') curr += pre1 * 15;
                else if (second < '7') curr += pre1 * 2;
                else curr += pre1;
            } else if (first == '1') {
                if (second == '*') curr += 9 * pre1;
                else curr += pre1;
            } else if (first == '2') {
                if (second == '*') curr += 6 * pre1;
                else if (second < '7') curr += pre1;
            }

            pre1 = pre2;
            pre2 = curr % MOD;
        }

        return static_cast<int>(pre2);
    }

};

#endif //OJ_LEETCODE639_H
