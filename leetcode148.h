//
// Created by limo on 2018/6/3.
//
// leetcode148 sort list
//

#ifndef OJ_LEETCODE148_H
#define OJ_LEETCODE148_H

#include "base.h"

class SolutionLeetCode148 {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode *prev = getMiddle(head);
        ListNode *sub1 = prev->next, *sub2 = head;
        prev->next = nullptr;

        sub1 = sortList(sub1);
        sub2 = sortList(sub2);

        return merge(sub1, sub2);
    }

    ListNode *merge(ListNode *sub1, ListNode *sub2) {
        ListNode head(0);
        ListNode *curr = &head;
        while (sub1 != nullptr && sub2 != nullptr) {
            if (sub1->val < sub2->val) {
                curr->next = sub1;
                sub1 = sub1->next;
            } else {
                curr->next = sub2;
                sub2 = sub2->next;
            }
            curr = curr->next;
        }
        if (sub1 != nullptr)
            curr->next = sub1;
        if (sub2 != nullptr)
            curr->next = sub2;
        return head.next;
    }

    ListNode* getMiddle(ListNode* head) {
        ListNode *prev = nullptr, *slow = head, *fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        return prev;
    }
};

#endif //OJ_LEETCODE148_H
