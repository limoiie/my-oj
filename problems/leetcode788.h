//
// Created by limo on 2018/6/2.
//
// leetcode788
//

#ifndef OJ_LEETCODE788_H
#define OJ_LEETCODE788_H

#include "base.h"

class SolutionLeetCode788 {
public:
    // method 1
    int rotatedDigits(int N) {
        int count = 0, dp[N + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i <= N; ++i) {
            if (i < 10) {
                if (i == 0 || i == 1 || i == 8) dp[i] = 1;
                else if (i == 2 || i == 5 || i == 6 || i == 9) {
                    dp[i] = 2;
                    count++;
                }
            } else {
                int a = dp[i/10], b = dp[i%10];
                if (a == 1 && b == 1) dp[i] = 1;
                else if (a >= 1 && b >= 1) {
                    dp[i] = 2;
                    ++count;
                }
            }
        }
        return count;
    }

private:
    // method 2
    int rotatedDigits2(int N, bool f = false) {
        if (N < 10) return f ? c[N] : b[N];

        int base, bits, high;
        getBaseAndBits(N, base, bits, high);

        auto p7 = static_cast<int>(pow(7, bits - 1));
        auto p3 = static_cast<int>(pow(3, bits - 1));

        int x = p7 * c[high-1];
        if (!e[high]) x += rotatedDigits2(N % base, f || d[high]);
        return f ? x : x - p3 * a[high-1];
    }

    void getBaseAndBits(int N, int &base, int &bits, int &high) {
        base = bits = 1, high = N;
        while (high >= 10)
            base *= 10, ++bits, high /= 10;
    }

    int a[10] = {1, 2, 2, 2, 2, 2, 2, 2, 3, 3};
    int b[10] = {0, 0, 1, 1, 1, 2, 3, 3, 3, 4};
    int c[10] = {1, 2, 3, 3, 3, 4, 5, 5, 6, 7};
    int d[10] = {0, 0, 1, 0, 0, 1, 1, 0, 0, 1};
    int e[10] = {0, 0, 0, 1, 1, 0, 0, 1, 0, 0};

};
#endif //OJ_LEETCODE788_H
