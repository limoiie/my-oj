//
// Created by limo on 1/16/2019.
//

#include <string>
#include <vector>

#include <gtest/gtest.h>

#include "algorithm/list.h"


namespace {

    using namespace std;
    using namespace algorithm::list;


    ListNode<int> *create_a_cyclic_list(ListNode<int> * &fork_node) {
        auto head = util::create_list<int>({1, 2, 3, 4, 5, 6});
        auto fork = util::create_list<int>({7, 8, 9, 10});

        fork_node = tail(head);
        fork_node->next = fork;
        tail(fork)->next = fork_node;

        return head;
    }

    GTEST_TEST(TestList, test_cyclic_list_delete) { // NOLINT
        auto head = new ListNode<int>(std::make_shared<int>(10));
        auto tail = new ListNode<int>(std::make_shared<int>(11));
        head->next = tail;
        tail->next = head;
        delete head;
    }

    GTEST_TEST(TestList, test_create_list) { // NOLINT
        vector<int> expected = {1, 2, 3, 4, 5, 6};
        auto head = util::create_list<int>(expected);

        vector<int> results;
        auto curr = head;
        while (curr != nullptr) {
            results.push_back(*curr->val);
            curr = curr->next;
        }
        ASSERT_TRUE(expected == results);

        delete head;
    }

    GTEST_TEST(TestList, test_is_cyclic) { // NOLINT
        ListNode<int> *fork_node = nullptr;
        auto head = create_a_cyclic_list(fork_node);
        ASSERT_TRUE(is_cyclic(head));
        delete head;
    }

    GTEST_TEST(TestList, test_cyclic_fork_node) { // NOLINT
        ListNode<int> *fork_node = nullptr;
        auto head = create_a_cyclic_list(fork_node);
        ASSERT_TRUE(cyclic_fork_node(head) == fork_node);
        delete head;
    }

}
