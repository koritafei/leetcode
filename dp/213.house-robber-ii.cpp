/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 *
 * https://leetcode.com/problems/house-robber-ii/description/
 *
 * algorithms
 * Medium (38.78%)
 * Likes:    3963
 * Dislikes: 73
 * Total Accepted:    301.3K
 * Total Submissions: 776.7K
 * Testcase Example:  '[2,3,2]'
 *
 * You are a professional robber planning to rob houses along a street. Each
 * house has a certain amount of money stashed. All houses at this place are
 * arranged in a circle. That means the first house is the neighbor of the last
 * one. Meanwhile, adjacent houses have a security system connected, and it
 * will automatically contact the police if two adjacent houses were broken
 * into on the same night.
 *
 * Given an integer array nums representing the amount of money of each house,
 * return the maximum amount of money you can rob tonight without alerting the
 * police.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [2,3,2]
 * Output: 3
 * Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money
 * = 2), because they are adjacent houses.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,2,3,1]
 * Output: 4
 * Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
 * Total amount you can rob = 1 + 3 = 4.
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [1,2,3]
 * Output: 3
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 100
 * 0 <= nums[i] <= 1000
 *
 *
 */

#include <vector>

// @lc code=start
class Solution {
public:
  int rob(std::vector<int>& nums) {
    int len = nums.size();
    if (1 == len) {
      return nums[0];
    }

    // 分别对应第一间不抢，和最后一间不抢
    return std::max(rob(nums, 1, len - 1), rob(nums, 0, len - 2));
  }

private:
  // 求区间内最大值
  int rob(std::vector<int>& nums, int start, int end) {
    std::vector<int> dp(nums.size() + 2, 0);

    for (int i = end; i >= start; i--) {
      dp[i] = std::max(dp[i + 1], dp[i + 2] + nums[i]);
    }

    return dp[start];
  }
};
// @lc code=end
