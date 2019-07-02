#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <sstream>

#include <problems/base.h>
#include <problems/leetcode131.h>
#include <algorithm/tree.h>

using namespace std;

#include "problems/leetcode518.h"

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.empty()) return {};
        deque<int> deq;
        vector<int> res;
        for (auto i = 0, j = 0; i < nums.size(); ++i) {
            while (!deq.empty() && deq.front() + k <= i)
                deq.pop_front();
            while (!deq.empty() && nums[i] >= nums[deq.back()])
                deq.pop_back();
            deq.push_back(i);
            if (i+1 >= k) {
                res.push_back(nums[deq.front()]);
            }
        }
        return res;
    }
};

void print_vector(vector<int> const& v) {
    for (auto const& i : v)
        cout << i << ' ';
    cout << endl;
}

void test() {
    vector<int> v = {1,3,-1,-3,5,3,6,7};
    Solution solution;
    print_vector(solution.maxSlidingWindow(v, 3));
}

struct Compare {
    int operator()(int const& l, int const& r) {
        if (l < r) return -1;
        if (l > r) return 1;
        return 0;
    }
};

int main() {
    test();
    auto x = new algorithm::tree::AVLTree<int, Compare>();
    x->insert(1);
    return 0;
}