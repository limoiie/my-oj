//
// Created by limo on 2018/6/1.
//
// leetcode 828
//

#ifndef OJ_LEETCODE828_H
#define OJ_LEETCODE828_H

#include "base.h"

class SolutionLeetCode828 {
public:
    int uniqueLetterString(string S) {
        int res = 0, mod = static_cast<int>(pow(10, 9) + 7), rd[26][2];
        memset(rd, -1, sizeof(rd));

        auto update = [&](int c, int i)->void {
            res = (res % mod) + (i - rd[c][1]) * (rd[c][1] - rd[c][0]);
            rd[c][0] = rd[c][1];
            rd[c][1] = i;
        };
        for (int i = 0; i < S.size(); ++i)
            update(S[i]-'A', i);
        for (int i = 0; i < 26; ++i)
            update(i, static_cast<int>(S.size()));
        return res % mod;
    }
};

#endif //OJ_LEETCODE828_H
