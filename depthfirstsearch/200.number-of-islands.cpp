/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 *
 * https://leetcode.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (52.28%)
 * Likes:    11339
 * Dislikes: 288
 * Total Accepted:    1.3M
 * Total Submissions: 2.5M
 * Testcase Example:
 * '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * Given an m x n 2D binary grid grid which represents a map of '1's (land) and
 * '0's (water), return the number of islands.
 *
 * An island is surrounded by water and is formed by connecting adjacent lands
 * horizontally or vertically. You may assume all four edges of the grid are
 * all surrounded by water.
 *
 *
 * Example 1:
 *
 *
 * Input: grid = [
 * ⁠ ["1","1","1","1","0"],
 * ⁠ ["1","1","0","1","0"],
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["0","0","0","0","0"]
 * ]
 * Output: 1
 *
 *
 * Example 2:
 *
 *
 * Input: grid = [
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["0","0","1","0","0"],
 * ⁠ ["0","0","0","1","1"]
 * ]
 * Output: 3
 *
 *
 *
 * Constraints:
 *
 *
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 300
 * grid[i][j] is '0' or '1'.
 *
 *
 */

#include <vector>

// @lc code=start
class Solution {
public:
  int numIslands(std::vector<std::vector<char>>& grid) {
    int row = grid.size(), col = grid[0].size();
    int res = 0;

    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        if ('1' == grid[i][j]) {
          dfs(grid, i, j, row, col);
          res++;
        }
      }
    }

    return res;
  }

private:
  void dfs(std::vector<std::vector<char>>& grid,
           int                             i,
           int                             j,
           int                             row,
           int                             col) {
    grid[i][j] = '0';
    for (auto it : dir) {
      int dx = i + it[0];
      int dy = j + it[1];
      if (isInArea(row, col, dx, dy) && '1' == grid[dx][dy]) {
        dfs(grid, dx, dy, row, col);
      }
    }
  }

  bool isInArea(int row, int col, int x, int y) {
    return x >= 0 && x < row && y >= 0 && y < col;
  }

  const std::vector<std::vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
};
// @lc code=end
