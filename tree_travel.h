//
// Created by limo on 1/10/2019.
//

#ifndef OJ_TREE_TRAVEL_H
#define OJ_TREE_TRAVEL_H

#include <functional>
#include <stack>
#include <vector>
#include <memory>

#include "tree.h"


namespace tree {

    namespace travel {

        template <typename T>
        struct Traveler {
            using tree_node_t = TreeNode<T>;
            using visit_ft = std::function<bool(tree_node_t *, int const)>;

            virtual ~Traveler() = default;
            virtual void travel(tree_node_t *root, visit_ft const& f_visit) = 0;
        };

#define USING_TRAVELER_TYPE_DEF \
using tree_node_t = typename Traveler<T>::tree_node_t; \
using visit_ft = typename Traveler<T>::visit_ft;

        namespace recurse {

            template <typename T>
            class InOrderTraveler : public Traveler<T> {
                USING_TRAVELER_TYPE_DEF
            public:
                void travel(tree_node_t *root, visit_ft const& f_visit) override {
                    if (nullptr == root) return;
                    travel(root->left, f_visit);
                    f_visit(root, 0);
                    travel(root->right, f_visit);
                }

            };

            template <typename T>
            class PreOrderTraveler : public Traveler<T> {
                USING_TRAVELER_TYPE_DEF
            public:
                void travel(tree_node_t *root, visit_ft const &f_visit) override {
                    if (nullptr == root) return;
                    f_visit(root, 0);
                    travel(root->left, f_visit);
                    travel(root->right, f_visit);
                }
            };

            template <typename T>
            class PostOrderTraveler : public Traveler<T> {
                USING_TRAVELER_TYPE_DEF
            public:
                void travel(tree_node_t *root, visit_ft const &f_visit) override {
                    if (nullptr == root) return;
                    travel(root->left, f_visit);
                    travel(root->right, f_visit);
                    f_visit(root, 0);
                }
            };

        }

        namespace iteration {

            template <typename T>
            class InOrderTraveler : public Traveler<T> {
                USING_TRAVELER_TYPE_DEF
            public:
                void travel(tree_node_t *root, visit_ft const &f_visit) override {
                    if (nullptr == root) return;

                    auto curr = root;
                    std::stack<tree_node_t *> stk({root});
                    while (!stk.empty()) {
                        while (nullptr != curr->left) {
                            curr = curr->left;
                            stk.push(curr);
                        }

                        tree_node_t *top;
                        do {
                            top = stk.top(); stk.pop();
                            f_visit(top, 0);
                        } while (!stk.empty() && nullptr == top->right);

                        if (nullptr != top->right) {
                            curr = top->right;
                            stk.push(curr);
                        }
                    }

                }

            };

            template <typename T>
            class PreOrderTraveler : public Traveler<T> {
                USING_TRAVELER_TYPE_DEF
            public:
                void travel(tree_node_t *root, visit_ft const &f_visit) override {
                    if (nullptr == root) return;
                    std::stack<tree_node_t*> stk({root});
                    while (!stk.empty()) {
                        auto top = stk.top(); stk.pop();
                        f_visit(top, 0);
                        if (nullptr != top->right) stk.push(top->right);
                        if (nullptr != top->left) stk.push(top->left);
                    }
                }
            };

            template <typename T>
            class PostOrderTraveler : public Traveler<T> {
                USING_TRAVELER_TYPE_DEF
            public:
                void travel(tree_node_t *root, visit_ft const &f_visit) override {
                    if (nullptr == root) return;

                    auto last_visited = root;
                    std::stack<tree_node_t*> stk({root});
                    while (!stk.empty()) {
                        auto top = stk.top();
                        if (nullptr == top->left && nullptr == top->right ||
                            last_visited == top->right || nullptr == top->right && last_visited == top->left) {
                            f_visit(top, 0);
                            last_visited = top;
                            stk.pop();
                        } else {
                            if (nullptr != top->right) stk.push(top->right);
                            if (nullptr != top->left) stk.push(top->left);
                        }
                    }
                }
            };

