//
// Created by limo on 2019/2/12.
//

#ifndef OJ_LEETCODE147_H
#define OJ_LEETCODE147_H

#include "base.h"

class SolutionLeetcode146 {
public:
    ListNode *insertionSortList(ListNode *head) {
        if (nullptr == head) return head;

        auto sorted_list = std::make_shared<ListNode>(INT_MIN);
        auto curr = head;
        while (nullptr != curr) {
            auto const next = curr->next;
            auto iter = sorted_list.get();
            while (nullptr != iter->next) {
                if (iter->next->val > curr->val) {
                    auto const temp = iter->next;
                    iter->next = curr;
                    curr->next = temp;
                    break;
                }
                iter = iter->next;
            }

            if (nullptr == iter->next) {
                iter->next = curr;
                curr->next = nullptr;
            }
            curr = next;
        }
        return sorted_list->next;
    }
};

#endif //OJ_LEETCODE147_H
