//
// Created by limo on 2018/7/22.
//

#ifndef OJ_LEETCODE036_H
#define OJ_LEETCODE036_H

#include "base.h"

class SolutionLeetcode036 {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < N; ++i) {
            if (!isColValid(board, i) ||
                !isRowValid(board, i) ||
                !isBoxValid(board, i))
                return false;
        }
        return true;
    }

private:
    bool isColValid(const vector<vector<char>>& board, int col) {
        int flag = 0;
        for (int i = 0; i < N; ++i) {
            auto c = board[i][col];
            if (c != '.') {
                if (isSet(flag, c-'0')) return false;
                set(flag, c-'0');
            }
        }
        return true;
    }

    bool isRowValid(const vector<vector<char>>& board, int row) {
        int flag = 0;
        for (int i = 0; i < N; ++i) {
            auto c = board[row][i];
            if (c != '.') {
                if (isSet(flag, c-'0')) return false;
                set(flag, c-'0');
            }
        }
        return true;
    }

    bool isBoxValid(const vector<vector<char>>& board, int box) {
        int flag = 0;
        int row = (box / 3) * 3, col = (box % 3) * 3;
        for (int i = row, k = 0; i < row+3; ++i) {
            for (int j = col; j < col+3; ++j, ++k) {
                auto c = board[i][j];
                if (c != '.') {
                    if (isSet(flag, c-'0')) return false;
                    set(flag, c-'0');
                }
            }
        }
        return true;
    }

    inline
    void set(int &val, int bit) {
        val |= (1 << bit);
    }

    inline
    bool isSet(int val, int bit) {
        return static_cast<bool>(val & (1 << bit));
    }

    const int N = 9;

};

#endif //OJ_LEETCODE036_H
