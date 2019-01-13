#include <iostream>
#include <stdio.h>
#include <memory.h>

using namespace std;

int m, n, nums[1001];

int main() {
  char c;
  while (scanf("%d%c", &nums[0], &c) != EOF) {
    n = 1;
    while (c != '\n')
      scanf("%d%c", &nums[n++], &c);
    scanf("%d", &m);

    bool dp[m+1];
    memset(dp, 0, sizeof(dp));
    dp[0] = true;

    for (int i = 0; i < n; ++i)
      for (int j = m; j >= nums[i]; --j)
        dp[j] |= dp[j-nums[i]];

    printf(dp[m] ? "Yes\n" : "No\n");
  }
  return 0;
}
