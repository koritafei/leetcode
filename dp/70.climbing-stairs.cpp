/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 *
 * https://leetcode.com/problems/climbing-stairs/description/
 *
 * algorithms
 * Easy (48.67%)
 * Likes:    6103
 * Dislikes: 192
 * Total Accepted:    909.3K
 * Total Submissions: 1.9M
 * Testcase Example:  '2'
 *
 * You are climbing a staircase. It takes n steps to reach the top.
 *
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can
 * you climb to the top?
 *
 *
 * Example 1:
 *
 *
 * Input: n = 2
 * Output: 2
 * Explanation: There are two ways to climb to the top.
 * 1. 1 step + 1 step
 * 2. 2 steps
 *
 *
 * Example 2:
 *
 *
 * Input: n = 3
 * Output: 3
 * Explanation: There are three ways to climb to the top.
 * 1. 1 step + 1 step + 1 step
 * 2. 1 step + 2 steps
 * 3. 2 steps + 1 step
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 45
 *
 *
 */

// @lc code=start
class Solution {
public:
  int climbStairs(int n) {
    if (n == 0 || n == 1) {
      return 1;
    }

    vector<int> memo(n + 1, -1);
    memo[0] = memo[1] = 1;

    for (int i = 2; i <= n; i++) {
      memo[i] = memo[i - 1] + memo[i - 2];
    }

    return memo[n];
  }
};
// @lc code=end
