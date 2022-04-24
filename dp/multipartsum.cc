#include <iostream>
#include <vector>

class Solution {
public:
  bool MultiPartSum(std::vector<int> &nums, std::vector<int> &m, int n, int K) {
    std::vector<std::vector<bool>> dp =
        std::vector<std::vector<bool>>(n + 1, std::vector<bool>(K + 1, false));
    dp[0][0] = true;

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= K; j++) {
        for (int k = 0; k <= m[i - 1] && k * nums[i - 1] <= j; k++) {
          dp[i][j] = dp[i][j] | dp[i - 1][j - nums[i - 1] * k];
        }
      }
    }

    return dp[n][K];
  }
};

int main() {
  std::vector<int> nums = {3, 5, 8};
  std::vector<int> m    = {3, 2, 2};
  int              n    = 3;
  int              K    = 17;
  Solution         solution;
  std::cout << solution.MultiPartSum(nums, m, n, K) << std::endl;
}
