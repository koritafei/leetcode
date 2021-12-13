/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 *
 * https://leetcode.com/problems/house-robber/description/
 *
 * algorithms
 * Medium (45.55%)
 * Likes:    9961
 * Dislikes: 228
 * Total Accepted:    930.2K
 * Total Submissions: 2M
 * Testcase Example:  '[1,2,3,1]'
 *
 * You are a professional robber planning to rob houses along a street. Each
 * house has a certain amount of money stashed, the only constraint stopping
 * you from robbing each of them is that adjacent houses have security systems
 * connected and it will automatically contact the police if two adjacent
 * houses were broken into on the same night.
 *
 * Given an integer array nums representing the amount of money of each house,
 * return the maximum amount of money you can rob tonight without alerting the
 * police.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,2,3,1]
 * Output: 4
 * Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
 * Total amount you can rob = 1 + 3 = 4.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [2,7,9,3,1]
 * Output: 12
 * Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house
 * 5 (money = 1).
 * Total amount you can rob = 2 + 9 + 1 = 12.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 100
 * 0 <= nums[i] <= 400
 *
 *
 */

#include <algorithm>
#include <vector>

// @lc code=start
class Solution {
public:
  int rob(std::vector<int>& nums) {
    int              len = nums.size();
    std::vector<int> memo(len + 1, -1);
    return rob(nums, 0, len, memo);
  }

public:
  int rob(std::vector<int>& nums, int index, int len, std::vector<int>& memo) {
    if (index >= len) {
      return 0;
    }
    if (memo[index] != -1) {
      return memo[index];
    }

    int res     = std::max(rob(nums, index + 1, len, memo),
                       nums[index] + rob(nums, index + 2, len, memo));
    memo[index] = res;
    return res;
  }
};
// @lc code=end
