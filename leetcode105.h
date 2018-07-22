//
// Created by limo on 2018/6/3.
//
// leetcode105 construct binary tree from preorder and inorder traversal
//

#ifndef OJ_LEETCODE105_H
#define OJ_LEETCODE105_H

#include "base.h"

class SolutionLeetCode105 {
    typedef vector<int>::iterator itr_t;
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        pre_top = preorder.begin(), pre_bot = preorder.end();
        in_top = inorder.begin(), in_bot = inorder.end();
        return build(pre_bot);
    }

private:
    TreeNode *build(const itr_t stop) {
        TreeNode *node = nullptr;
        if (in_top != in_bot && (stop == pre_bot || *in_top != *stop)) {
            node = new TreeNode(*pre_top);
            node->left = build(pre_top++);
            ++in_top;
            node->right = build(stop);
        }
        return node;
    }

    itr_t pre_top, pre_bot, in_top, in_bot;

};

#endif //OJ_LEETCODE105_H
