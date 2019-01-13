//
// Created by limo on 2018/6/12.
//
// leetcode653 two sum iv input is a bst
//

#ifndef OJ_LEETCODE653_H
#define OJ_LEETCODE653_H

#include "base.h"

class SolutionLeetcode653 {
public:
    bool findTarget(TreeNode *root, int k) {
        unordered_set<int> mem;
        return method1(root, mem, k);
    }

private:
    bool method1(TreeNode *node, unordered_set<int> &mem, int k) {
        if (node == nullptr) return false;
        if (mem.count(k-node->val)) return true;
        mem.insert(node->val);
        return method1(node->left, mem, k) ||
               method1(node->right, mem, k);
    }

    bool method2(TreeNode *node, int k) {
        vector<int> nums;
        inorder(node, nums);
        for (int i = 0, j = static_cast<int>(nums.size() - 1); i < j; ) {
            if (nums[i] + nums[j] == k) return true;
            (nums[i] + nums[j] < k) ? ++i : ++j;
        }
        return false;
    }

    void inorder(TreeNode *node, vector<int> &nums) {
        if (node == nullptr) return;
        inorder(node->left, nums);
        nums.push_back(node->val);
        inorder(node->right, nums);
    }

};

#endif //OJ_LEETCODE653_H
