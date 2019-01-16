#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <sstream>

#include <problems/base.h>

using namespace std;

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (nullptr == headA || nullptr == headB)
            return nullptr;

        auto curr_a = headA;
        while (nullptr != curr_a->next)
            curr_a = curr_a->next;
        curr_a->next = headB;

        auto slow = headA, fast = headA;
        do {
            if (nullptr == fast || nullptr == fast->next || nullptr == fast->next->next)
                return nullptr;
            slow = slow->next;
            fast = fast->next->next;
        } while (slow != fast);

        fast = headA;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        curr_a->next = nullptr;
        return slow;
    }
};

void test() {
    vector<vector<int>> nums_list = {
            {3,1,3},
            {3,4,5,1,2},
            {4,5,6,7,0,1,2}
    };
}

int main() {
    test();
    return 0;
}