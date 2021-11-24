#include <vector>

class Solution {
public:
  // 动态规划解法
  int coinNum(std::vector<int> &nums, int aim) {
    int len = nums.size();
    if (0 == len || aim == 0) {
      return 0;
    }

    std::vector<std::vector<int>> memo =
        std::vector<std::vector<int>>(len + 1, std::vector<int>(aim + 1, 0));

    // base case
    for (int i = 0; i <= len; i++) {
      memo[i][0] = 1;
    }

    for (int i = 0; i * nums[0] <= aim; i++) {
      memo[0][i] = 1;
    }

    // 计算dp
    int res = 0;
    for (int i = 1; i <= len; i++) {
      for (int j = 1; j <= aim; j++) {
        res = 0;
        for (int k = 0; nums[i - 1] * k <= j; k++) {
          res += memo[i][j - nums[i - 1] * k];
        }
        memo[i][j] = res;
      }
    }
    return memo[len][aim];
  }
};
