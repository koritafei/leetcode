/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 *
 * https://leetcode.com/problems/target-sum/description/
 *
 * algorithms
 * Medium (45.24%)
 * Likes:    5509
 * Dislikes: 216
 * Total Accepted:    291.8K
 * Total Submissions: 644.4K
 * Testcase Example:  '[1,1,1,1,1]\n3'
 *
 * You are given an integer array nums and an integer target.
 *
 * You want to build an expression out of nums by adding one of the symbols '+'
 * and '-' before each integer in nums and then concatenate all the
 * integers.
 *
 *
 * For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1
 * and concatenate them to build the expression "+2-1".
 *
 *
 * Return the number of different expressions that you can build, which
 * evaluates to target.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,1,1,1,1], target = 3
 * Output: 5
 * Explanation: There are 5 ways to assign symbols to make the sum of nums be
 * target 3.
 * -1 + 1 + 1 + 1 + 1 = 3
 * +1 - 1 + 1 + 1 + 1 = 3
 * +1 + 1 - 1 + 1 + 1 = 3
 * +1 + 1 + 1 - 1 + 1 = 3
 * +1 + 1 + 1 + 1 - 1 = 3
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1], target = 1
 * Output: 1
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 20
 * 0 <= nums[i] <= 1000
 * 0 <= sum(nums[i]) <= 1000
 * -1000 <= target <= 1000
 *
 *
 */

#include <vector>

// @lc code=start
class Solution {
public:
  int findTargetSumWays(std::vector<int>& nums, int target) {
    int res = 0;
    findTargetSumWays(nums, target, 0, res);
    return res;
  }

private:
  void findTargetSumWays(std::vector<int>& nums, int target, int i, int& res) {
    // 终止循环
    if (i == nums.size()) {
      if (target == 0) {  // 找到一个组合
        res++;
      }
      return;
    }

    // 做一个选择
    target -= nums[i];
    findTargetSumWays(nums, target, i + 1, res);
    // 撤销选择
    target += nums[i];

    // 做一个选择
    target += nums[i];
    findTargetSumWays(nums, target, i + 1, res);
    // 撤销选择
    target -= nums[i];
  }
};
// @lc code=end
