/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 *
 * https://leetcode.com/problems/surrounded-regions/description/
 *
 * algorithms
 * Medium (32.90%)
 * Likes:    4213
 * Dislikes: 1039
 * Total Accepted:    375.1K
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
    int row = board.size(), col = board[0].size();

    // 处理边界
    for (int i = 0; i < row; i++) {
      if (board[i][0] == 'O') {
        dfs(board, row, col, i, 0, 'Y');
      }

      if (board[i][col - 1] == 'O') {
        dfs(board, row, col, i, col - 1, 'Y');
      }
    }

    for (int i = 0; i < col; i++) {
      if (board[0][i] == 'O') {
        dfs(board, row, col, 0, i, 'Y');
      }

      if (board[row - 1][i] == 'O') {
        dfs(board, row, col, row - 1, i, 'Y');
      }
    }

    for (int i = 1; i < row; i++) {
      for (int j = 1; j < col; j++) {
        if ('O' == board[i][j]) {
          dfs(board, row, col, i, j, 'X');
        }
      }
    }

    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        if ('Y' == board[i][j]) {
          board[i][j] = 'O';
        }
      }
    }
  }

private:
  void dfs(std::vector<std::vector<char>>& board,
           int                             row,
           int                             col,
           int                             x,
           int                             y,
           char                            ch) {
    board[x][y] = ch;

    for (auto& it : direct) {
      int dx = it[0] + x;
      int dy = it[1] + y;
      if (isInArea(row, col, dx, dy) && board[dx][dy] == 'O') {
        dfs(board, row, col, dx, dy, ch);
      }
    }
  }

  bool isInArea(int row, int col, int x, int y) {
    return x >= 0 && x < row && y >= 0 && y < col;
  }

  const std::vector<std::vector<int>> direct = {{0, 1},
                                                {0, -1},
                                                {1, 0},
                                                {-1, 0}};
};
// @lc code=end
