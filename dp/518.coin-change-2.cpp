/*
 * @lc app=leetcode id=518 lang=cpp
 *
 * [518] Coin Change 2
 *
 * https://leetcode.com/problems/coin-change-2/description/
 *
 * algorithms
 * Medium (55.48%)
 * Likes:    4257
 * Dislikes: 91
 * Total Accepted:    246.3K
 * Total Submissions: 443K
 * Testcase Example:  '5\n[1,2,5]'
 *
 * You are given an integer array coins representing coins of different
 * denominations and an integer amount representing a total amount of money.
 *
 * Return the number of combinations that make up that amount. If that amount
 * of money cannot be made up by any combination of the coins, return 0.
 *
 * You may assume that you have an infinite number of each kind of coin.
 *
 * The answer is guaranteed to fit into a signed 32-bit integer.
 *
 *
 * Example 1:
 *
 *
 * Input: amount = 5, coins = [1,2,5]
 * Output: 4
 * Explanation: there are four ways to make up the amount:
 * 5=5
 * 5=2+2+1
 * 5=2+1+1+1
 * 5=1+1+1+1+1
 *
 *
 * Example 2:
 *
 *
 * Input: amount = 3, coins = [2]
 * Output: 0
 * Explanation: the amount of 3 cannot be made up just with coins of 2.
 *
 *
 * Example 3:
 *
 *
 * Input: amount = 10, coins = [10]
 * Output: 1
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= coins.length <= 300
 * 1 <= coins[i] <= 5000
 * All the values of coins are unique.
 * 0 <= amount <= 5000
 *
 *
 */

#include <vector>

// @lc code=start
class Solution {
public:
  int change(int amount, std::vector<int>& coins) {
    int len = coins.size();

    std::vector<std::vector<int>> memo(len + 1,
                                       std::vector<int>(amount + 1, 0));

    // base case
    for (int i = 0; i <= len; i++) {
      memo[i][0] = 1;
    }

    // dp
    for (int i = 1; i <= len; i++) {
      for (int j = 1; j <= amount; j++) {
        if (j - coins[i - 1] >= 0) {
          memo[i][j] = memo[i - 1][j] + memo[i][j - coins[i - 1]];
        } else {
          memo[i][j] = memo[i - 1][j];
        }
      }
    }

    return memo[len][amount];
  }
};
// @lc code=end
