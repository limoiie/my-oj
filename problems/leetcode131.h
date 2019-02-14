//
// Created by limo on 2/14/2019.
//

#ifndef OJ_LEETCODE131_H
#define OJ_LEETCODE131_H

#include "base.h"

/*
 * @category back-tracking, memory
 *
 * @detail All backtracking problems are composed by these three steps: choose, explore, unchoose.
 * So for each problem, you need to know:
 *   1. choose what? For this problem, we choose each substring.
 *   2. how to explore? For this problem, we do the same thing to the remained string.
 *   3. unchoose Do the opposite operation of choose.
 *
 */
class SolutionLeetcode131 {
public:
    using memo_t = map<int, vector<vector<string>>>;

    vector<vector<string>> partition(string s) {
        memo_.clear();
        memo_[s.size()] = {{}};
        curr_partition_.clear();
        sentence_.assign(move(s));
        partition(0);
        return move(all_partitions_);
    }

    void partition(size_t const index) {
        if (memo_.end() != memo_.find(index)) {
            for (auto const& post_partition : memo_[index]) {
                auto partition = curr_partition_;
                partition.insert(partition.end(), post_partition.begin(), post_partition.end());
                all_partitions_.push_back(move(partition));
            }
            return;
        }

        vector<vector<string>> partitions;
        for (auto i = index; i < sentence_.size(); ++i) {
            if (not is_palindrome(index, i)) continue;
            auto const part = sentence_.substr(index, i+1-index);
            curr_partition_.push_back(part);
            partition(i+1);
            curr_partition_.pop_back();
        }
    }

private:
    bool is_palindrome(size_t const start, size_t const end) {
        for (auto i = start, j = end; i < j; ++i, --j) {
            if (sentence_[i] != sentence_[j]) return false;
        }
        return true;
    }

    memo_t memo_;
    vector<string> curr_partition_;
    vector<vector<string>> all_partitions_;
    string sentence_;

};

#endif //OJ_LEETCODE131_H
