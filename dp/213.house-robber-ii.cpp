/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 *
 * https://leetcode.com/problems/house-robber-ii/description/
 *
 * algorithms
 * Medium (38.98%)
 * Likes:    4270
 * Dislikes: 76
 * Total Accepted:    318.7K
 * Total Submissions: 816.5K
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

#include <algorithm>
#include <vector>

// @lc code=start
class Solution {
public:
  int rob(std::vector<int> &nums) {
    int len = nums.size();
    if (len == 0) {
      return 0;
    }

    if (len == 1) {
      return nums[0];
    }

    std::vector<int> memo1 = std::vector<int>(len, -1);
    std::vector<int> memo2 = std::vector<int>(len, -1);
    return std::max(rob(nums, 0, len - 2, memo1), rob(nums, 1, len - 1, memo2));
  }

private:
  int rob(std::vector<int> &nums, int index, int len, std::vector<int> &memo) {
    if (index > len) {
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
