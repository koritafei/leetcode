/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 *
 * https://leetcode.com/problems/sudoku-solver/description/
 *
 * algorithms
 * Hard (51.83%)
 * Likes:    4133
 * Dislikes: 130
 * Total Accepted:    305.5K
 * Total Submissions: 588.2K
 * Testcase Example:
 * '[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]'
 *
 * Write a program to solve a Sudoku puzzle by filling the empty cells.
 *
 * A sudoku solution must satisfy all of the following rules:
 *
 *
 * Each of the digits 1-9 must occur exactly once in each row.
 * Each of the digits 1-9 must occur exactly once in each column.
 * Each of the digits 1-9 must occur exactly once in each of the 9 3x3
 * sub-boxes of the grid.
 *
 *
 * The '.' character indicates empty cells.
 *
 *
 * Example 1:
 *
 *
 * Input: board =
 * [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
 * Output:
 * [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
 * Explanation: The input board is shown above and the only valid solution is
 * shown below:
 *
 *
 *
 *
 *
 * Constraints:
 *
 *
 * board.length == 9
 * board[i].length == 9
 * board[i][j] is a digit or '.'.
 * It is guaranteed that the input board has only one solution.
 *
 *
 */

#include <vector>

// @lc code=start
class Solution {
public:
  void solveSudoku(std::vector<std::vector<char>>& board) {
    int row = board.size(), col = board[0].size();
    backtrace(board, row, col, 0, 0);
  }

private:
  bool backtrace(std::vector<std::vector<char>>& board,
                 int                             row,
                 int                             col,
                 int                             x,
                 int                             y) {
    if (y == col) {  // 当前行处理完成，处理下一行
      return backtrace(board, row, col, x + 1, 0);
    }

    if (row == x) {  // 行处理完成
      return true;
    }

    if ('.' != board[x][y]) {
      // 当前位置有数字
      return backtrace(board, row, col, x, y + 1);
    }

    for (char ch = '1'; ch <= '9'; ch++) {
      if (isValid(board, row, col, x, y, ch)) {
        // 做选择
        board[x][y] = ch;
        if (backtrace(board, row, col, x, y + 1)) {
          return true;
        }
        // 撤销选择
        board[x][y] = '.';
      }
    }

    return false;
  }

  bool isValid(std::vector<std::vector<char>>& board,
               int                             row,
               int                             col,
               int                             x,
               int                             y,
               char                            ch) {
    for (int i = 0; i < row; i++) {
      // 同一行没有相同数字
      if (board[x][i] == ch) {
        return false;
      }

      // 同一列没有相同数字
      if (board[i][y] == ch) {
        return false;
      }

      // 3 * 3 矩阵没有相同数字
      if (ch == board[(x / 3) * 3 + i / 3][(y / 3) * 3 + i % 3]) {
        return false;
      }
    }

    return true;
  }
};
// @lc code=end
