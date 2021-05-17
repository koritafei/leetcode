/*
 * @lc app=leetcode id=309 lang=cpp
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
 *
 * algorithms
 * Medium (48.58%)
 * Likes:    3660
 * Dislikes: 117
 * Total Accepted:    194.1K
 * Total Submissions: 399.5K
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

    int d_i0 = 0, d_i1 = INT_MIN;
    int pre = 0;

    for (int i = 0; i < len; i++) {
      int tmp = d_i0;
      d_i0    = max(d_i0, d_i1 + prices[i]);
      d_i1    = max(d_i1, pre - prices[i]);
      pre     = tmp;
    }

    return d_i0;
  }
};
// @lc code=end

int main(int argc, char** argv) {
  vector<int> prices = {1, 2, 3, 0, 2};
  Solution    solution;
  cout << solution.maxProfit(prices) << endl;
}
