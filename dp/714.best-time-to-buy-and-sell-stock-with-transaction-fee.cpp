/*
 * @lc app=leetcode id=714 lang=cpp
 *
 * [714] Best Time to Buy and Sell Stock with Transaction Fee
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/
 *
 * algorithms
 * Medium (58.26%)
 * Likes:    2560
 * Dislikes: 74
 * Total Accepted:    110.4K
 * Total Submissions: 189.5K
 * Testcase Example:  '[1,3,2,8,4,9]\n2'
 *
 * You are given an array prices where prices[i] is the price of a given stock
 * on the i^th day, and an integer fee representing a transaction fee.
 *
 * Find the maximum profit you can achieve. You may complete as many
 * transactions as you like, but you need to pay the transaction fee for each
 * transaction.
 *
 * Note: You may not engage in multiple transactions simultaneously (i.e., you
 * must sell the stock before you buy again).
 *
 *
 * Example 1:
 *
 *
 * Input: prices = [1,3,2,8,4,9], fee = 2
 * Output: 8
 * Explanation: The maximum profit can be achieved by:
 * - Buying at prices[0] = 1
 * - Selling at prices[3] = 8
 * - Buying at prices[4] = 4
 * - Selling at prices[5] = 9
 * The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
 *
 *
 * Example 2:
 *
 *
 * Input: prices = [1,3,7,5,10,3], fee = 3
 * Output: 6
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= prices.length <= 5 * 10^4
 * 1 <= prices[i] < 5 * 10^4
 * 0 <= fee < 5 * 10^4
 *
 *
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
  int maxProfit(vector<int>& prices, int fee) {
    int len = prices.size();
    if (len < 2) {
      return 0;
    }

    int d_i0 = 0, d_i1 = INT_MIN;
    for (int i = 0; i < len; i++) {
      d_i0 = max(d_i0, d_i1 + prices[i]);
      d_i1 = max(d_i1, d_i0 - prices[i] - fee);
    }

    return d_i0;
  }
};
// @lc code=end

int main(int argc, char** argv) {
  vector<int> prices = {1, 3, 2, 8, 4, 9};
  int         fee    = 2;
  Solution    solution;
  cout << solution.maxProfit(prices, fee) << endl;
}
