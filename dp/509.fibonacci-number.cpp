/*
 * @lc app=leetcode id=509 lang=cpp
 *
 * [509] Fibonacci Number
 *
 * https://leetcode.com/problems/fibonacci-number/description/
 *
 * algorithms
 * Easy (68.05%)
 * Likes:    2844
 * Dislikes: 253
 * Total Accepted:    647.5K
 * Total Submissions: 951.6K
 * Testcase Example:  '2'
 *
 * The Fibonacci numbers, commonly denoted F(n) form a sequence, called the
 * Fibonacci sequence, such that each number is the sum of the two preceding
 * ones, starting from 0 and 1. That is,
 *
 *
 * F(0) = 0, F(1) = 1
 * F(n) = F(n - 1) + F(n - 2), for n > 1.
 *
 *
 * Given n, calculate F(n).
 *
 *
 * Example 1:
 *
 *
 * Input: n = 2
 * Output: 1
 * Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.
 *
 *
 * Example 2:
 *
 *
 * Input: n = 3
 * Output: 2
 * Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.
 *
 *
 * Example 3:
 *
 *
 * Input: n = 4
 * Output: 3
 * Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= n <= 30
 *
 *
 */

#include <vector>

// @lc code=start
class Solution {
public:
  // 递归方式
  int fib1(int n) {
    if (n == 0) {
      return 0;
    }
    if (n == 1) {
      return 1;
    }

    return fib1(n - 1) + fib1(n - 2);
  }

  // 备忘录方式
  int fib2(int n) {
    std::vector<int> memo(std::vector<int>(n + 1, -1));
    return fib2(n, memo);
  }

  // dp 方式
  int fib(int n) {
    if (0 == n) {
      return 0;
    }

    if (1 == n) {
      return 1;
    }
    std::vector<int> dp(n + 1, 0);

    // base case
    dp[1] = 1;

    // dp数组计算
    for (int i = 2; i <= n; i++) {
      dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
  }

private:
  int fib2(int n, std::vector<int> &memo) {
    if (n == 0) {
      return 0;
    }

    if (n == 1) {
      return 1;
    }

    if (memo[n] != -1) {
      return memo[n];
    }

    memo[n] = fib2(n - 1, memo) + fib2(n - 2, memo);

    return memo[n];
  }
};
// @lc code=end
