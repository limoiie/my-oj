//
// Created by limoi on 2018/3/2.
//
// LeetCode139 Word Break
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

class SolutionLeetCode139 {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        sort(wordDict.begin(), wordDict.end());

        bool dp[s.size()+1];
        memset(dp, false, sizeof(dp));
        dp[0] = true;
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                auto tmp = s.substr(j, i-j);
                if (dp[j] && contain(tmp, wordDict)) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }

private:
    bool contain(string& str, vector<string>& dict) {
        long lt = 0;
        long rt = dict.size() - 1;

        while (lt <= rt) {
            auto md = (lt + rt) >> 1;
            int compare = str.compare(dict[md]);
            if (compare == 0) {
                return true;
            } else if (compare < 0) {
                rt = md - 1;
            } else {
                lt = md + 1;
            }
        }
        return false;
    }

};
