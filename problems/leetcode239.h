#include "problems/base.h"

using namespace std;

class SolutionLeetCode239 {
public:
  vector<int> maxSlidingWindow(vector<int>& nums, int const k) {
    if (nums.empty()) return {};
    deque<int> deq;
    vector<int> res;
    for (auto i = 0, j = 0; i < nums.size(); ++i) {
      while (!deq.empty() && deq.front()+k <= i)
        deq.pop_front();
      while (!deq.empty() && nums[i] >= nums[deq.back()])
        deq.pop_back();
      deq.push_back(i);
      if (i+1>=k)
        res[j++] = nums[deq.front()];
    }
    return res;
  }
}
