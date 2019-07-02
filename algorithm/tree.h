//
// Created by limo on 1/12/2019.
//

#ifndef OJ_TREE_H
#define OJ_TREE_H

#include <memory>
#include <vector>
#include <queue>

namespace algorithm {

    namespace tree {

        template<typename T>
        struct TreeNode {
            std::shared_ptr<T> val;
            TreeNode<T> *left;
            TreeNode<T> *right;

            TreeNode() : val(nullptr), left(nullptr), right(nullptr) {}

            explicit TreeNode(std::shared_ptr<T> const &x)
                    : val(x), left(nullptr), right(nullptr) {
            }

            TreeNode(std::shared_ptr<T> const &v_val, TreeNode<T> *v_left, TreeNode<T> *v_right)
                    : val(v_val), left(v_left), right(v_right) {
            }

            ~TreeNode() {
                delete left;
                left = nullptr;
                delete right;
                right = nullptr;
            }

            void release_child() {
                left = right = nullptr;
            }

        };

        namespace util {

            template<typename T>
            static inline TreeNode<T> *create_tree_node(T const &val) {
                return new TreeNode<T>(std::make_shared<T>(val));
            }

            template<typename T>
            static inline TreeNode<T> *create_tree_node(T const &val, T const &null_val) {
                return null_val == val ? nullptr : create_tree_node(val);
            }

            template<typename T>
            TreeNode<T> *create_tree(std::vector<T> const &seq, T const &null_val) {
                if (seq.empty()) return nullptr;

                auto root = create_tree_node<T>(seq.front(), null_val);
                std::queue<TreeNode<T> *> pre_layer;
                pre_layer.push(root);

                for (auto start = 1; start < seq.size();) {
                    std::queue<TreeNode<T> *> layer;
                    layer.swap(pre_layer);

                    while (!layer.empty()) {
                        auto const parent = layer.front();
                        layer.pop();
                        if (nullptr != parent) {
                            parent->left = create_tree_node(seq[start++], null_val);
                            if (nullptr != parent->left) {
                                pre_layer.push(parent->left);
                            }

                            parent->right = create_tree_node(seq[start++], null_val);
                            if (nullptr != parent->right) {
                                pre_layer.push(parent->right);
                            }
                        }
                    }
                }

                return root;
            }

        }

        template<typename T>
        struct AVLNodeState {
            int height;
            T data;

            AVLNodeState(int const height, const T &data)
                    : height(height), data(data) {}
        };

        template<typename T>
        TreeNode<AVLNodeState<T>> *create_node(T const &data) {
            return util::create_tree_node(AVLNodeState<T>(1, data));
        }

        template<typename T, typename CMP>
        class AVLTree {
            using node_t = TreeNode<AVLNodeState<T>>;
            enum Unbalance {
                GOOD, RR, LL, RL, LR
            };

        public:
            size_t height() const {
                return 0;
            }

            void insert(T const &data) {
                if (root_ == nullptr) {
                    root_ = std::shared_ptr<node_t>(create_node(data));
                    return;
                }
                std::stack<node_t *> path;
                auto curr = root_.get();
                while (curr != nullptr) {
                    path.push(curr);
                    auto const cmp_res = cmp_(curr->val->data, data);
                    auto &child = cmp_res < 0 ? curr->left : curr->right;
                    if (child == nullptr) {
                        child = create_node(data);
                        path.push(child);
                        balance(path);
                        return;
                    }
                    curr = child;
                }
            }

        private:
            int height(node_t *node) const {
                return node == nullptr ? 0 : node->val->height;
            }

            bool is_left_child_higher(node_t *node) const {
                return height(node->left) > height(node->right);
            }

            bool is_left_child(node_t *node, node_t *parent) const {
                return parent->left == node;
            }

            Unbalance what_kind_unbalance(node_t* node) const {
                auto const sub_left_h = height(node->left);
                auto const sub_right_h = height(node->right);
                if (sub_right_h >= sub_left_h + 2)
                    return is_left_child_higher(node->right) ? RL : RR;
                if (sub_left_h >= sub_right_h + 2)
                    return is_left_child_higher(node->right) ? LL : LR;
                return GOOD;
            }

            node_t *& ref_child(node_t *node, bool left) const {
                return left ? node->left : node->right;
            }

            void turn(node_t *node, node_t *parent, bool left) {
                auto child = ref_child(node, !left);
                ref_child(node, !left) = ref_child(child, left);
                ref_child(child, left) = node;

                ref_child(parent, is_left_child(node, parent)) = child;
                local_update(node);
            }

            void left_turn(node_t *node, node_t *parent) {
                auto right_child = node->right;

            }

            void right_turn(node_t *node, node_t *parent) {
                auto left_child = node->left;
                node->left = left_child->right;
                left_child->right = node;
                auto& target = is_left_child(node, parent) ?
                        parent->left : parent->right;
                target = left_child;
                local_update(node);
            }

            void balance(std::stack<node_t *> &path) {
                auto balanced = false;
                while (!path.empty()) {
                    auto curr = path.top(); path.pop();
                    auto parent = path.empty() ? root_.get() : path.top();
                    local_update(curr);
                    if (!balanced) {
                        balanced = true;
                        switch (what_kind_unbalance(curr)) {
                            case LL:
                                right_turn(curr, parent);
                                break;
                            case LR:
                                left_turn(curr->left, curr);
                                right_turn(curr, parent);
                                break;
                            case RR:
                                left_turn(curr, parent);
                                break;
                            case RL:
                                right_turn(curr->right, parent);
                                left_turn(curr, parent);
                                break;
                            case GOOD:
                                balanced = false;
                                break;
                        }
                    }
                }
            }

            void local_update(node_t *node) {
                node->val->height = std::max(height(node->left), height(node->right)) + 1;
                // TODO: update node->val->data
            }

            std::shared_ptr<node_t> root_;
            CMP cmp_;

        };

    }

}

#endif //OJ_TREE_H
