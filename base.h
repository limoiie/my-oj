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

using namespace std;

template <class T> void swap(T &a, T &b) {
    T c(std::move(a)); a=std::move(b); b=std::move(c);
}

template <class T, size_t N> void sw(T (&a)[N], T (&b)[N]) {
    for (size_t i = 0; i<N; ++i) sw(a[i], b[i]);
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

#endif //OJ_BASE_H
