//
// Created by limoi on 2018/2/28.
//
// LeetCode 023 Merge k Sorted Lists
//

#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class SolutionLeetCode023 {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return nullptr;

        ListNode result(0);
        result.next = lists.front();
        for (int i = 1; i < lists.size(); ++i) {
            __mergeList(&result, result.next, lists[i]);
        }
        return result.next;
    }

private:
    void __mergeList(ListNode* tgt, ListNode* ls1, ListNode* ls2) {
        while (ls1 != nullptr && ls2 != nullptr) {
            if (ls1->val < ls2->val) {
                tgt->next = ls1;
                tgt = tgt->next;
                ls1 = ls1->next;
            } else {
                tgt->next = ls2;
                tgt = tgt->next;
                ls2 = ls2->next;
            }
        }
        tgt->next = ls1 == nullptr ? ls2 : ls1;
    }
};
