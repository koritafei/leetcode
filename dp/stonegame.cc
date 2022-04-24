#include <vector>

// 返回先后手分值差
int stoneGame(std::vector<int> &piles) {
  int n = piles.size();
  if (n == 0) {
    return 0;
  }

  std::vector<std::vector<std::pair<int, int>>> dp =
      std::vector<std::vector<std::pair<int, int>>>(
          n + 1,
          std::vector<std::pair<int, int>>(n + 1, std::make_pair(0, 0)));

  // base case
  for (int i = 0; i < n; i++) {
    dp[i][0] = std::make_pair(piles[i], 0);
  }

  // 计算dp数组
  for (int i = 2; i <= n; i++) {
    for (int j = 0; j <= n - 1; j++) {
      // 斜着遍历数组
      int l = i + j - 1;
      // 先手选择左边或右边的石子
      int left  = piles[i] + dp[i + 1][j].second;
      int right = piles[j] + dp[i][j - 1].second;

      // 套用状态转移方程
      if (left > right) {
        dp[i][j].first  = left;
        dp[i][j].second = dp[i + 1][j].first;
      } else {
        dp[i][j].first  = right;
        dp[i][j].second = dp[i][j - 1].first;
      }
    }

    auto res = dp[0][n - 1];

    return res.second - res.first;
  }
}
