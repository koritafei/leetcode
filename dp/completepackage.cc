#include <iostream>
#include <vector>

class Solution {
public:
  int CompletePackage(std::vector<int> &weight,
                      std::vector<int> &val,
                      int               w,
                      int               n) {
    std::vector<std::vector<int>> dp =
        std::vector<std::vector<int>>(n + 1, std::vector<int>(w + 1, 0));
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= w; j++) {
        for (int k = 0; k * weight[i - 1] <= j; k++) {
          dp[i][j] =
              std::max(dp[i][j],
                       dp[i - 1][j - k * weight[i - 1]] + k * val[i - 1]);
        }
      }
    }

    return dp[n][w];
  }
};

int main() {
  int              n    = 3;
  std::vector<int> nums = {3, 4, 2};
  std::vector<int> v    = {4, 5, 3};
  int              w    = 7;
  Solution         sol;

  std::cout << sol.CompletePackage(nums, v, w, n) << std::endl;
}
