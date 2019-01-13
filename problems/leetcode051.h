//
// Created by limoi on 2018/3/1.
//
// LeetCode051 N Queens
//

#include <vector>
#include <string>

using namespace std;

class SolutionLeetCode051 {
public:
    vector<vector<string>> solveNQueens(int n) {
        dim = static_cast<size_t>(n);
        __init();
        __solve();
        return res;
    }

private:
    size_t dim;
    vector<vector<string>> res;
    vector<int> flags[3];
    vector<string> board;

    void __init() {
        res.clear();
        flags[0] = vector<int>(dim, 1);
        flags[1] = vector<int>(2*dim-1, 1);
        flags[2] = vector<int>(2*dim-1, 1);
        board = vector<string>(dim, string(dim, '.'));
    }

    void __solve(int r = 0) {
        if (r == dim) {
            res.push_back(board);
            return;
        }

        for (int c = 0; c < dim; ++c) {
            if (__isValid(r, c)) {
                __setFlag(r, c, false);
                __solve(r + 1);
                __setFlag(r, c, true);
            }
        }
    }

    bool __isValid(int r, int c) {
        return flags[0][c] && flags[1][r+c] && flags[2][dim-1+c-r];
    }

    void __setFlag(int r, int c, bool flag) {
        board[r][c] = flag ? '.' : 'Q';
        flags[0][c] = flags[1][r+c] = flags[2][dim-1+c-r] = flag;
    }

};