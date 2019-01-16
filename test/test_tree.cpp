//
// Created by limo on 1/12/2019.
//
#include <iostream>
#include <string>
#include <vector>

#include <gtest/gtest.h>

#include "algorithm/tree_travel.h"


namespace {

    using namespace std;
    using namespace algorithm::tree;
    using namespace algorithm::tree::travel;

#define null INT_MIN


    TreeNode<int>* create_a_tree() {
        return util::create_tree<int>({0, 2, 4, 1, null, 3, -1, 5, 1, null, 6, null, 8}, null);
    }

    void test_travelers(TreeNode<int> *tree,
              vector<std::shared_ptr<Traveler<int>>> const& travelers,
              vector<int> const& predicted) {

        for (auto && traveler : travelers) {
            vector<int> gotten;
            traveler->travel(tree, [&gotten](Traveler<int>::tree_node_t *node, int const depth) {
                gotten.push_back(*node->val);
                return true;
            });

            ASSERT_TRUE(gotten == predicted);
        }
    }

    GTEST_TEST(TestTree, test_in_order_travel) { // NOLINT
        auto tree = create_a_tree();
        auto travelers = vector<std::shared_ptr<travel::Traveler<int>>> {
                std::make_shared<recurse::InOrderTraveler<int>>(),
                std::make_shared<iteration::InOrderTraveler<int>>(),
                std::make_shared<morris::InOrderTraveler<int>>(),
        };

        test_travelers(tree, travelers, vector<int>{5, 1, 1, 2, 0, 3, 6, 4, -1, 8});
        delete tree;
    }

    GTEST_TEST(TestTree, test_pre_order_travel) { // NOLINT
        auto tree = create_a_tree();
        auto travelers = vector<std::shared_ptr<travel::Traveler<int>>> {
                std::make_shared<recurse::PreOrderTraveler<int>>(),
                std::make_shared<iteration::PreOrderTraveler<int>>(),
                std::make_shared<morris::PreOrderTraveler<int>>()
        };

        test_travelers(tree, travelers, vector<int>{0, 2, 1, 5, 1, 4, 3, 6, -1, 8});
        delete tree;
    }

    GTEST_TEST(TestTree, test_post_order_travel) { // NOLINT
        try {
            auto tree = create_a_tree();
            auto travelers = vector<std::shared_ptr<travel::Traveler<int>>> {
                    std::make_shared<recurse::PostOrderTraveler<int>>(),
                    std::make_shared<iteration::PostOrderTraveler<int>>(),
                    std::make_shared<iteration::PostOrderTraveler2<int>>(),
                    std::make_shared<morris::PostOrderTraveler<int>>()
            };

            test_travelers(tree, travelers, vector<int>{5, 1, 1, 2, 6, 3, 8, -1, 4, 0});
            delete tree;
        } catch (std::exception &e) {
            cerr << "Error: " << e.what() << endl;
        }
    }

}
