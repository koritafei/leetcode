/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 *
 * https://leetcode.com/problems/minimum-path-sum/description/
 *
 * algorithms
 * Medium (58.26%)
 * Likes:    6218
 * Dislikes: 89
 * Total Accepted:    631K
 * Total Submissions: 1.1M
 * Testcase Example:  '[[1,3,1],[1,5,1],[4,2,1]]'
 *
 * Given a m x n grid filled with non-negative numbers, find a path from top
 * left to bottom right, which minimizes the sum of all numbers along its
 * path.
 *
 * Note: You can only move either down or right at any point in time.
 *
 *
 * Example 1:
 *
 *
 * Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
 * Output: 7
 * Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
 *
 *
 * Example 2:
 *
 *
 * Input: grid = [[1,2,3],[4,5,6]]
 * Output: 12
 *
 *
 *
 * Constraints:
 *
 *
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 200
 * 0 <= grid[i][j] <= 100
 *
 *
 */

#include <climits>
#include <vector>

// @lc code=start
class Solution {
public:
  int minPathSum(std::vector<std::vector<int>>& grid) {
    int                           row = grid.size(), col = grid[0].size();
    std::vector<std::vector<int>> dp(row + 1, std::vector<int>(col + 1, 0));

    // base case
    dp[0][0] = grid[0][0];
    for (int i = 1; i < row; i++) {
      dp[i][0] = dp[i - 1][0] + grid[i][0];
    }

    for (int j = 1; j < col; j++) {
      dp[0][j] = dp[0][j - 1] + grid[0][j];
    }

    // 计算dp
    for (int i = 1; i < row; i++) {
      for (int j = 1; j < col; j++) {
        dp[i][j] = std::min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
      }
    }

    return dp[row - 1][col - 1];
  }
};
// @lc code=end
