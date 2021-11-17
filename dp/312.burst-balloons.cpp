/*
 * @lc app=leetcode id=312 lang=cpp
 *
 * [312] Burst Balloons
 *
 * https://leetcode.com/problems/burst-balloons/description/
 *
 * algorithms
 * Hard (54.79%)
 * Likes:    4428
 * Dislikes: 124
 * Total Accepted:    151.1K
 * Total Submissions: 275.6K
 * Testcase Example:  '[3,1,5,8]'
 *
 * You are given n balloons, indexed from 0 to n - 1. Each balloon is painted
 * with a number on it represented by an array nums. You are asked to burst all
 * the balloons.
 *
 * If you burst the i^th balloon, you will get nums[i - 1] * nums[i] * nums[i +
 * 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it
 * as if there is a balloon with a 1 painted on it.
 *
 * Return the maximum coins you can collect by bursting the balloons wisely.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [3,1,5,8]
 * Output: 167
 * Explanation:
 * nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
 * coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167
 *
 * Example 2:
 *
 *
 * Input: nums = [1,5]
 * Output: 10
 *
 *
 *
 * Constraints:
 *
 *
 * n == nums.length
 * 1 <= n <= 500
 * 0 <= nums[i] <= 100
 *
 *
 */

#include <vector>

// @lc code=start
class Solution {
public:
  int maxCoins(std::vector<int>& nums) {
    int n = nums.size();
    if (n == 0) {
      return 0;
    }

    // 添加两端构造新数组
    std::vector<int> points = std::vector<int>(n + 2, 1);
    for (int i = 1; i < n + 1; i++) {
      points[i] = nums[i - 1];
    }

    // 构造dp
    std::vector<std::vector<int>> dp =
        std::vector<std::vector<int>>(n + 2, std::vector<int>(n + 2, 0));

    // 开始状态转移，i 从上到下
    for (int i = n; i >= 0; i--) {
      // j从右向左
      for (int j = i + 1; j < n + 2; j++) {
        // 最后戳破的气球
        for (int k = i + 1; k < j; k++) {
          // 择优选择
          dp[i][j] =
              std::max(dp[i][j],
                       dp[i][k] + dp[k][j] + points[i] * points[j] * points[k]);
        }
      }
    }

    return dp[0][n + 1];
  }
};
// @lc code=end
