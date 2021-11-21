
#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
  int SarumansAramy(std::vector<int> &nums, int r, int n) {
    if (n == 0 || r <= 0) {
      return 0;
    }

    std::sort(nums.begin(), nums.end());
    int res = 0;
    int i   = 0;
    while (i < n) {
      int s = nums[i++];  // 最左端点

      while (i < n && s + r >= nums[i]) {
        i++;
      }
      int p = nums[i - 1];  // 被标记的点
      res++;
      while (i < n && p + r >= nums[i]) {
        i++;  // p+r的点
      }
    }

    return res;
  }
};

int main() {
  std::vector<int> nums = {1, 7, 15, 20, 30, 50};
  int              r    = 10;
  int              n    = 6;
  Solution         sol;
  std::cout << sol.SarumansAramy(nums, r, n) << std::endl;
}