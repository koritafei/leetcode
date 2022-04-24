/*
 * @lc app=leetcode id=188 lang=cpp
 *
 * [188] Best Time to Buy and Sell Stock IV
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/
 *
 * algorithms
 * Hard (32.11%)
 * Likes:    3280
 * Dislikes: 149
 * Total Accepted:    215.2K
 * Total Submissions: 668.3K
 * Testcase Example:  '2\n[2,4,1]'
 *
 * You are given an integer array prices where prices[i] is the price of a
 * given stock on the i^th day, and an integer k.
 *
 * Find the maximum profit you can achieve. You may complete at most k
 * transactions.
 *
 * Note: You may not engage in multiple transactions simultaneously (i.e., you
 * must sell the stock before you buy again).
 *
 *
 * Example 1:
 *
 *
 * Input: k = 2, prices = [2,4,1]
 * Output: 2
 * Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit
 * = 4-2 = 2.
 *
 *
 * Example 2:
 *
 *
 * Input: k = 2, prices = [3,2,6,5,0,3]
 * Output: 7
 * Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit
 * = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3),
 * profit = 3-0 = 3.
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= k <= 100
 * 0 <= prices.length <= 1000
 * 0 <= prices[i] <= 1000
 *
 *
 */

#include <vector>

// @lc code=start
class Solution {
public:
  int maxProfit(int k, std::vector<int>& prices) {
    int len = prices.size();

    if (len == 0 || k == 0) {
      return 0;
    }

    std::vector<std::vector<std::vector<int>>> dp(
        len + 1,
        std::vector<std::vector<int>>(k + 1, std::vector<int>(2, 0)));

    for (int i = 0; i < len; i++) {
      for (int j = k; j >= 1; j--) {
        if (-1 == i - 1) {
          dp[i][j][0] = 0;
          dp[i][j][1] = -prices[i];
          continue;
        }

        dp[i][j][0] = std::max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);
        dp[i][j][1] =
            std::max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);
      }
    }

    return dp[len - 1][k][0];
  }
};
// @lc code=end
