//
// Created by limo on 2018/6/1.
//
// leetcode099 Recover binary search tree

#ifndef OJ_LEETCODE099_H
#define OJ_LEETCODE099_H

#include "base.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class SolutionLeetCode099 {
public:
    void recoverTree(TreeNode* root) {
        morrisRecover(root);
    }

private:
    TreeNode *first, *second;
    void morrisRecover(TreeNode* root) {
        TreeNode *cur = root, *pre = nullptr, *tmp = nullptr;
        first = second = nullptr;

        auto inorder_emit = [this, &pre](TreeNode *& cur)->void {
            if (pre != nullptr && pre->val > cur->val) {
                if (first == nullptr) first = pre;
                second = cur;
            }
            pre = cur;
        };

        while (cur != nullptr) {
            if (cur->left != nullptr) {
                tmp = cur->left;
                // find the rightest node in the left sub-tree of cur node
                while (tmp->right != nullptr && tmp->right != cur)
                    tmp = tmp->right;


                if (tmp->right == nullptr) {
                    // if this is the first access, just connect to cur node
                    tmp->right = cur;
                    cur = cur->left;
                } else { // tmp->right == cur
                    // if this is the second access, which means all the nodes
                    // in the left sub-tree of cur have been emitted, so just
                    // emit cur and travel the right sub-tree. DO NOT FORGET
                    // to reset the right of rightest node.
                    tmp->right = nullptr;
                    inorder_emit(cur);
                    // travel the right sub-tree
                    cur = cur->right;
                }
            } else {
                inorder_emit(cur);
                // travel the right sub-tree
                cur = cur->right;
            }
        }

        sw(first->val, second->val);
    }

};

#endif //OJ_LEETCODE099_H
