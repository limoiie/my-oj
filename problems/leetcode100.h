//
// Created by limoi on 2018/2/28.
//
// LeetCode 100 Same Tree
//

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class SolutionLeetCode100 {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return __isSameTree(p, q);
    }

private:
    bool __isSameTree(TreeNode* p, TreeNode* q) {
        if (p == q) return true;
        if (p == nullptr || q == nullptr) return false;
        if (p->val != q->val) return false;
        return __isSameTree(p->left, q->left) &&
               __isSameTree(p->right, q->right);
    }
};
