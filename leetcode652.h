//
// Created by limo on 2018/6/10.
//
// leetcode 652 find duplicate subtrees

#ifndef OJ_LEETCODE652_H
#define OJ_LEETCODE652_H

#include "base.h"

class SolutionLeetcode652 {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode *root) {
        res.clear(); mem.clear();
        mapTreeIntoInt(root);
        return res;
    }

private:
    int mapTreeIntoInt(TreeNode *root) {
        if (root == nullptr) return 0;
        long key = constructKey(root->val, mapTreeIntoInt(root->left), mapTreeIntoInt(root->right));

        auto itr = mem.find(key);
        if (itr == mem.end())
            itr = mem.insert({key, {static_cast<const int &>(mem.size() + 1), 0}}).first;

        if (++itr->second.second == 2)
            res.push_back(root);

        return itr->second.first;
    }

    inline
    long constructKey(long val, int left, int right) {
        return (val << 32) | (left << 16) | right;
    }

    vector<TreeNode*> res;
    unordered_map<long, pair<int, int>> mem;
};

#endif //OJ_LEETCODE652_H
