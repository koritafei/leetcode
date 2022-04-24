/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 *
 * https://leetcode.com/problems/target-sum/description/
 *
 * algorithms
 * Medium (45.31%)
 * Likes:    5658
 * Dislikes: 221
 * Total Accepted:    298.3K
 * Total Submissions: 658.3K
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

#include <map>
#include <string>
#include <vector>

// @lc code=start
class Solution {
public:
  int findTargetSumWays(std::vector<int>& nums, int target) {
    return dp(nums, target, 0, nums.size());
  }

private:
  int dp(std::vector<int>& nums, int target, int i, int len) {
    if (i == len) {
      if (0 == target) {
        return 1;
      }
      return 0;
    }

    // 转string
    std::string key = std::to_string(i) + "," + std::to_string(target);
    if (map.find(key) != map.end()) {
      return map[key];
    }

    int res = dp(nums, target - nums[i], i + 1, len) +
              dp(nums, target + nums[i], i + 1, len);
    map[key] = res;

    return res;
  }

  std::map<std::string, int> map;
};
// @lc code=end
