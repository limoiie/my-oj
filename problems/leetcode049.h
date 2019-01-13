//
// Created by limoi on 2018/1/29.
//
// LeetCode 049 group anagrams
//

#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

class SolutionLeetCode049 {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        map<string, vector<string>> con;
        for (auto str : strs) {
            string tmp = str;
            sort(tmp.begin(), tmp.end());
            con[tmp].push_back(move(str));
        }

        for (auto item : con) {
            res.push_back(move(item.second));
        }
        return res;
    }

};
