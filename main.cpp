#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <sstream>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = static_cast<int>(nums.size()) - 1;
        while (l <= r) {
            auto m = (l + r) >> 1;
            if (nums[m] > nums.back()) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return nums[l];
    }
};

void test() {
    vector<vector<int>> nums_list = {
            {3,4,5,1,2},
            {4,5,6,7,0,1,2}
    };

    Solution solution;
    for (auto & nums : nums_list) {
        cout << solution.findMin(nums) << endl;
    }
}

int main() {
    test();
    return 0;
}