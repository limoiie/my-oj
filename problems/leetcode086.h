#ifndef LEETCODE086_H
#define LEETCODE086_H

#include "base.h"

using namespace std;

class SolutionLeetCode086 {
public:
  ListNode* partition(ListNode* head, int x) {
    ListNode *less_head = nullptr, *less_tail = nullptr;
    ListNode *more_head = nullptr, *more_tail = nullptr;
    while (head != nullptr) {
      auto const next = head->next;
      if (head->x < x) {
        if (less_tail == nullptr) {
          less_head = less_tail = head;
        } else {
          less_tail->next = head;
          less_tail = less_tail->next;
        }
        less_tail->next = nullptr;
      } else {
        if (more_tail == nullptr) {
          more_head = more_tail = head;
        } else {
          more_tail->next = head;
          more_tail = more_tail->next;
        }
        more_tail->next = nullptr;
      }
      head = next;
    }

    if (less_tail == nullptr)
      return more_head;
    less_tail->next = more_head;
    return less_head;
  }

};

#endif LEETCODE086_H
