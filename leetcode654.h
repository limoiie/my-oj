//
// Created by limo on 2018/6/13.
//
// leetcode 654 maximum binary tree
//

#ifndef OJ_LEETCODE654_H
#define OJ_LEETCODE654_H

#include "base.h"

class SolutionLeetcode654 {
public:
    TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
        return construct(nums, 0, static_cast<int>(nums.size()));
    }

private:
    TreeNode *construct(vector<int> &nums, const int l, const int r) {
        if (l >= r) return nullptr;
        int m = l;
        for (int i = l+1; i < r; ++i)
            if (nums[m] < nums[i])
                m = i;

        auto p_node = new TreeNode(nums[m]);
        p_node->left = construct(nums, l, m);
        p_node->right = construct(nums, m+1, r);
        return p_node;
    }

    TreeNode *constructMaximumBinaryTree2(vector<int> &nums) {
        deque<TreeNode *> stack;
        for (const auto num : nums) {
            auto p_node = new TreeNode(num);
            while (!stack.empty() && stack.back()->val < num) {
                p_node->left = stack.back(); stack.pop_back();
            }
            if (!stack.empty()) {
                stack.back()->right = p_node;
            }
            stack.push_back(p_node);
        }
        return stack.empty() ? nullptr : stack.front();
    }

};

#endif //OJ_LEETCODE654_H
