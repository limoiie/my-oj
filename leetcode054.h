//
// Created by limo on 2018/5/30.
//
// Leetcode054 spiral matrix

#ifndef OJ_LEETCODE054_H
#define OJ_LEETCODE054_H

#include "base.h"

class SolutionLeetCode054 {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty() || matrix.front().empty()) return res;

        int row_u = 0;
        auto row_d = static_cast<int>(matrix.size() - 1);
        int col_l = 0;
        auto col_r = static_cast<int>(matrix.front().size() - 1);

        while (row_u <= row_d && col_l <= col_r) {
            for (auto i = col_l; i <= col_r; ++i)
                res.push_back(matrix[row_u][i]);
            ++row_u;

            for (auto i = row_u; i <= row_d; ++i)
                res.push_back(matrix[i][col_r]);
            --col_r;

            if (row_u <= row_d)
                for (auto i = col_r; i >= col_l; --i)
                    res.push_back(matrix[row_d][i]);
            --row_d;

            if (col_l <= col_r)
                for (auto i = row_d; i >= row_u; --i)
                    res.push_back(matrix[i][col_l]);
            ++col_l;
        }

        return res;
    }
};

#endif //OJ_LEETCODE054_H
