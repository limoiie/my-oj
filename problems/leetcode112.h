//
// Created by limo on 2018/3/27.
//
// LeetCode112 Path Sum
//

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class SolutionLeetCode112 {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if (nullptr == root) return false;
        if (root->val == sum && nullptr != root->left && nullptr != root->right) return true;
        return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
    }
};
