/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 *
 * https://leetcode.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (49.25%)
 * Likes:    7895
 * Dislikes: 240
 * Total Accepted:    988K
 * Total Submissions: 2M
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

// @lc code=start
class Solution {
public:
  int numIslands(vector<vector<char>>& grid) {
    int row = grid.size();
    if (row == 0) {
      return 0;
    }
    int col = grid[0].size();
    if (col == 0) {
      return 0;
    }
    int res = 0;

    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        if (grid[i][j] == '1') {
          dfs(grid, i, j, row, col);
          res++;
        }
      }
    }
    return res;
  }

private:
  void dfs(vector<vector<char>>& grid, int x, int y, int row, int col) {
    grid[x][y] = '0';

    for (int i = 0; i < 4; i++) {
      int newx = x + step[i][0];
      int newy = y + step[i][1];
      if (isInEdge(newx, newy, row, col) && grid[newx][newy] == '1') {
        dfs(grid, newx, newy, row,col);
      }
    }
    return;
  }

  bool isInEdge(int x, int y, int row, int col) {
    return x >= 0 && x < row && y >= 0 && y < col;
  }

  int step[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
};
// @lc code=end
