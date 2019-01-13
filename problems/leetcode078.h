//
// Created by limoi on 2018/1/29.
//
// LeetCode 078 subsets
//

#include <vector>

using namespace std;

class SolutionLeetCode078 {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> con;
        for (int i = 0; i <= nums.size(); ++i) {
            sub(con, nums , {}, 0, i);
        }
        return con;
    }

private:
    void sub(vector<vector<int>>& con, vector<int>& nums, vector<int> pres, int start, int size) {
        if (size == 0) {
            con.emplace_back(std::move(pres));
        } else {
            for (int i = start; i + size <= nums.size(); ++i) {
                vector<int> nums_one_more = pres;
                nums_one_more.push_back(nums[i]);
                sub(con, nums, move(nums_one_more), i+1, size-1);
            }
        }
    }
};
