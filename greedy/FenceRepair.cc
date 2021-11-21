#include <iostream>
#include <queue>
#include <vector>

class Solution {
public:
  int FenceRepair(std::vector<int> &nums, int n) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> heap;
    int                                                           ans = 0;
    for (int i = 0; i < n; i++) {
      heap.push(nums[i]);
    }

    while (heap.size() > 1) {
      int min1 = heap.top();
      heap.pop();
      int min2 = heap.top();
      heap.pop();

      int sum = min1 + min2;
      ans += sum;
      heap.push(sum);
    }

    return ans;
  }
};

int main() {
  Solution         sol;
  std::vector<int> nums = {8, 5, 8};
  int              n    = 3;
  std::cout << sol.FenceRepair(nums, n) << std::endl;
}
