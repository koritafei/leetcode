/*
 * @lc app=leetcode id=1254 lang=cpp
 *
 * [1254] Number of Closed Islands
 *
 * https://leetcode.com/problems/number-of-closed-islands/description/
 *
 * algorithms
 * Medium (62.67%)
 * Likes:    1295
 * Dislikes: 33
 * Total Accepted:    65.1K
 * Total Submissions: 103.9K
 * Testcase Example:
 * '[[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]'
 *
 * Given a 2D grid consists of 0s (land) and 1s (water).  An island is a
 * maximal 4-directionally connected group of 0s and a closed island is an
 * island totally (all left, top, right, bottom) surrounded by 1s.
 *
 * Return the number of closed islands.
 *
 *
 * Example 1:
 *
 *
 *
 *
 * Input: grid =
 * [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
 * Output: 2
 * Explanation:
 * Islands in gray are closed because they are completely surrounded by water
 * (group of 1s).
 *
 * Example 2:
 *
 *
 *
 *
 * Input: grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
 * Output: 1
 *
 *
 * Example 3:
 *
 *
 * Input: grid = [[1,1,1,1,1,1,1],
 * [1,0,0,0,0,0,1],
 * [1,0,1,1,1,0,1],
 * [1,0,1,0,1,0,1],
 * [1,0,1,1,1,0,1],
 * [1,0,0,0,0,0,1],
 * ⁠              [1,1,1,1,1,1,1]]
 * Output: 2
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= grid.length, grid[0].length <= 100
 * 0 <= grid[i][j] <=1
 *
 *
 */

#include <vector>

// @lc code=start
class Solution {
public:
  int closedIsland(std::vector<std::vector<int>>& grid) {
    int row = grid.size(), col = 0;
    if (0 == row) {
      return 0;
    } else {
      col = grid[0].size();
    }

    // 首先将边界处的岛屿全部替换为海水
    for (int i = 0; i < row; i++) {
      if (0 == grid[i][0]) {
        dfs(grid, row, col, i, 0);
      }

      if (0 == grid[i][col - 1]) {
        dfs(grid, row, col, i, col - 1);
      }
    }

    for (int i = 0; i < col; i++) {
      if (0 == grid[0][i]) {
        dfs(grid, row, col, 0, i);
      }

      if (0 == grid[row - 1][i]) {
        dfs(grid, row, col, row - 1, i);
      }
    }

    int res = 0;  // 查找剩余的岛屿数
    for (int i = 1; i < row - 1; i++) {
      for (int j = 1; j < col - 1; j++) {
        if (0 == grid[i][j]) {
          res++;
          dfs(grid, row, col, i, j);
        }
      }
    }
    return res;
  }

private:
  std::vector<std::vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  bool                          isInArea(int row, int col, int x, int y) {
    return x >= 0 && x < row && y >= 0 && y < col;
  }

  void dfs(std::vector<std::vector<int>>& grid,
           int                            row,
           int                            col,
           int                            x,
           int                            y) {
    grid[x][y] = 1;
    for (auto item : dir) {
      int dx = item[0] + x;
      int dy = item[1] + y;
      if (isInArea(row, col, dx, dy) && grid[dx][dy] == 0) {
        dfs(grid, row, col, dx, dy);
      }
    }
  }
};
// @lc code=end
