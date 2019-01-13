//
// Created by limoi on 2018/3/1.
//
// LeetCode101 Symmetric tree
//

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int n) : val(n), left(nullptr), right(nullptr) {}
};

class SolutionLeetCode101 {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return __isSymmetric(root->left, root->right);
    }

private:
    bool __isSymmetric(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right == nullptr) return true;
        if (left == nullptr || right == nullptr) return false;
        if (left->val != right->val) return false;
        return __isSymmetric(left->left, right->right) &&
               __isSymmetric(left->right, right->left);
    }
};
