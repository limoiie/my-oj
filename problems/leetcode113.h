//
// Created by limo on 2018/3/28.
//
// LeetCode113 Path Sum II
//

#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class SolutionLeetCode113 {
public:
    vector<vector<int>> pathSum(TreeNode *root, int sum) {
        vector<vector<int>> paths;
        vector<int> path;
        dive(root, sum, path, paths);
        return paths;
    }

private:
    void dive(TreeNode *curr, int remain, vector<int>& path, vector<vector<int>>& paths) {
        if (curr == nullptr) return;
        path.push_back(curr->val);
        if (curr->val == remain && !(curr->left) && !(curr->right))
            paths.push_back(path);
        dive(curr->left, remain-curr->val, path, paths);
        dive(curr->right, remain-curr->val, path, paths);
        path.pop_back();
    }

};