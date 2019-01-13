//
// Created by limo on 2018/5/5.
//
// LeetCode122 Best Time to Buy and Sell Stock II
//

#ifndef OJ_LEETCODE127_H
#define OJ_LEETCODE127_H

#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class SolutionLeetCode127 {
public:
    int ladderLength(const string &begin_word, const string &end_word, vector<string> &word_list) {
        if (begin_word == end_word) return 1;

        unordered_set<string> dict(word_list.begin(), word_list.end());
        if (dict.find(end_word) == dict.end()) return 0;

        auto words1 = unordered_set<string>{begin_word};
        auto words2 = unordered_set<string>{end_word};

        dict.erase(begin_word);
        dict.erase(end_word);

        return __ladderLength(words1, words2, dict, 1);
    }

private:
    int __ladderLength(unordered_set<string> &words1,
                       unordered_set<string> &words2,
                       unordered_set<string> &dict,
                       int step) {

        if (words2.empty()) return 0;
        if (words1.size() > words2.size()) return __ladderLength(words2, words1, dict, step);

        unordered_set<string> words3;
        for (auto &word : words1) {
            for (auto ic = word.begin(); ic != word.end(); ++ic) {
                auto tmp = *ic;
                for (*ic = 'a'; *ic <= 'z'; ++(*ic)) {
                    if (words2.find(word) != words2.end())
                        return step + 1;

                    if (dict.find(word) != dict.end()) {
                        dict.erase(word);
                        words3.insert(word);
                    }
                }
                *ic = tmp;
            }
        }

        return __ladderLength(words2, words3, dict, step + 1);
    }
};

#endif //OJ_LEETCODE127_H
