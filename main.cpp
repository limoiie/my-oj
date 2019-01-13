#include <iostream>
#include <string>
#include <vector>

#include <gtest/gtest.h>

#include "tree.h"
#include "tree_travel.h"

using namespace std;
using namespace std;
using namespace tree;
using namespace tree::travel;

#define null INT_MIN


TreeNode<int>* create_a_tree() {
    return util::create_tree<int>({0, 2, 4, 1, null, 3, -1, 5, 1, null, 6, null, 8}, null);
}

void test_travelers(TreeNode<int> *tree,
                    vector<std::shared_ptr<Traveler<int>>> const& travelers,
    vector<int> const& predicted) {

    for (auto && traveler : travelers) {
        cout << "traveler..." << endl;

        vector<int> gotten;
        traveler->travel(tree, [&gotten](tree::travel::Traveler<int>::tree_node_t *node, int const depth) {
            gotten.push_back(*node->val);
            return true;
        });

        ASSERT_TRUE(gotten == predicted);
    }
}

int main() {
    try {
        auto tree = create_a_tree();
        auto travelers = vector<std::shared_ptr<tree::travel::Traveler<int>>> {
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

    return 0;
}