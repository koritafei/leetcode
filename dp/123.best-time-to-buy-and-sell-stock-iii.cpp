/*
 * @lc app=leetcode id=123 lang=cpp
 *
 * [123] Best Time to Buy and Sell Stock III
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/
 *
 * algorithms
 * Hard (40.37%)
 * Likes:    3553
 * Dislikes: 90
 * Total Accepted:    290.9K
 * Total Submissions: 720.5K
 * Testcase Example:  '[3,3,5,0,0,3,1,4]'
 *
 * You are given an array prices where prices[i] is the price of a given stock
 * on the i^th day.
 *
 * Find the maximum profit you can achieve. You may complete at most two
 * transactions.
 *
 * Note: You may not engage in multiple transactions simultaneously (i.e., you
 * must sell the stock before you buy again).
 *
 *
 * Example 1:
 *
 *
 * Input: prices = [3,3,5,0,0,3,1,4]
 * Output: 6
 * Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit
 * = 3-0 = 3.
 * Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 =
 * 3.
 *
 * Example 2:
 *
 *
 * Input: prices = [1,2,3,4,5]
 * Output: 4
 * Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit
 * = 5-1 = 4.
 * Note that you cannot buy on day 1, buy on day 2 and sell them later, as you
 * are engaging multiple transactions at the same time. You must sell before
 * buying again.
 *
 *
 * Example 3:
 *
 *
 * Input: prices = [7,6,4,3,1]
 * Output: 0
 * Explanation: In this case, no transaction is done, i.e. max profit = 0.
 *
 *
 * Example 4:
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
 * 1 <= prices.length <= 10^5
 * 0 <= prices[i] <= 10^5
 *
 *
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int len = prices.size();
    if (len < 2) {
      return 0;
    }
    vector<vector<vector<int> > > dp(
        len,
        vector<vector<int> >(3, vector<int>(2, 0)));

    for (int i = 0; i < len; i++) {
      for (int k = 2; k >= 1; k--) {
        if (i - 1 == -1) {
          dp[i][0][0] = 0;
          dp[i][0][1] = -prices[i];
          dp[i][1][0] = 0;
          dp[i][1][1] = -prices[i];
          dp[i][2][0] = 0;
          dp[i][2][1] = -prices[i];
          continue;
        }

        dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1] + prices[i]);
        dp[i][k][1] = max(dp[i - 1][k][1], dp[i - 1][k - 1][0] - prices[i]);
      }
    }

    return dp[len - 1][2][0];

    // int dp_i10 = 0, dp_i11 = INT_MIN;
    // int dp_i20 = 0, dp_i21 = INT_MIN;
    // for (int price : prices) {
    //   dp_i20 = max(dp_i20, dp_i21 + price);
    //   dp_i21 = max(dp_i21, dp_i10 - price);
    //   dp_i10 = max(dp_i10, dp_i11 + price);
    //   dp_i11 = max(dp_i11, -price);
    // }
    // return dp_i20;
  }
};
// @lc code=end

int main(int argc, char** argv) {
  vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
  Solution    solution;
  cout << solution.maxProfit(prices) << endl;
}