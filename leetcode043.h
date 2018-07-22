//
// Created by limo on 2018/6/2.
//
// leetcode043 multiply strings
//

#ifndef OJ_LEETCODE043_H
#define OJ_LEETCODE043_H

#include "base.h"

class SolutionLeetCode043 {
public:
    string multiply(string num1, string num2) {
        const auto N = num1.size() + num2.size();
        int pos[N] = {0};
        for (int i = static_cast<int>(num1.size()) - 1; i >= 0; --i) {
            for (int j = static_cast<int>(num2.size()) - 1; j >= 0; --j) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int in = i + j, cur = i + j + 1;
                int sum = mul + pos[cur];

                pos[cur] = sum % 10;
                pos[in] += sum / 10;
            }
        }

        string product;
        for (int i = 0, f = 0; i < N; ++i)
            if (f || (f = !product.empty() || pos[i]))
                product.push_back(static_cast<char>(pos[i] + '0'));
        return product.empty() ? "0" : product;
    }

};

#endif //OJ_LEETCODE043_H
