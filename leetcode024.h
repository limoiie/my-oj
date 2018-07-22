//
// Created by limoi on 2018/1/24.
//
// LeetCode 024 sw node in pairs
//

#include <string>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class SolutionLeetCode024 {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *sentinel = new ListNode(0);
        sentinel->next = head;

        head = sentinel;
        while (head->next != nullptr && head->next->next != nullptr) {
            auto next = head->next;
            head->next = head->next->next;
            next->next = head->next->next;
            head->next->next = next;
            head = head->next->next;
        }
        return sentinel->next;
    }

};
