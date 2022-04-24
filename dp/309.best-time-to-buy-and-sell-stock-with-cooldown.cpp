/*
 * @lc app=leetcode id=309 lang=cpp
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
 *
 * algorithms
 * Medium (50.95%)
 * Likes:    4956
 * Dislikes: 170
 * Total Accepted:    242.2K
 * Total Submissions: 474.6K
 * Testcase Example:  '[1,2,3,0,2]'
 *
 * You are given an array prices where prices[i] is the price of a given stock
 * on the i^th day.
 *
 * Find the maximum profit you can achieve. You may complete as many
 * transactions as you like (i.e., buy one and sell one share of the stock
 * multiple times) with the following restrictions:
 *
 *
 * After you sell your stock, you cannot buy stock on the next day (i.e.,
 * cooldown one day).
 *
 *
 * Note: You may not engage in multiple transactions simultaneously (i.e., you
 * must sell the stock before you buy again).
 *
 *
 * Example 1:
 *
 *
 * Input: prices = [1,2,3,0,2]
 * Output: 3
 * Explanation: transactions = [buy, sell, cooldown, buy, sell]
 *
 *
 * Example 2:
 *
 *
 * Input: prices = [1]
 * Output: 0
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= prices.length <= 5000
 * 0 <= prices[i] <= 1000
 *
 *
 */

#include <vector>

// @lc code=start
class Solution {
public:
  int maxProfit(std::vector<int>& prices) {
    int len = prices.size();
    if (len == 0) {
      return 0;
    }
    std::vector<std::vector<int>> dp(len + 1, std::vector<int>(2, 0));

    for (int i = 0; i < len; i++) {
      if (i - 1 == -1) {
        dp[i][0] = 0;
        dp[i][1] = -prices[i];
        continue;
      }

      if (i - 1 == 0) {
        dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
        dp[i][1] = std::max(dp[i - 1][1], -prices[i]);
        continue;
      }

      dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
      dp[i][1] = std::max(dp[i - 1][1], dp[i - 2][0] - prices[i]);
    }

    return dp[len - 1][0];
  }
};
// @lc code=end
