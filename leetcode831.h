//
// Created by limo on 2018/6/1.
//
// leetcode 831 masking personal information
//

#ifndef OJ_LEETCODE831_H
#define OJ_LEETCODE831_H

#include "base.h"

class SolutionLeetCode831 {
public:
    string maskPII(string s) {
        return isEmailAddress(s) ? processEmailAddress(s) : processPhoneNumber(s);
    }

private:
    bool isEmailAddress(const string& s) {
        return s.find('@') < s.size();
    }

    string processEmailAddress(string& s) {
        lower(s);
        auto i = s.find('@');
        string mask = "a*****b" + s.substr(i);
        mask[0] = s[0];
        mask[6] = s[i-1];
        return mask;
    }

    string processPhoneNumber(const string& s) {
        string cs = cleanPhoneNumber(s);
        string country_code;
        if (cs.size() > 10) {
            country_code = "+" + string(cs.size()-10, '*') + "-";
        }
        return country_code + "***-***-" + cs.substr(cs.size()-4);
    }

    string cleanPhoneNumber(const string &s) {
        string t;
        for (auto c : s)
            if (isdigit(c))
                t.push_back(c);
        return t;
    }

    void lower(string &s) {
        for (auto &c : s) {
            if (isupper(c))
                c = static_cast<char>(tolower(c));
        }
    }

};

#endif //OJ_LEETCODE831_H
