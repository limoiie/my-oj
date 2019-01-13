//
// Created by limoi on 2018/1/25.
//
// LeetCode 035 search insert position

#include <vector>

using namespace std;

class SolutionLeetCode035 {
public:
    int searchInsert(vector<int> & nums, int target) {
        int lt = 0, rt = static_cast<int>(nums.size()) - 1;
        while (lt <= rt) {
            int md = (lt + rt) >> 1;
            if (nums[md] < target) {
                lt = md + 1;
            } else {
                rt = md - 1;
            }
        }
        return lt;
    }

};
