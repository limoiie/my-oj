//
// Created by limoi on 2018/3/13.
//
// LeetCode133 clone graph
//

#include <iostream>
#include <vector>
#include <map>
#include <stack>

using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {}
};

class SolutionLeetCode133 {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        return clone(node);[]
    }

    UndirectedGraphNode *clone(UndirectedGraphNode *node) {
        if (node == nullptr)
            return nullptr;

        if (container[node->label] != nullptr)
            return container[node->label];

        auto *clone_obj = new UndirectedGraphNode(node->label);
        container[node->label] = clone_obj;

        for (auto *item : node->neighbors) {
            clone_obj->neighbors.push_back(clone(item));
        }
        return clone_obj;
    }

private:
    map<int, UndirectedGraphNode *> container;

};
