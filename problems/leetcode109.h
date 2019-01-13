//
// Created by limo on 2018/6/3.
//
// leetcode109
//

#ifndef OJ_LEETCODE109_H
#define OJ_LEETCODE109_H

#include "base.h"

class SolutionLeetCode109 {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        return sortedListToBST(head, nullptr);
    }

private:
    TreeNode *sortedListToBST(ListNode *head, ListNode *tail) {
        if (head == tail) return nullptr;

        auto *slow = head, *fast = head;
        while (fast != tail && fast->next != tail) {
            slow = slow->next;
            fast = fast->next->next;
        }

        auto *node = new TreeNode(slow->val);
        node->left = sortedListToBST(head, slow);
        node->right = sortedListToBST(slow->next, tail);
        return node;
    }
};

#endif //OJ_LEETCODE109_H
