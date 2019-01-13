//
// Created by limo on 2018/5/14.
//
// LeetCode122 Best Time to Buy and Sell Stock II
//

#ifndef OJ_LEETCODE126_H
#define OJ_LEETCODE126_H

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <map>

using namespace std;

class SolutionLeetCode126 {
public:
    vector<vector<string>> findLadders(const string &beginWord, const string &endWord, vector<string>& wordList) {
        if (beginWord == endWord)
            return vector<vector<string>>{vector<string>{beginWord}};

        unordered_set<string> word_set(wordList.begin(), wordList.end());
        if (word_set.find(endWord) == word_set.end())
            return vector<vector<string>>{};

        word_set.erase(beginWord);
        word_set.erase(endWord);

        words1 = unordered_set<string>{beginWord};
        words2 = unordered_set<string>{endWord};
        afterWord[beginWord] = {};
        afterWord[endWord] = {};

        res.clear();

        bool flap = false;
        bool found = false;
        while (!found && !words1.empty() && !words2.empty()) {
            if (words1.size() > words2.size()) flap = true;
            auto &wordsA = flap ? words2 : words1;
            auto &wordsB = flap ? words1 : words2;

            unordered_set<string> words3;
            for (const auto &word : wordsA) {
                string step = word;
                for (auto &itr : step) {
                    auto tmp = itr;
                    for (auto c = 'a'; c <= 'z'; ++c) {
                        itr = c;
                        if (wordsB.find(step) != wordsB.end()) {
                            flap ? afterWord[step].push_back(word) : afterWord[word].push_back(step);
                            found = true;
                        } else if (word_set.find(step) != word_set.end()) {
                            words3.insert(step);
                            flap ? afterWord[step].push_back(word) : afterWord[word].push_back(step);
                        }
                    }
                    itr = tmp;
                }
            }

            for (auto const &item : words3)
                word_set.erase(item);
            wordsA = move(words3);
        }

        vector<string> path{beginWord};
        if (found) concatPath(beginWord, endWord, path);
        return res;
    }

private:
    unordered_set<string> words1;
    unordered_set<string> words2;

    map<string, vector<string>> afterWord;
    vector<vector<string>> res;

    void concatPath(const string& beginJoin, const string& endJoin, vector<string> &path) {
        if (beginJoin == endJoin) {
            res.push_back(path);
            return;
        }
        for (const auto &word : afterWord[beginJoin]) {
            path.push_back(word);
            concatPath(word, endJoin, path);
            path.pop_back();
        }
    }

};

#endif //OJ_LEETCODE126_H
