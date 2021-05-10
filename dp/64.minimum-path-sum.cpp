/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 *
 * https://leetcode.com/problems/minimum-path-sum/description/
 *
 * algorithms
 * Medium (56.29%)
 * Likes:    4403
 * Dislikes: 80
 * Total Accepted:    516.8K
 * Total Submissions: 917.9K
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

// @lc code=start
class Solution {
public:
  int minPathSum(vector<vector<int>>& grid) {
    int row = grid.size();
    if (row == 0) {
      return 0;
    }
    int col = grid[0].size();
    if (col == 0) {
      return 0;
    }

    vector<vector<int>> dp(row, vector<int>(col, 0));

    for (int i = 0; i < col; i++) {
      dp[0][i] = grid[0][i];
    }
    for (int i = 0; i < row; i++) {
      dp[i][0] = grid[i][0];
    }

    for (int i = 1; i < col; i++) {
      dp[0][i] = dp[0][i - 1] + grid[0][i];
    }
    for (int i = 1; i < row; i++) {
      dp[i][0] = dp[i - 1][0] + grid[i][0];
    }

    for (int i = 1; i < row; i++) {
      for (int j = 1; j < col; j++) {
        dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]) + grid[i][j];
      }
    }

    return dp[row - 1][col - 1];
  }
};
// @lc code=end
