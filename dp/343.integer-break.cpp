/*
 * @lc app=leetcode id=343 lang=cpp
 *
 * [343] Integer Break
 *
 * https://leetcode.com/problems/integer-break/description/
 *
 * algorithms
 * Medium (51.24%)
 * Likes:    1465
 * Dislikes: 254
 * Total Accepted:    126.1K
 * Total Submissions: 246.1K
 * Testcase Example:  '2'
 *
 * Given an integer n, break it into the sum of at least two positive integers
 * and maximize the product of those integers.
 *
 * Return the maximum product you can get.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 2
 * Output: 1
 * Explanation: 2 = 1 + 1, 1 × 1 = 1.
 *
 *
 * Example 2:
 *
 *
 * Input: n = 10
 * Output: 36
 * Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
 *
 *
 *
 * Constraints:
 *
 *
 * 2 <= n <= 58
 *
 *
 */

// @lc code=start
class Solution {
public:
  int integerBreak(int n) {
    vector<int> res(n + 1, -1);
    res[1] = 1;
    res[2] = 1;

    for (int i = 3; i <= n; i++) {
      for (int j = 1; j < i; j++) {
        res[i] = max(res[i], max(j * (i - j), res[i - j] * j));
      }
    }

    return res[n];
  }
};
// @lc code=end
