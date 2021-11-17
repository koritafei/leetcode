/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 *
 * https://leetcode.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (51.99%)
 * Likes:    11013
 * Dislikes: 274
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
    int row = grid.size(), col = 0;
    if (row != 0) {
      col = grid[0].size();
    } else {
      return 0;
    }

    int res = 0;
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        if (grid[i][j] == '1') {
          res++;
          dfs(grid, row, col, i, j);
        }
      }
    }
    return res;
  }

private:
  bool isInArea(int row, int col, int i, int j) {
    return i < 0 || i >= row || j < 0 || j >= col;
  }

  void dfs(std::vector<std::vector<char>>& grid,
           int                             row,
           int                             col,
           int                             i,
           int                             j) {
    grid[i][j] = '0';
    for (auto item : dir) {
      int dx = i + item[0];
      int dy = j + item[1];
      if (!isInArea(row, col, dx, dy) && grid[dx][dy] == '1') {
        dfs(grid, row, col, dx, dy);
      }
    }
  }

  std::vector<std::vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
};
// @lc code=end
