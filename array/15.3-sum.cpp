/*
 * @lc app=leetcode id=15 lang=cpp
 * @lcpr version=30113
 *
 * [15] 3Sum
 */

// @lcpr-template-start
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
  std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
    std::vector<std::vector<int>> res;
    int                           len = nums.size();

    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < len; i++) {
      int left = i + 1, right = len - 1;
      int target = -nums[i];
      while (left < right) {
        int t1 = nums[left], t2 = nums[right];
        int sum = t1 + t2;
        if (sum == target) {
          res.push_back({nums[i], nums[left], nums[right]});
          while ((++left) < right && nums[left] == t1)
            ;
          while (left < (--right) && t2 == nums[right])
            ;
        } else if (sum < target) {
          while ((++left) < right && nums[left] == t1)
            ;
        } else if (sum > target) {
          while (left < (--right) && t2 == nums[right])
            ;
        }
      }

      while (i + 1 < len && nums[i] == nums[i + 1]) {
        i++;
      }
    }

    return res;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [-1,0,1,2,-1,-4]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,1]\n
// @lcpr case=end

// @lcpr case=start
// [0,0,0]\n
// @lcpr case=end

 */
