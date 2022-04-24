/*
 * @lc app=leetcode id=1020 lang=cpp
 *
 * [1020] Number of Enclaves
 *
 * https://leetcode.com/problems/number-of-enclaves/description/
 *
 * algorithms
 * Medium (60.76%)
 * Likes:    806
 * Dislikes: 29
 * Total Accepted:    36.7K
 * Total Submissions: 60.3K
 * Testcase Example:  '[[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]'
 *
 * You are given an m x n binary matrix grid, where 0 represents a sea cell and
 * 1 represents a land cell.
 *
 * A move consists of walking from one land cell to another adjacent
 * (4-directionally) land cell or walking off the boundary of the grid.
 *
 * Return the number of land cells in grid for which we cannot walk off the
 * boundary of the grid in any number of moves.
 *
 *
 * Example 1:
 *
 *
 * Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
 * Output: 3
 * Explanation: There are three 1s that are enclosed by 0s, and one 1 that is
 * not enclosed because its on the boundary.
 *
 *
 * Example 2:
 *
 *
 * Input: grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
 * Output: 0
 * Explanation: All 1s are either on the boundary or can reach the
 * boundary.
 *
 *
 *
 * Constraints:
 *
 *
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 500
 * grid[i][j] is either 0 or 1.
 *
 *
 */

#include <vector>

// @lc code=start
class Solution {
public:
  int numEnclaves(std::vector<std::vector<int>>& grid) {
    int row = grid.size(), col = 0;
    if (row == 0) {
      return 0;
    } else {
      col = grid[0].size();
    }

    // 处理边界
    for (int i = 0; i < row; i++) {
      if (1 == grid[i][0]) {
        dfs(grid, row, col, i, 0);
      }

      if (1 == grid[i][col - 1]) {
        dfs(grid, row, col, i, col - 1);
      }
    }

    for (int i = 0; i < col; i++) {
      if (1 == grid[0][i]) {
        dfs(grid, row, col, 0, i);
      }

      if (1 == grid[row - 1][i]) {
        dfs(grid, row, col, row - 1, i);
      }
    }

    int res = 0;
    for (int i = 1; i < row - 1; i++) {
      for (int j = 1; j < col - 1; j++) {
        if (1 == grid[i][j]) {
          res++;
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

  void dfs(std::vector<std::vector<int>>& grid,
           int                            row,
           int                            col,
           int                            x,
           int                            y) {
    grid[x][y] = 0;
    for (auto item : dir) {
      int dx = x + item[0];
      int dy = y + item[1];
      if (isInArea(row, col, dx, dy) && 1 == grid[dx][dy]) {
        dfs(grid, row, col, dx, dy);
      }
    }
  }
};
// @lc code=end
