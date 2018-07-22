//
// Created by limo on 2018/6/21.
//
// leetcode 670 maximum swap

#ifndef OJ_LEETCODE670_H
#define OJ_LEETCODE670_H

#include "base.h"

class SolutionLeetCode670 {
public:
    int maximumSwap(int n) {
        string num = to_string(n);
        unordered_map<char, int> chars;
        for (int i = 0; i < num.size(); ++i) chars[num[i]] = i;

        for (int i = 0; i < num.size(); ++i) {
            for (char c = '9'; c > num[i]; --c) {
                if (chars[c] > i) {
                    swap(num[i], num[chars[c]]);
                    return stoi(num);
                }
            }
        }

        return n;
    }

public:
    int maximumSwap2(int num) {
        return process(to_string(num));
    }

private:
    int process(string num) {
        string sorted_num = num;
        sort(sorted_num.begin(), sorted_num.end(), greater<>());
        for (int i = 0; i < num.size(); ++i) {
            if (num[i] != sorted_num[i]) {
                for (auto j = static_cast<int>(num.size() - 1); j > i; --j) {
                    if (num[j] == sorted_num[i]) {
                        swap(num[i], num[j]);
                        break;
                    }
                }
                break;
            }
        }
        return stoi(num);
    }

};

#endif //OJ_LEETCODE670_H
