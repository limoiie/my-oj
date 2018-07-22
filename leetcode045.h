//
// Created by limoi on 2018/1/25.
//
// LeetCode 024 sw node in pairs
//

#include <vector>
#include <memory.h>

using namespace std;

class SolutionLeetCode045 {
public:
    int jump(vector<int> & nums) {
        int step = 0, cur = 0, top = 0;
        while (top+1 < nums.size()) {
            ++step;

            int old_top = top;
            while (cur <= old_top) {
                top = max(cur+nums[cur], top);
                ++cur;
            }
        }
        return step;
    }
};
