//
// Created by limo on 2018/5/30.
//

#ifndef OJ_BASE_H
#define OJ_BASE_H

#include <string>
#include <vector>
#include <memory.h>
#include <algorithm>
#include <utility>
#include <cmath>
#include <memory>
#include <queue>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <numeric>
#include <functional>
#include <stack>

using namespace std;

template <class T> void my_swap(T &a, T &b) {
    T c(std::move(a)); a=std::move(b); b=std::move(c);
}

template <class T, size_t N> void my_swap(T (&a)[N], T (&b)[N]) {
    for (size_t i = 0; i<N; ++i) my_swap(a[i], b[i]);
}

struct ListNode {
    int val;
    ListNode *next;
    explicit ListNode(int x) : val(x), next(nullptr) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


#define null INT_MIN

inline TreeNode *createNode(int const val) {
    return null == val ? nullptr : new TreeNode(val);
}

TreeNode* createTree(vector<int> const& seq) {
    if (seq.empty()) return nullptr;

    auto root = new TreeNode(seq.front());
    queue<TreeNode*> pre_layer; pre_layer.push(root);

    for (auto start = 1; start < seq.size();) {
        queue<TreeNode*> layer;
        layer.swap(pre_layer);

        while (!layer.empty()) {
            auto const parent = layer.front(); layer.pop();
            if (nullptr != parent) {
                parent->left = createNode(seq[start++]);
                if (nullptr != parent->left) {
                    pre_layer.push(parent->left);
                }

                parent->right = createNode(seq[start++]);
                if (nullptr != parent->right) {
                    pre_layer.push(parent->right);
                }
            }
        }
    }

    return root;
}


#endif //OJ_BASE_H
