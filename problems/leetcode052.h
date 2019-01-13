//
// Created by limoi on 2018/3/1.
//
// LeetCode052 N Queens II
//

#include <vector>
#include <string>

using namespace std;

class SolutionLeetCode052 {
public:
    int totalNQueens(int n) {
        dim = static_cast<size_t>(n);
        __init();
        __solve();
        return res;
    }

private:
    size_t dim;
    int res;
    vector<int> flags[3];

    void __init() {
        res = 0;
        flags[0] = vector<int>(dim, 1);
        flags[1] = vector<int>(2*dim-1, 1);
        flags[2] = vector<int>(2*dim-1, 1);
    }

    void __solve(int r = 0) {
        if (r == dim) {
            ++res;
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
        flags[0][c] = flags[1][r+c] = flags[2][dim-1+c-r] = flag;
    }

};

