/*
 * @lc app=leetcode id=1905 lang=cpp
 *
 * [1905] Count Sub Islands
 *
 * https://leetcode.com/problems/count-sub-islands/description/
 *
 * algorithms
 * Medium (61.68%)
 * Likes:    508
 * Dislikes: 20
 * Total Accepted:    16.2K
 * Total Submissions: 26.1K
 * Testcase Example:
 '[[1,1,1,0,0],[0,1,1,1,1],[0,0,0,0,0],[1,0,0,0,0],[1,1,0,1,1]]\n' +
  '[[1,1,1,0,0],[0,0,1,1,1],[0,1,0,0,0],[1,0,1,1,0],[0,1,0,1,0]]'
 *
 * You are given two m x n binary matrices grid1 and grid2 containing only 0's
 * (representing water) and 1's (representing land). An island is a group of
 * 1's connected 4-directionally (horizontal or vertical). Any cells outside of
 * the grid are considered water cells.
 *
 * An island in grid2 is considered a sub-island if there is an island in grid1
 * that contains all the cells that make up this island in grid2.
 *
 * Return the number of islands in grid2 that are considered sub-islands.
 *
 *
 * Example 1:
 *
 *
 * Input: grid1 =
 * [[1,1,1,0,0],[0,1,1,1,1],[0,0,0,0,0],[1,0,0,0,0],[1,1,0,1,1]], grid2 =
 * [[1,1,1,0,0],[0,0,1,1,1],[0,1,0,0,0],[1,0,1,1,0],[0,1,0,1,0]]
 * Output: 3
 * Explanation: In the picture above, the grid on the left is grid1 and the
 * grid on the right is grid2.
 * The 1s colored red in grid2 are those considered to be part of a sub-island.
 * There are three sub-islands.
 *
 *
 * Example 2:
 *
 *
 * Input: grid1 =
 * [[1,0,1,0,1],[1,1,1,1,1],[0,0,0,0,0],[1,1,1,1,1],[1,0,1,0,1]], grid2 =
 * [[0,0,0,0,0],[1,1,1,1,1],[0,1,0,1,0],[0,1,0,1,0],[1,0,0,0,1]]
 * Output: 2
 * Explanation: In the picture above, the grid on the left is grid1 and the
 * grid on the right is grid2.
 * The 1s colored red in grid2 are those considered to be part of a sub-island.
 * There are two sub-islands.
 *
 *
 *
 * Constraints:
 *
 *
 * m == grid1.length == grid2.length
 * n == grid1[i].length == grid2[i].length
 * 1 <= m, n <= 500
 * grid1[i][j] and grid2[i][j] are either 0 or 1.
 *
 *
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
  int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
    int row = grid1.size(), col = 0;
    if (0 == row) {
      return 0;
    } else {
      col = grid1[0].size();
    }

    // 将在grid1中非岛屿，grid2中岛屿部分淹掉
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        if (0 == grid1[i][j] && 1 == grid2[i][j]) {
          dfs(grid2, row, col, i, j);
        }
      }
    }

    // 统计grid2中剩余岛屿
    int res = 0;
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        if (1 == grid2[i][j]) {
          res++;
          dfs(grid2, row, col, i, j);
        }
      }
    }

    return res;
  }

private:
  vector<vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

  bool isInArea(int row, int col, int i, int j) {
    return i >= 0 && i < row && j >= 0 && j < col;
  }

  void dfs(vector<vector<int>>& grid, int row, int col, int x, int y) {
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
