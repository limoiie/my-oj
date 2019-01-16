//
// Created by limo on 1/16/2019.
//

#ifndef OJ_LIST_H
#define OJ_LIST_H

#include <memory>
#include <vector>

namespace algorithm {

    namespace list {

        template <typename T>
        struct ListNode {
            std::shared_ptr<T> val;
            ListNode<T> *next;

            explicit ListNode(std::shared_ptr<T> const& x)
                    : val(x), next(nullptr) {
            }

            ListNode(std::shared_ptr<T> const& x, ListNode<T> *v_next)
                    : val(x), next(v_next) {
            }

            ~ListNode() {
                deleted_ = true;
                if (nullptr != next && !next->deleted_)
                    delete next;
            }

            void release_next() {
                next = nullptr;
            }

        private:
            bool deleted_ = false;

        };

        namespace util {

            template <typename T>
            ListNode<T> *create_list(std::vector<T> const& seq) {
                if (seq.empty()) return nullptr;

                auto head = new ListNode<T>(std::make_shared<int>(seq.front()));
                auto curr = head;
                for (auto i = 1; i < seq.size(); ++i) {
                    curr->next = new ListNode<T>(std::make_shared<int>(seq[i]));
                    curr = curr->next;
                }
                return head;
            }

        }

        ListNode<int> *tail(ListNode<int> * const head) {
            if (nullptr == head) return nullptr;

            auto curr = head;
            while (nullptr != curr->next)
                curr = curr->next;
            return curr;
        }

        bool is_cyclic(ListNode<int> *head) {
            auto slow = head, fast = head;
            do {
                if (nullptr == fast || nullptr == fast->next || nullptr == fast->next->next) {
                    return false;
                }
                slow = slow->next;
                fast = fast->next->next;
            } while (slow != fast);
            return true;
        }

        ListNode<int> *cyclic_fork_node(ListNode<int> *head) {
            auto slow = head, fast = head;
            do {
                if (nullptr == fast || nullptr == fast->next || nullptr == fast->next->next) {
                    return nullptr;
                }
                slow = slow->next;
                fast = fast->next->next;
            } while (slow != fast);

            fast = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }

            return slow;
        }

    }

}

#endif //OJ_LIST_H
