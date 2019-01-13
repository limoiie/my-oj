//
// Created by limo on 2018/5/18.
//
// LeetCode065 valid number
//

#ifndef OJ_LEETCODE065_H
#define OJ_LEETCODE065_H

#include <string>
#include <vector>

using namespace std;

class SolutionLeetCode065 {
public:
    bool isNumber(string s) {
        trim(s);
        Status st = Q0;
        for (const auto c : s)
            if (QE == (st = move(st, c)))
                return false;
        return isEnd(st);
    }

private:
    enum Status {
        QE, Q0, Q1, Q2, Q3, Q4, Q5, Q6, Q7, Q8
    };

    const vector<Status> END_STATUS = { Q1, Q3, Q5, Q6 };

    void trim(string &str) {
        str.erase(0, str.find_first_not_of(' '));
        str.erase(str.find_last_not_of(' ') + 1);
    }

    inline
    bool isEnd(Status s) {
        for (const auto &es : END_STATUS)
            if (es == s)
                return true;
        return false;
    }

    inline
    bool isDigit(const char c) {
        return c >= '0' && c <= '9';
    }

    inline
    bool isSign(const char c) {
        return c == '+' || c == '-';
    }

    inline
    bool isExp(const char c) {
        return c == 'e';
    }

    inline
    bool isDot(const char c) {
        return c == '.';
    }

    Status move(const Status curr, const char c) {
        switch(curr) {
            case Q0:
                if (isDigit(c)) return Q1;
                if (isSign(c)) return Q2;
                if (isDot(c)) return Q7;
                break;
            case Q1:
                if (isDigit(c)) return Q1;
                if (isDot(c)) return Q3;
                if (isExp(c)) return Q4;
                break;
            case Q2:
                if (isDigit(c)) return Q1;
                if (isDot(c)) return Q7;
                break;
            case Q3:
                if (isExp(c)) return Q4;
                if (isDigit(c)) return Q5;
                break;
            case Q4:
                if (isDigit(c)) return Q6;
                if (isSign(c)) return Q8;
                break;
            case Q5:
                if (isExp(c)) return Q4;
                if (isDigit(c)) return Q5;
                break;
            case Q6:
                if (isDigit(c)) return Q6;
                break;
            case Q7:
                if (isDigit(c)) return Q5;
                break;
            case Q8:
                if (isDigit(c)) return Q6;
                break;
            case QE:break;
        }
        return QE;
    }

};

#endif //OJ_LEETCODE065_H
