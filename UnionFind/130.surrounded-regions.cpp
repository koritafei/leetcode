/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 *
 * https://leetcode.com/problems/surrounded-regions/description/
 *
 * algorithms
 * Medium (32.61%)
 * Likes:    4075
 * Dislikes: 993
 * Total Accepted:    365.7K
 * Total Submissions: 1.1M
 * Testcase Example:
 * '[["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]'
 *
 * Given an m x n matrix board containing 'X' and 'O', capture all regions that
 * are 4-directionally surrounded by 'X'.
 *
 * A region is captured by flipping all 'O's into 'X's in that surrounded
 * region.
 *
 *
 * Example 1:
 *
 *
 * Input: board =
 * [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
 * Output:
 * [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
 * Explanation: Surrounded regions should not be on the border, which means
 * that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that
 * is not on the border and it is not connected to an 'O' on the border will be
 * flipped to 'X'. Two cells are connected if they are adjacent cells connected
 * horizontally or vertically.
 *
 *
 * Example 2:
 *
 *
 * Input: board = [["X"]]
 * Output: [["X"]]
 *
 *
 *
 * Constraints:
 *
 *
 * m == board.length
 * n == board[i].length
 * 1 <= m, n <= 200
 * board[i][j] is 'X' or 'O'.
 *
 *
 */

#include <vector>

// @lc code=start

class Solution {
public:
  void solve(std::vector<std::vector<char>>& board) {
    int m = board.size(), n = 0;
    if (m > 0) {
      n = board[0].size();
    }
    // 替换首尾行
    for (int i = 0; i < n; i++) {
      if ('O' == board[0][i]) {
        fill(board, m, n, 0, i);
      }

      if ('O' == board[m - 1][i]) {
        fill(board, m, n, m - 1, i);
      }
    }

    // 替换首尾列
    for (int i = 0; i < m; i++) {
      if ('O' == board[i][0]) {
        fill(board, m, n, i, 0);
      }

      if ('O' == board[i][n - 1]) {
        fill(board, m, n, i, n - 1);
      }
    }

    // 余下的'O'变为'X'
    for (int i = 1; i < m - 1; i++) {
      for (int j = 1; j < n - 1; j++) {
        if ('O' == board[i][j]) {
          board[i][j] = 'X';
        }
      }
    }

    // 余下的'#'变为'O'
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if ('#' == board[i][j]) {
          board[i][j] = 'O';
        }
      }
    }
  }

private:
  void fill(std::vector<std::vector<char>>& board,
            int                             row,
            int                             col,
            int                             x,
            int                             y) {
    board[x][y] = '#';
    for (int i = 0; i < 4; i++) {
      int dx = x + dir[i][0];
      int dy = y + dir[i][1];
      if (isInArea(row, col, dx, dy) && 'O' == board[dx][dy]) {
        fill(board, row, col, dx, dy);
      }
    }
  }

  bool isInArea(int row, int col, int x, int y) {
    return (x < row) && (x >= 0) && (y < col) && (y >= 0);
  }

  std::vector<std::vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
};
// @lc code=end
