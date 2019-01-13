//
// Created by limoi on 2018/3/6.
//
// LeetCode102 Binary Tree Level Order Traversal
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class SolutionLeetCode102 {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;

        queue<pair<TreeNode*, int>> que;
        que.push(make_pair(root, 0));

        while (!que.empty()) {
            auto p = que.front();
            que.pop();
            if (p.first != nullptr) {
                if (res.size() == p.second)
                    res.emplace_back();

                res[p.second].emplace_back(p.first->val);

                que.push(make_pair(p.first->left, p.second+1));
                que.push(make_pair(p.first->right, p.second+1));
            }
        }

        return res;
    }
};