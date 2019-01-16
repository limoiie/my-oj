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

        template <typename T>
        struct TreeNode {
            std::shared_ptr<T> val;
            TreeNode<T> *left;
            TreeNode<T> *right;

            explicit TreeNode(std::shared_ptr<T> const& x)
                    : val(x), left(nullptr), right(nullptr) {
            }

            TreeNode(std::shared_ptr<T> const& v_val, TreeNode<T> *v_left, TreeNode<T> *v_right)
                    : val(v_val), left(v_left), right(v_right) {
            }

            ~TreeNode() {
                delete left;
                delete right;
            }

            void release_child() {
                left = right = nullptr;
            }

        };

        namespace util {

            template <typename T>
            static inline TreeNode<T> *create_tree_node(T const val, T const &null_val) {
                return null_val == val ? nullptr : new TreeNode<T>(std::make_shared<T>(val));
            }

            template <typename T>
            TreeNode<T>* create_tree(std::vector<T> const &seq, T const& null_val) {
                if (seq.empty()) return nullptr;

                auto root = create_tree_node<T>(seq.front(), null_val);
                std::queue<TreeNode<T>*> pre_layer; pre_layer.push(root);

                for (auto start = 1; start < seq.size();) {
                    std::queue<TreeNode<T>*> layer;
                    layer.swap(pre_layer);

                    while (!layer.empty()) {
                        auto const parent = layer.front(); layer.pop();
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

    }

}

#endif //OJ_TREE_H
