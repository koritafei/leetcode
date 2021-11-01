/*
 * @lc app=leetcode id=188 lang=cpp
 *
 * [188] Best Time to Buy and Sell Stock IV
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/
 *
 * algorithms
 * Hard (30.32%)
 * Likes:    2446
 * Dislikes: 136
 * Total Accepted:    182.9K
 * Total Submissions: 602.9K
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

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
  int maxProfit(int k, vector<int>& prices) {
    int len = prices.size();
    if (len < 2 || k < 0) {
      return 0;
    }

    if (k > len / 2) {
      return maxProfit(prices);
    }

    vector<vector<vector<int>>> dp(
        len,
        vector<vector<int>>(k + 1, vector<int>(2, 0)));
    for (int j = 0; j < k + 1; j++) {
      dp[0][j][0] = 0;
      dp[0][j][1] = -prices[0];
    }

    for (int i = 1; i < len; i++) {
      for (int j = k; j >= 1; j--) {
        dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);
        dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);
      }
    }

    return dp[len - 1][k][0];
  }

private:
  int maxProfit(vector<int>& prices) {
    int len = prices.size();
    if (len < 2) {
      return 0;
    }
    vector<vector<int>> dp(len, vector<int>(2, 0));
    dp[0][0] = 0;
    dp[0][1] = -prices[0];

    for (int i = 1; i < len; i++) {
      dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
      dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
    }

    return dp[len - 1][0];
  }
};
// @lc code=end

int main(int argc, char** argv) {
  vector<int> prices = {2, 4, 1};
  int         k      = 2;
  Solution    solution;
  cout << solution.maxProfit(k, prices) << endl;
}