/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 *
 * https://leetcode.com/problems/surrounded-regions/description/
 *
 * algorithms
 * Medium (32.76%)
 * Likes:    4170
 * Dislikes: 1025
 * Total Accepted:    372K
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
    int row = board.size();
    int col = board[0].size();

    for (int i = 0; i < row; i++) {
      if ('O' == board[i][0]) {
        dfs(board, row, col, i, 0, 'E', 'O');
      }

      if ('O' == board[i][col - 1]) {
        dfs(board, row, col, i, col - 1, 'E', 'O');
      }
    }

    for (int i = 0; i < col; i++) {
      if ('O' == board[0][i]) {
        dfs(board, row, col, 0, i, 'E', 'O');
      }

      if ('O' == board[row - 1][i]) {
        dfs(board, row, col, row - 1, i, 'E', 'O');
      }
    }

    for (int i = 1; i < row; i++) {
      for (int j = 1; j < col; j++) {
        if ('O' == board[i][j]) {
          dfs(board, row, col, i, j, 'X', 'O');
        }
      }
    }

    for (int i = 0; i < row; i++) {
      if ('E' == board[i][0]) {
        dfs(board, row, col, i, 0, 'O', 'E');
      }

      if ('E' == board[i][col - 1]) {
        dfs(board, row, col, i, col - 1, 'O', 'E');
      }
    }

    for (int i = 0; i < col; i++) {
      if ('E' == board[0][i]) {
        dfs(board, row, col, 0, i, 'O', 'E');
      }

      if ('E' == board[row - 1][i]) {
        dfs(board, row, col, row - 1, i, 'O', 'E');
      }
    }
  }

private:
  void dfs(std::vector<std::vector<char>>& board,
           int                             row,
           int                             col,
           int                             x,
           int                             y,
           char                            set,
           char                            old) {
    board[x][y] = set;
    for (auto iter : dir) {
      int dx = x + iter[0];
      int dy = y + iter[1];
      if (isInArea(row, col, dx, dy) && old == board[dx][dy]) {
        dfs(board, row, col, dx, dy, set, old);
      }
    }
  }

  bool isInArea(int row, int col, int x, int y) {
    return x >= 0 && y >= 0 && x < row && y < col;
  }

  const std::vector<std::vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
};
// @lc code=end
