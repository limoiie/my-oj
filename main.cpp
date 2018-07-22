#include <iostream>
#include "leetcode097.h"
#include "leetcode054.h"
#include "leetcode084.h"
#include "leetcode057.h"
#include "leetcode830.h"
#include "leetcode831.h"
#include "leetcode466.h"
#include "leetcode473.h"
#include "leetcode650.h"
#include "leetcode667.h"
#include "leetcode668.h"
#include "leetcode546.h"
#include "leetcode347.h"

void test_leetcode_097() {
    SolutionLeetcode097 solutionLeetcode;
    cout << solutionLeetcode.isInterleave("aabcc", "dbbca", "aadbbcbcac") << endl;
    cout << solutionLeetcode.isInterleave("aabcc", "dbbca", "aadbbbaccc") << endl;
}

void test_leetcode_054() {
    SolutionLeetCode054 solutionLeetCode;
    vector<vector<int>> m = {{1}};
    auto x = solutionLeetCode.spiralOrder(m);
    for (auto const &i : x)
        cout << i << " ";
    cout << endl;
}

void test_leetcode_084() {
    auto x = vector<int>{2,1,5,6,2,3};

    SolutionLeetCode084 solutionLeetCode;
    cout << solutionLeetCode.largestRectangleArea(x) << endl;
}

void test_leetcode_057() {
    SolutionLeetCode057 solution;

    vector<Interval> intervals = {
//            {1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}
            {1, 3}, {6, 9}
    };
    Interval interval = {2, 5};
    auto newIntervals = solution.insert(intervals, interval);
    for (auto const& item : newIntervals) {
        cout << "s: " << item.start << ", e: " << item.end << endl;
    }
}

void test_leetcode_830() {
    SolutionLeetCode830 solution;
    solution.largeGroupPositions("abcdddeeeeaabbbcd");
}

void test_leetcode_831() {
    SolutionLeetCode831 solution;
//    cout << solution.maskPII("LeetCode@LeetCode.com") << endl;
    string s = "86-(10)12345678";
    cout << solution.maskPII(s) << endl;
}

void test_leetcode_466() {
    SolutionLeetcode466 solution;
    cout << solution.getMaxRepetitions("aaa", 20, "bbb", 1) << endl;
}

void test_leetcode_473() {
    SolutionLeetCode473 solution{};
    auto x = vector<int>{1, 1, 2, 2, 2};
    cout << solution.makesquare(x) << endl;
    auto y = vector<int>{1, 1, 1, 1, 2, 2, 2, 2};
    cout << solution.makesquare(y) << endl;
}

void test_leetcode_464() {
    int n;
    while (cin >> n) {
        SolutionLeetcode650 solution;
        cout << solution.minSteps(n) << endl;
        cout << solution.minSteps2(n) << endl;
    }
}

void test_leetcode_668() {

}

int main() {
//    test_leetcode_097();
//    test_leetcode_806();
//    test_leetcode_464();
    SolutionLeetcode347 solution;
    vector<int> nums = {1};
    auto arr = solution.topKFrequent(nums, 1);
    for (const auto &num : arr)
        cout << num << " ";
    cout << endl;
    return 0;
}
