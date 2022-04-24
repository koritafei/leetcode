#include <iostream>
#include <vector>

class Solution {
public:
  bool partSum(int n, std::vector<int> &nums, int target) {
    sum = 0;
    return backtrack(n, nums, target, 0);
  }

private:
  bool backtrack(int n, std::vector<int> &nums, int target, int index) {
    if (index >= n) {
      return sum == target;
    }

    if (target == sum) {
      return true;
    } else if (target < sum) {
      return false;
    }

    for (int i = index; i < n; i++) {
      // 做选择
      sum += nums[i];
      if (backtrack(n, nums, target, i + 1)) {
        return true;
      }

      // 撤销选择
      sum -= nums[i];
    }
    return false;
  }

  int sum;
};

int main() {
  int              n      = 4;
  std::vector<int> nums   = {1, 2, 4, 7};
  int              target = 13;
  Solution         solution;
  std::cout << solution.partSum(n, nums, target) << std::endl;
  target = 15;
  std::cout << solution.partSum(n, nums, target) << std::endl;
}