            template <typename T>
            class PostOrderTraveler2 : public Traveler<T> {
                USING_TRAVELER_TYPE_DEF
            public:
                void travel(tree_node_t *root, visit_ft const &f_visit) override {
                    if (nullptr == root) return;
                    std::stack<tree_node_t*> stk({root, root});
                    while (!stk.empty()) {
                        auto top = stk.top(); stk.pop();
                        if (!stk.empty() && top == stk.top()) {
                            // first visit:
                            // two nodes next to each other are equal means this node is
                            // popped for the first time and all of the children of this
                            // node has not been pushed into the stack
                            dup_push(stk, top->right);
                            dup_push(stk, top->left);
                        } else {
                            // second visit:
                            // all of the children of this node has been visited, next we
                            // visit current node
                            f_visit(top, 0);
                        }
                    }
                }

            private:
                void dup_push(std::stack<tree_node_t*>& stk, tree_node_t *node) {
                    if (nullptr != node) {
                        stk.push(node);
                        stk.push(node);
                    }
                }
            };

        }

        namespace morris {

            template <typename T>
            class InOrderTraveler : public Traveler<T> {
                USING_TRAVELER_TYPE_DEF
            public:
                void travel(tree_node_t *root, visit_ft const &f_visit) override {
                    auto curr = root;
                    while (nullptr != curr) {
                        if (nullptr == curr->left) {
                            f_visit(curr, 0);
                            curr = curr->right;
                        } else {
                            // find out prev node of curr
                            auto prev = curr->left;
                            while (nullptr != prev->right && curr != prev->right) {
                                prev = prev->right;
                            }

                            if (nullptr == prev->right) {
                                // this is the first time to visit curr, set the right of prev
                                // node of curr points to curr; then travel the left of curr
                                prev->right = curr;
                                curr = curr->left;
                            } else {
                                // prev node of curr already points to curr which means curr
                                // is the second time to be visited, so reset prev->right to
                                // nullptr and hit curr
                                prev->right = nullptr;
                                f_visit(curr, 0);
                                curr = curr->right;
                            }
                        }
                    }
                }
            };

            template <typename T>
            class PreOrderTraveler : public Traveler<T> {
                USING_TRAVELER_TYPE_DEF
            public:
                void travel(tree_node_t *root, visit_ft const &f_visit) override {
                    auto curr = root;
                    while (nullptr != curr) {
                        if (nullptr == curr->left) {
                            f_visit(curr, 0);
                            curr = curr->right;
                        } else {
                            // find the rightest node of the left subtree of curr
                            auto prev = curr->left;
                            while (nullptr != prev->right && curr != prev->right) {
                                prev = prev->right;
                            }

                            if (nullptr == prev->right) {
                                // first visit
                                f_visit(curr, 0);
                                prev->right = curr;
                                curr = curr->left;
                            } else {
                                // second visit
                                prev->right = nullptr;
                                curr = curr->right;
                            }
                        }
                    }
                }
            };

            template <typename T>
            class PostOrderTraveler : public Traveler<T> {
                USING_TRAVELER_TYPE_DEF
            public:
                void travel(tree_node_t *root, visit_ft const &f_visit) override {
                    auto dump = std::make_shared<tree_node_t>(nullptr);
                    dump->left = root;
                    auto curr = dump.get();
                    while (nullptr != curr) {
                        if (nullptr == curr->left) {
                            curr = curr->right;
                        } else {
                            auto prev = curr->left;
                            while (nullptr != prev->right && curr != prev->right) {
                                prev = prev->right;
                            }

                            if (nullptr == prev->right) {
                                // first visit
                                prev->right = curr;
                                curr = curr->left;
                            } else {
                                // second visit
                                visit_reverse(prev, curr->left, f_visit);
                                prev->right = nullptr;
                                curr = curr->right;
                            }
                        }
                    }
                    dump->release_child();
                }

            private:
                void reverse_rightest_branch(tree_node_t *root, tree_node_t *rightest_child) {
                    if (root == rightest_child) return;
                    auto parent = root, curr = root->right;
                    do {
                        auto temp = curr->right;
                        curr->right = parent;
                        parent = curr;
                        curr = temp;
                    } while (rightest_child != parent);
                }

                void visit_reverse(tree_node_t *rightest_child, tree_node_t *root, visit_ft const &f_visit) {
                    reverse_rightest_branch(root, rightest_child);
                    auto curr = rightest_child;
                    while (curr != root) {
                        f_visit(curr, 0);
                        curr = curr->right;
                    }
                    f_visit(curr, 0);
                    reverse_rightest_branch(rightest_child, root);
                }

            };

        }
    }

}


#endif //OJ_TREE_TRAVEL_H
