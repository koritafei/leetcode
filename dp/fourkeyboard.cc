#include <algorithm>
#include <vector>

// 解法一
// 递归形式
int dp(int n, int aNum, int copy) {
  if (0 >= n) {
    return aNum;
  }

  return std::max(
      std::max(dp(n - 1, aNum + 1, copy), dp(n - 1, aNum + copy, copy)),
      dp(n - 2, aNum, aNum));
}

int maxA(int N) {
  return dp(N, 0, 0);
}

// 解法二
int maxA(int n) {
  std::vector<int> dp = std::vector<int>(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    // 按下A键
    dp[i] = dp[i - 1] + 1;
    for (int j = 2; j < i; j++) {
      dp[i] = std::max(dp[i], dp[j - 2] * (i - j + 1));
    }
  }

  return dp[n];
}