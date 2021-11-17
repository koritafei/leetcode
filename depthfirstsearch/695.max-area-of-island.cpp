/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
 *
 * https://leetcode.com/problems/max-area-of-island/description/
 *
 * algorithms
 * Medium (68.03%)
 * Likes:    4693
 * Dislikes: 123
 * Total Accepted:    363.4K
 * Total Submissions: 533.4K
 * Testcase Example:
 * '[[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]'
 *
 * You are given an m x n binary matrix grid. An island is a group of 1's
 * (representing land) connected 4-directionally (horizontal or vertical.) You
 * may assume all four edges of the grid are surrounded by water.
 *
 * The area of an island is the number of cells with a value 1 in the island.
 *
 * Return the maximum area of an island in grid. If there is no island, return
 * 0.
 *
 *
 * Example 1:
 *
 *
 * Input: grid =
 * [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
 * Output: 6
 * Explanation: The answer is not 11, because the island must be connected
 * 4-directionally.
 *
 *
 * Example 2:
 *
 *
 * Input: grid = [[0,0,0,0,0,0,0,0]]
 * Output: 0
 *
 *
 *
 * Constraints:
 *
 *
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 50
 * grid[i][j] is either 0 or 1.
 *
 *
 */

#include <vector>

// @lc code=start
class Solution {
public:
  int maxAreaOfIsland(std::vector<std::vector<int>>& grid) {
    int row = grid.size(), col = 0;
    if (row == 0) {
      return 0;
    } else {
      col = grid[0].size();
    }

    // 遍历
    int res = 0;
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        if (1 == grid[i][j]) {
          res = std::max(res, dfs(grid, row, col, i, j));
        }
      }
    }

    return res;
  }

private:
  std::vector<std::vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

  bool isInArea(int row, int col, int x, int y) {
    return x >= 0 && x < row && y >= 0 && y < col;
  }

  int dfs(std::vector<std::vector<int>>& grid, int row, int col, int x, int y) {
    grid[x][y] = 0;
    int res    = 1;
    for (auto item : dir) {
      int dx = x + item[0];
      int dy = y + item[1];
      if (isInArea(row, col, dx, dy) && 1 == grid[dx][dy]) {
        res += dfs(grid, row, col, dx, dy);
      }
    }

    return res;
  }
};
// @lc code=end
