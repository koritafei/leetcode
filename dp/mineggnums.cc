#include <climits>
#include <vector>

int minegg(int k, int n, std::vector<std::vector<int>> memo) {
  if (k == 1) {
    return n;
  }
  if (n == 0) {
    return 0;
  }

  if (memo[k][n] != 0) {
    return memo[k][n];
  }

  int res = INT_MAX;
  for (int i = 1; i <= n; i++) {
    res = std::min(
        res,
        1 + std::max(minegg(k - 1, i - 1, memo), minegg(k, n - i, memo)));
  }

  memo[k][n] = res;

  return memo[k][n];
}

int superEggDrop(int k, int n) {
  std::vector<std::vector<int>> memo =
      std::vector<std::vector<int>>(k + 1, std::vector<int>(n + 1, 0));
  return minegg(k, n, memo);
}
