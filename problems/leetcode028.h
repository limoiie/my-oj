//
// Created by limo on 2018/5/18.
//
// LeetCode28 implement strStr()
//

#ifndef OJ_LEETCODE028_H
#define OJ_LEETCODE028_H

#include <string>
#include <vector>

using namespace std;

class SolutionLeetCode028 {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        constructNext(needle);
        return match(haystack, needle);
    }

private:
    vector<int> next;

    void constructNext(const string &ptn) {
        next = vector<int>(ptn.size(), -1);
        for (int i = 0; i < ptn.size(); ++i) {
            int cur = i - 1;
            while (cur >= 0) {
                cur = next[cur];
                if (ptn[cur + 1] == ptn[i]) {
                    next[i] = cur + 1;
                    break;
                }
            }
        }
    }

    int match(const string &str, const string &ptn) {
        int i = 0, k = 0;
        while (i < str.size()) {
            if (str[i] != ptn[k]) {
                k = k - 1;
                while (k >= 0) {
                    k = next[k];
                    if (ptn[k+1] == str[i]) {
                        ++k; break;
                    }
                }
            }
            ++k, ++i;
            if (k == ptn.size())
                return i - k;
        }
        return -1;
    }

};

#endif //OJ_LEETCODE028_H
