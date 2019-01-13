//
// Created by limo on 2018/6/2.
//
// leetcode058 length of last word
//

#ifndef OJ_LEETCODE058_H
#define OJ_LEETCODE058_H

#include "base.h"

class SolutionLeetCode058 {
public:
    int lenghtOfLastWord(string s) {
        s = " " + s;
        auto e = s.find_last_not_of(' ');
        auto i = s.find_last_of(' ', e);
        if (i < s.size() && e < s.size())
            return static_cast<int>(s.substr(i + 1, e - i).length());
        return 0;
    }

};

#endif //OJ_LEETCODE058_H
