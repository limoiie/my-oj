//
// Created by limoi on 2018/x/x.
//
// LeetCode 460 lfu cache
//

#ifndef OJ_LEETCODE460_H
#define OJ_LEETCODE460_H

#include <utility>
#include <memory>

#include "base.h"

class LFUCache {
    struct UseNode;
    using node_ptr = shared_ptr<UseNode>;
    struct UseNode {
        node_ptr prev;
        node_ptr next;
        int key;
        int use_count;
        UseNode(node_ptr v_prev, node_ptr v_next, int v_key = -1, int v_use_count = 0)
                : prev(std::move(v_prev)), next(std::move(v_next)), key(v_key), use_count(v_use_count) {}
    };

    class UseNodeQueue {
    private:
        node_ptr head;
        node_ptr tail;

    public:
        UseNodeQueue() {
            head = tail = make_shared<UseNode>(nullptr, nullptr);
        }

        void push(const node_ptr &node) {
            node->next = tail->next;
            tail->next = node;
            node->prev = tail;
            tail = node;
        }

        node_ptr pop() {
            if (empty())
                throw exception();
            auto removed_node = head->next;
            remove(removed_node);
            return removed_node;
        }

        void remove(const node_ptr &node) {
            node->prev->next = node->next;
            if (node->next != nullptr)
                node->next->prev = node->prev;
            else
                tail = head;
        }

        bool empty() {
            return head->next == nullptr;
        }

    };

public:
    explicit LFUCache(int capacity) {
        this->capacity = capacity;
        this->size = 0;
        this->min_use_count = 1;
    }

    int get(int key) {
        if (key_val_map[key] != 0)
            increase_use_count(key);
        return key_val_map[key] - 1;
    }

    void put(int key, int value) {
        if (capacity == 0) return;

        if (key_val_map[key] != 0) {
            key_val_map[key] = value + 1;
            increase_use_count(key);
            return;
        }

        node_ptr node;
        if (size >= capacity) {
            auto &curr_queue = count_queue_map[min_use_count];
            node = curr_queue.pop();
            key_val_map.erase(node->key);
            key_node_map.erase(node->key);
        } else {
            node = make_shared<UseNode>(nullptr, nullptr);
            ++size;
        }

        node->key = key;
        node->use_count = 1;
        key_val_map[key] = value + 1;
        key_node_map[key] = node;
        count_queue_map[1].push(node);
        min_use_count = 1;
    }

private:
    void increase_use_count(int key) {
        auto p_node = key_node_map[key];
        auto &curr_queue = count_queue_map[p_node->use_count];
        curr_queue.remove(p_node);
        auto &next_queue = count_queue_map[p_node->use_count+1];
        next_queue.push(p_node);
        if (p_node->use_count == min_use_count && curr_queue.empty()) ++min_use_count;
        ++p_node->use_count;
    }

    unordered_map<int, int> key_val_map;
    unordered_map<int, shared_ptr<UseNode>> key_node_map;
    unordered_map<int, UseNodeQueue> count_queue_map;
    int capacity;
    int size;
    int min_use_count;

};

#endif //OJ_LEETCODExxx_H
