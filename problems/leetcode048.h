//
// Created by limoi on 2018/1/25.
//
// LeetCode 048 rotate image

#include <vector>
#include <algorithm>

using namespace std;

class SolutioinLeetCode048 {
public:
    void rotate(vector<vector<int>>& matrix) {
        flip(matrix);
        symmetry(matrix);
    }

private:
    void flip(vector<vector<int>>& matrix) {
        reverse(matrix.begin(), matrix.end());
    }

    void symmetry(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }

};