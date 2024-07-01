/*
 * @lc app=leetcode id=18 lang=cpp
 * @lcpr version=30113
 *
 * [18] 4Sum
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
  std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
    std::vector<std::vector<int>> res;

    int len = nums.size();

    std::sort(nums.begin(), nums.end());

    for (int i = 0; i < len; i++) {
      int64_t find1 = target - nums[i];
      for (int j = i + 1; j < len; j++) {
        int64_t find2 = find1 - nums[j];
        int     left = j + 1, right = len - 1;
        while (left < right) {
          int     t1 = nums[left], t2 = nums[right];
          int64_t sum = t1 + t2;
          if (sum == find2) {
            res.push_back({nums[i], nums[j], nums[left], nums[right]});
            while ((++left < right) && nums[left] == t1)
              ;
            while ((left < (--right)) && t2 == nums[right])
              ;
          } else if (sum < find2) {
            while ((++left < right) && nums[left] == t1)
              ;
          } else if (sum > find2) {
            while ((left < (--right)) && t2 == nums[right])
              ;
          }
        }
        while ((j + 1 < len - 1) && nums[j] == nums[j + 1]) {
          j++;
        }
      }
      while ((i + 1 < len - 1) && nums[i] == nums[i + 1]) {
        i++;
      }
    }

    return res;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [1,0,-1,0,-2,2]\n0\n
// @lcpr case=end

// @lcpr case=start
// [2,2,2,2,2]\n8\n
// @lcpr case=end

 */
