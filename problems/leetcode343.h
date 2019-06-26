#ifndef LEETCODE_343_H
#define LEETCODE_343_H

#include "bash.h"

class Solution {
public:
  int integerBreak(int n) {
    if (n == 2) return 1;
    memset(mem, 0, sizeof(mem));
    mem[1] = 1, mem[2] = 2, mem[3] = 3, mem[4] = 4, mem[5] = 6;
    return max_product(n, true);
  }

private:
  int max_product(int n, bool must_break=false) {
    if (mem[n] == 0) {
      auto product = mem[n];
      for (auto i = 1, h = n>>1; i <= h; ++i)
        product = max(product, max_product(i) * max_product(n-i));
       mem[n] = must_break ? product : max(product, n);
    }
    return mem[n];
  }
  
  int mem[60];
  
};

#endif // LEETCODE_343_H
