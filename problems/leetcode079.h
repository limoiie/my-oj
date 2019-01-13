//
// Created by limoi on 2018/2/28.
//
// LeetCode 079 Word Search
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class SolutionLeetCode079 {
    using mat2d_t = vector<vector<char>>;
public:
    bool exist(mat2d_t & board, string word) {
        r = board.size();
        l = board[0].size();

        for (int i = 0; i < r; ++i)
            for (int j = 0; j < l; ++j)
                if (find(i, j, board, word, 0))
                    return true;
        return false;
    }

private:
    size_t r, l;

    bool find(int x, int y, mat2d_t& board, string& word, int loop) {
        if (loop == word.length()) return true;
        if (x < 0 || y < 0 || x == r || y == l) return false;
        if (board[x][y] != word[loop]) return false;

        board[x][y] += 122;
        bool exist = find(x+1, y, board, word, loop+1) ||
                     find(x, y+1, board, word, loop+1) ||
                     find(x-1, y, board, word, loop+1) ||
                     find(x, y-1, board, word, loop+1);
        board[x][y] -= 122;
        return exist;
    }

};
