//
// Created by limo on 2018/6/2.
//
// leetcode061 rotate list
//

#ifndef OJ_LEETCODE061_H
#define OJ_LEETCODE061_H

#include "base.h"

class SolutionLeetCode061 {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        int l = 0;
        auto *tail = getLength(head, l);

        if (k == 0 || (k % l) == 0)
            return head;

        k = l - (k % l);

        auto *curr = head;
        while (--k > 0)
            curr = curr->next;

        tail->next = head;
        head = curr->next;
        curr->next = nullptr;

        return head;
    }

private:
    ListNode *getLength(ListNode *head, int &l) {
        if (head == nullptr) return nullptr;
        l = 1;
        while (head->next != nullptr) {
            head = head->next;
            ++l;
        }
        return head;
    }

};

#endif //OJ_LEETCODE061_H
