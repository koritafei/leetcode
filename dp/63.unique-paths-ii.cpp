/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 *
 * https://leetcode.com/problems/unique-paths-ii/description/
 *
 * algorithms
 * Medium (36.77%)
 * Likes:    3918
 * Dislikes: 347
 * Total Accepted:    452.7K
 * Total Submissions: 1.2M
 * Testcase Example:  '[[0,0,0],[0,1,0],[0,0,0]]'
 *
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in
 * the diagram below).
 *
 * The robot can only move either down or right at any point in time. The robot
 * is trying to reach the bottom-right corner of the grid (marked 'Finish' in
 * the diagram below).
 *
 * Now consider if some obstacles are added to the grids. How many unique paths
 * would there be?
 *
 * An obstacle and space is marked as 1 and 0 respectively in the grid.
 *
 *
 * Example 1:
 *
 *
 * Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
 * Output: 2
 * Explanation: There is one obstacle in the middle of the 3x3 grid above.
 * There are two ways to reach the bottom-right corner:
 * 1. Right -> Right -> Down -> Down
 * 2. Down -> Down -> Right -> Right
 *
 *
 * Example 2:
 *
 *
 * Input: obstacleGrid = [[0,1],[0,0]]
 * Output: 1
 *
 *
 *
 * Constraints:
 *
 *
 * m == obstacleGrid.length
 * n == obstacleGrid[i].length
 * 1 <= m, n <= 100
 * obstacleGrid[i][j] is 0 or 1.
 *
 *
 */

#include <vector>

// @lc code=start
class Solution {
public:
  int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid) {
    int row = obstacleGrid.size(), col = obstacleGrid[0].size();
    std::vector<std::vector<int>> dp(row + 1, std::vector<int>(col + 1, 0));

    for (int i = 0; i < row; i++) {
      if (obstacleGrid[i][0] != 1) {
        dp[i][0] = 1;
      } else {
        break;
      }
    }

    for (int j = 0; j < col; j++) {
      if (1 != obstacleGrid[0][j]) {
        dp[0][j] = 1;
      } else {
        break;
      }
    }

    for (int i = 1; i < row; i++) {
      for (int j = 1; j < col; j++) {
        if (obstacleGrid[i][j] != 1) {
          dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
      }
    }

    return dp[row - 1][col - 1];
  }
};
// @lc code=end
