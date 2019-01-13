//
// Created by limoi on 2018/1/25.
//
// LeetCode 010 regular expression matching

#include <string>
#include <memory.h>

using namespace std;

class SolutionLeetCode010 {
public:
    bool isMatch(string s, string p) {
        string str = ' ' + s;
        string ptn = ' ' + p;

        bool match_table[ptn.length()][str.length()];
        memset(match_table, 0, sizeof(match_table));

        match_table[0][0] = true;
        for (unsigned int i = 1; i < ptn.length(); ++i) {
            switch (ptn[i]) {
                case '*':
                    if (ptn[i-1] == '.') {
                        for (unsigned int j = 0; j < str.length(); ++j) {
                            if (match_table[i-2][j]) {
                                for (; j < str.length(); ++j) {
                                    match_table[i][j] = true;
                                }
                            }
                        }
                    } else {
                        for (unsigned int j = 0; j < str.length(); ++j) {
                            if (match_table[i-2][j]) {
                                match_table[i][j] = true;
                                for (++j; j < str.length() && str[j] == ptn[i-1]; ++j) {
                                    match_table[i][j] = true;
                                }
                                --j;
                            }
                        }
                    }
                    break;
                case '.':
                    for (unsigned int j = 1; j < str.length(); ++j) {
                        if (match_table[i-1][j-1]) {
                            match_table[i][j] = true;
                        }
                    }
                    break;
                default:
                    for (unsigned int j = 1; j < str.length(); ++j) {
                        if (match_table[i-1][j-1] && (str[j] == ptn[i])) {
                            match_table[i][j] = true;
                        }
                    }
                    break;
            }
        }

        return match_table[p.length()][s.length()];
    }
};
