#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <sstream>

#include <problems/base.h>

using namespace std;

#include "problems/leetcode518.h"

void test() {
    SolutionLeetcode518 solution;
    cout << solution.change(10, vector<int>{10}) << endl;
}

int main() {
    test();
    return 0;
}