//
// Created by limo on 2018/5/28.
//
// LeetCode097 interleaving string

#ifndef OJ_LEETCODE097_H
#define OJ_LEETCODE097_H

#include <iostream>
#include <string>
#include <memory.h>

using namespace std;

class SolutionLeetcode097 {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() + s2.length() == s3.length())
            return check(s1, s2, s3);
        return false;
    }

private:
    bool check(const string &s1, const string &s2, const string &s3) {
        bool dp[s1.size()+1][s2.size()+1];
        memset(dp, 0, sizeof(dp)); dp[0][0] = true;
        for (int i = 0; i <= s1.size(); ++i) {
            for (int j = 0; j <= s2.size(); ++j) {
                if (i != 0 && dp[i-1][j] && s1[i-1] == s3[i+j-1]) dp[i][j] = true;
                if (j != 0 && dp[i][j-1] && s2[j-1] == s3[i+j-1]) dp[i][j] = true;
            }
        }
        return dp[s1.size()][s2.size()];
    }

};

#endif //OJ_LEETCODE097_H
