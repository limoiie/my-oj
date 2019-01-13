//
// Created by limo on 2018/6/1.
//
// leetcode892 consecutive numbers sum
//

#ifndef OJ_LEETCODE829_H
#define OJ_LEETCODE829_H

#include "base.h"

class SolutionLeetCode829 {
public:
    int consecutiveNumbersSum(int N) {
        int res = 0;
        int N2 = N << 1, NQ = static_cast<int>(sqrt(N2));
        if (NQ * NQ != N2) ++NQ;
        for (int i = 1; i < NQ; ++i)
            if ((N2 % i) == 0 && ((i & 1) == 1 || ((N2 / i) & 1) == 1))
                ++res;
        return res;
    }

};

#endif //OJ_LEETCODE829_H
