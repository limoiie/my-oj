//
// Created by limo on 2018/5/30.
//
// LeetCode088 Merge sorted array
//

#ifndef OJ_LEETCODE088_H
#define OJ_LEETCODE088_H

#include <iostream>
#include <vector>

using namespace std;

class SolutionLeetCode088 {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int l = m + n;

        auto dst_start = nums1.rbegin() + nums1.size() - l;
        auto src1_start = nums1.rbegin() + nums1.size() - m;
        auto src2_start = nums2.rbegin();
        auto src1_end = nums1.rend();
        auto src2_end = nums2.rend();

        while (src1_start != src1_end && src2_start != src2_end) {
            if (*src1_start < *src2_start) *(dst_start++) = *(src2_start++);
            else *(dst_start++) = *(src1_start++);
        }

        while (src1_start != src1_end) *(dst_start++) = *(src1_start++);
        while (src2_start != src2_end) *(dst_start++) = *(src2_start++);
    }

};

#endif //OJ_LEETCODE088_H
