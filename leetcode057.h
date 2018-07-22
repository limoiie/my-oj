//
// Created by limo on 2018/6/1.
//
// leetcode 057 insert interval
//

#ifndef OJ_LEETCODE057_H
#define OJ_LEETCODE057_H

#include "base.h"

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class SolutionLeetCode057 {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
        auto itr = intervals.begin();
        while (itr != intervals.end() && itr->end < newInterval.start) res.push_back(*(itr++));

        if (itr == intervals.end()) {
            res.push_back(newInterval);
        } else {
            int e = newInterval.end, s = min(newInterval.start, itr->start);
            while (itr != intervals.end() && itr->start <= newInterval.end) e = max(e, (itr++)->end);
            res.emplace_back(s, e);
            while (itr != intervals.end()) res.push_back(*(itr++));
        }

        return res;
    }
};

#endif //OJ_LEETCODE057_H
